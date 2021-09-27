////////////////////////////////////////////////////
// High Field Simulation for MuSUEUM experiment
//
//  Author:     Hideharu Yamauchi 2021/9/23
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "./RF.cc"
#include "./magnet.cc"
#include "./stop.cc"
#include "./simulator.cc"

int main(int argc, const char** argv){
  //--------------------------radio frequency info(TMmode)
  RFfield field_RF(atol(argv[1]));
  
  // if you want to visualize RF field
  //field_RF.Vis_mode();
  //----------------------------------------------------------------------

  
  //-------------------------superconductive magnet info
  // using copy constructor to initialize default constructor
  //magfield magnet_field = magfield();
  //magfield magnet_field(argv[2]);
  
  // if you want to visualize magnet field at Z
  //magnet_field.Vis_magfield(-150.);
  //----------------------------------------------------------------------

  
  //-------------------------muon stop distribution info
  //muonstopping run(argv[3], argv[4]);
  
  // if you want to make the root file
  //run.CreateRootFile();

  // if you want to visualize the track of particle
  //run.Vis_particle_trackxy(1,0);
  //run.Vis_particle_track(1);
  
  // if you want to scan the tree object
  //run.GetScanTree("*","");
  //run.GetScanTree("particle:volume:pointX:pointY:pointZ", "e+==particle"); 
  
  // if you want to get the list of tree at a entry
  //run.GetListOfEntry(0);

  // if you want to visualize muon stopping distribution
  //run.Vis_stopping_distXY(double Z);
  //run.Vis_stopping_distZ();
  //----------------------------------------------------------------------

  
  //-------------------------calculate the effective RF field
  simulator sim(atol(argv[1]), &field_RF);

  // if you want to get state amplitude
  //sim.timedev(double t, double b, double delta, double gamma);
  
  //----------------------------------------------------------------------
  
  return 0;
}
