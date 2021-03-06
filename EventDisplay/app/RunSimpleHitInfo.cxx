#include "HitSimplePlot.hh"

#include <unistd.h>

int main(int argc, char** argv){
  int opt;
  // Shut GetOpt error messages down (return '?'): 
  extern char *optarg;
  extern int  optopt;

  int RMS=-1;
  int Width=-1;
  int nEvent=-1;
  std::string InputFile = "";
  std::string InputTree = "";
  while ( (opt = getopt(argc, argv, "r:w:i:t:n:")) != -1 ) {  // for each option...
    switch ( opt ) {
    case 'r':
      RMS = atoi(optarg);
      break;
    case 'w':
      Width = atoi(optarg);
      break;
    case 'i':
      InputFile = optarg;
      break;
    case 't':
      InputTree = optarg;
      break;
    case 'n':
      nEvent = atoi(optarg);
      break;
    case '?':  // unknown option...
      std::cerr << "Unknown option: '" << char(optopt) << "'!" << std::endl;
      break;
    }
  }

  if (RMS>=0 && Width >=0)
    return 1;

  
  HitSimplePlot hsp(InputFile, InputTree);
  hsp.SetNEvent(nEvent);
  if(RMS  >=0) hsp.PlotRMS  (RMS  );
  if(Width>=0) hsp.PlotWidth(Width);

  return 0;

}
