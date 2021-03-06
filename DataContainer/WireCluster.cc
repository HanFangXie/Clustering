#include "WireCluster.hh"
#include "WireHit.hh"


WireCluster::WireCluster(std::vector<Hit*>& vec_Hits):
  Cluster(vec_Hits),
  fMC_UnderlyingE(0),
  fNElectron(0){
  Initialise();
  for (auto const& it: fHit) {
    WireHit* hit = (WireHit*)it;
    fNElectron += hit->GetNElectron();
  }
}
