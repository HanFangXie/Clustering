#ifndef CLUSTERINGBASE_HH
#define CLUSTERINGBASE_HH

#include <iostream>
#include <vector>
#include <algorithm>

#include "Utils/Helper.h"
#include "Utils/Exceptions.hh"

#include "IO/InputManager.hh"
#include "IO/OutputManager.hh"

#include "Algorithm/ClusterEngine.hh"
#include "Algorithm/Trigger.hh"

class ClusteringBase {
protected:
  ClusteringBase(){
  }

  void InitialiseBase() {
    fInputFileName  = "";
    fInputTreeName  = "";
    fOutputFileName = "";
    fClustEng       = NULL;
    fTrigger        = NULL;
    fPrintLevel     = -1;
    fNAPA           = -1;
    fOffset         =  0;
    fOutputOffset   =  0;
    fIM             = NULL;
    fOM             = NULL;
    fmap_APA_Channel[-1] = std::numeric_limits<int>::max();
    fmap_APA_Channel[ 0] =     0;
    fmap_APA_Channel[ 1] =  3000;
    fmap_APA_Channel[ 2] =  6000;
    fmap_APA_Channel[ 3] =  8000;
    fmap_APA_Channel[ 4] = 11000;
    fmap_APA_Channel[ 5] = 14000;
    fmap_APA_Channel[ 6] = 16000;
    fmap_APA_Channel[ 7] = 19000;
    fmap_APA_Channel[ 8] = 21000;
    fmap_APA_Channel[ 9] = 24000;
    fmap_APA_Channel[10] = 26000;
    fmap_APA_Channel[11] = 29000;
    fmap_APA_Channel[12] = 31000;
    fUsePDS = 1;
    fUseTPC = 1;
    SetupCuts();
    
    if (fNConfig == 0)
      throw NoConfig();
    
  };

  virtual void SetupCuts() = 0;

public:
   
  int         GetPrintLevel  () const { return fPrintLevel;     };
  std::string GetInputFile   () const { return fInputFileName;  };
  std::string GetInputTree   () const { return fInputTreeName;  };
  std::string GetOutputFile  () const { return fOutputFileName; };
  bool        GetUsePDS      () const { return fUsePDS; };
  bool        GetUseTPC      () const { return fUseTPC; };

  void SetPrintLevel  (const int p=-1) { fPrintLevel     = p; };
  void SetInputFile   (const std::string s="") { fInputFileName  = s; };
  void SetInputTree   (const std::string s="") { fInputTreeName  = s; };
  void SetOutputFile  (const std::string s="") { fOutputFileName = s; };
  void SetOffset      (const size_t n= 0)      { fOffset         = n; };
  void SetOutputOffset(const size_t n= 0)      { fOutputOffset   = n; };
  void SetNAPA        (const int n=-1)         { fNAPA           = n; };
  void SetUsePDS      (const bool usepds=1)    { fUsePDS = usepds;    };
  void SetUseTPC      (const bool usetpc=1)    { fUseTPC = usetpc;    };
  
  virtual void ClusterAll(int inNEvent) {

    if (inNEvent>0) {
      fNEvent = std::min((size_t)inNEvent+fOffset,(size_t)fIM->GetEntries());
    } else {
      fNEvent = (size_t)fIM->GetEntries();
    }
    RunClustering();
  };
  virtual void RunClustering() = 0;
  
  ~ClusteringBase()
    {
      if(fClustEng) delete fClustEng;  
      fClustEng = NULL;

      if(fTrigger) delete fTrigger;
      fTrigger = NULL;
      
      if(fIM) delete fIM;
      fIM = NULL;

      if(fOM) delete fOM;
      fOM = NULL;

    };
  
protected:
  std::string fInputFileName ;
  std::string fInputTreeName ;
  std::string fOutputFileName;
  std::string fERecoXMLFile  ;

  ClusterEngine* fClustEng;
  Trigger* fTrigger;

  InputManager * fIM;
  OutputManager* fOM;
  
  int fPrintLevel;
  int fNAPA;
  size_t fOffset;
  size_t fOutputOffset;
  size_t fNEvent;
  size_t fCurrentEvent;

  std::map<int, int> fmap_APA_Channel;
  size_t fNConfig;

  bool fUseTPC;
  bool fUsePDS;

};
#endif

 
