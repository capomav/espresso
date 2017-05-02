#include "cluster_analysis.hpp"
#include "interaction_data.hpp"
#include <algorithm>


void ClusterStructure::clear() {
 clusters.clear();
 cluster_id.clear();
 cluster_identities.clear();
}

inline bool ClusterStructure::part_of_cluster(const Particle& p)
{
 if (cluster_id.find(p.p.identity)==cluster_id.end()) return false;
 return true;
}

// Analyze the cluster structure of the given particles
void ClusterStructure::analyze_pair()
{
  // clear data structs
  clear();
  
  // Iterate over pairs
  for (int i=0;i<=max_seen_particle;i++) {
    if (! local_particles[i]) continue;
    for (int j=i+1;j<=max_seen_particle;j++) {
      if (! local_particles[j]) continue;
      add_pair(*local_particles[i],*local_particles[j]); 
    }
  }
  merge_clusters();
}

void ClusterStructure::analyze_bonds() {
clear();
for (int i=0;i<=max_seen_particle;i++) {
  if (local_particles[i]) {
    auto p=local_particles[i];
    int j=0;
    while (j<p->bl.n) {
      int bond_type=p->bl.e[j];
      int partners =bonded_ia_params[bond_type].num;
      if (partners!=1) {
        j+=1+partners;
        continue;
      }
      // We are only here if bond has one partner
      add_pair(*p,*(local_particles[p->bl.e[j+1]]));
      j+=2; // Type id + one prtner
    }
  }
}
merge_clusters();
}



void ClusterStructure::add_pair(Particle& p1, Particle& p2) {
// * check, if there's a neighbor
 //   * No: Then go on to the next particle
 // * Yes: Then if
 //   * One of them belongs to a cluster, give the other one the same cluster
 //     id.
 //   * None of them belongs to a cluster: Give them both a new cluster id
 //   * Both belong to different clusters: Mark the clusters as identical 
 //   * so that they can be put together later
  if (! nc) {
    runtimeErrorMsg() << "No cluster criterion defined"; 
    return;
  }
  if (nc->are_neighbors(p1,p2)) {
     
     if // None belongs to a cluster
     ((!part_of_cluster(p1)) && (!part_of_cluster(p2)))
    {  
      // Both particles belong to the same, new cluster
      const int cid=get_next_free_cluster_id();

      // assign the cluster_ids 
      cluster_id[p1.p.identity]=cid;
      cluster_id[p2.p.identity]=cid;
    }
    else if // p2 belongs to a cluster but p1 doesn't
      (part_of_cluster(p2) && !part_of_cluster(p1))
    {
     // Give p1 the same cluster id as p2
     cluster_id[p1.p.identity]=find_id_for(cluster_id.at(p2.p.identity));
    }
    else if // i belongs to a cluster but j doesn't
      (part_of_cluster(p1) && !part_of_cluster(p2))
    {
     // give p2 the cluster id from p1
     cluster_id[p2.p.identity]=find_id_for(cluster_id.at(p1.p.identity));
    }
    else if // Both belong to different clusters
      (part_of_cluster(p1) && part_of_cluster(p2) &&
       cluster_id.at(p1.p.identity)!=cluster_id.at(p2.p.identity))
    {
     // Clusters of p1 and p2 are one and the same. Add an identity to the list
     // The higher number must be inserted as first value of tjhe pair
     // because the substituions later have to be done in descending order
     const int cid1=find_id_for(cluster_id.at(p1.p.identity));
     const int cid2=find_id_for(cluster_id.at(p2.p.identity));
     if (cid1>cid2)
     {
       cluster_identities[cid1] =cid2;
     }
     else if (cid1<cid2) 
     {
       cluster_identities[cid2]=cid1;
     }
     // else do nothing. The clusters are already noted for merging.
     // Connected clusters will be merged later
    }
    // The case for both particles being in the same cluster does not need to be
    // treated.
  }
}

void ClusterStructure::merge_clusters() {
  // Relabel particles according to the cluster identities map
  // Also create empty cluster objects for the final cluster id
  
  // Collect needed changes in a separate map, as doing the changes on the fly
  // would screw up the iterators
  std::map<int,int> to_be_changed;
  
  for (auto it : cluster_id) { 
    // particle id is in it.first and cluster id in it.second
    // We change the cluster id according to the cluster identities
    // map
    const int cid=find_id_for(it.second);
    // We note the list of changes here, so we don't modify the map
    // while iterating
    to_be_changed[it.first]=cid;
    // Empty cluster object
    if (clusters.find(cid)==clusters.end()) {
      clusters[cid]=Cluster();
    }
  }
  
  // Now act on the changes marke in above iteration
  for (auto it : to_be_changed) {
   cluster_id[it.first]=it.second;
  }
  
  // Now fill the cluster objects with particle ids
  // Iterate over particles, fill in the cluster map 
  // to each cluster particle the corresponding cluster id 
  for (auto it : cluster_id) {
    clusters[it.second].particles.push_back(it.first);
  }

  // Sort particles ids in the cluters
  for (auto c : clusters) {
    std::sort(c.second.particles.begin(),c.second.particles.end());
  }
}


int ClusterStructure::find_id_for(int x)
{
 int tmp=x;
 while (cluster_identities.find(tmp)!=cluster_identities.end())
 {
  tmp =cluster_identities[tmp];
 }
 return tmp;
}

int ClusterStructure::get_next_free_cluster_id(){
  //iterate over cluster_id'
  int max_seen_cluster = 0;
  for (auto it : cluster_id){
    int cid=it.second;
    if (max_seen_cluster < cid ) {
      max_seen_cluster=cid;
    }
  }
  return max_seen_cluster+1;
}


ClusterStructure cluster_structure;

ClusterStructure& cluster_analysis() {
  return cluster_structure;
}

void ClusterStructure::set_criterion(NeighborCriterion* c) {
  if (nc)
  {
    delete nc;
    nc=0;
  }
  nc=c;
}

   

 

