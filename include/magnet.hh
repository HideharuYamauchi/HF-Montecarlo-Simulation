///////////////////////////////////////////          
//  High field simulation(MuSEUM project)
//
//  Hideharu Yamauchi 2021/09/18                                            
///////////////////////////////////////////  
#if !defined(___header_magfield_)
#define ___header_magfield_ 1

#include <cmath>
#include <vector>
#include "TMath.h"
#include "HFgeometry.hh"
#include "TH2.h"
#include "TCanvas.h"
#include "TGraph2D.h"
#include "TStyle.h"

class magfield{
private:
  const int moment_num = 3602;
  int mode;
  std::vector<std::vector<double>> moment_coordinate;
  std::vector<std::vector<double>> moment;
  std::vector<std::vector<double>> distance;
  std::vector<double> interval;
  std::vector<double> position;
  const double B_ave = 1.199671277270803; // average field
  const double scaling_factor = B_cons/B_ave;
  
public:
  magfield(const char* magnetfile);
  ~magfield(void){;};
  double GetDistance(double x, double y, double z);
  double Bfield_value(void);
  void Vis_magfield(double Z);
  TCanvas* c;
  TPad* center_pad;
  TPad* top_pad;
  TGraph2D* dt;
  TH2D* dt2;
};
#endif