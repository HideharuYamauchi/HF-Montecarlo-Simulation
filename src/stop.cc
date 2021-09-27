///////////////////////////////////////////        
//  High field simulation(MuSEUM project)             
//                                               
//  Author: Hideharu Yamauchi 2021/09/19                          
///////////////////////////////////////////                         
#ifndef ___class_muonstopping_
#define ___class_muonstopping_ 1

#include <stdio.h>
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "TString.h"
#include "TMath.h"
#include "TEntryList.h"
#include "../include/stop.hh"
#include "../include/HFgeometry.hh"
#include "TCanvas.h"
#include "TStyle.h"
#include "TObject.h"
#include <cstring>
#endif

muonstopping::muonstopping(std::string runfile, const char* envfile):tree(nullptr),branchtime(nullptr),branchX(nullptr),branchY(nullptr),branchZ(nullptr),branchPx(nullptr),branchPy(nullptr),branchPz(nullptr),branchkE(nullptr),branchdepE(nullptr),branchtrack(nullptr),branchstep(nullptr),branchcopyno(nullptr){
  TString runfile2 = runfile;
  run_num = runfile.substr(runfile.find("run"), 7); // get the present run number
  
  tree = new TTree("tree",run_num);
  tree->ReadFile(runfile2.Data(),"time/D:particle/C:volume:process:X/D:Y:Z:Px:Py:Pz:kE:depE:track/I:step:copyno");
  tree->SetBranchAddress("time",&time, &branchtime);
  tree->SetBranchAddress("particle",particle, &branchparticle);
  tree->SetBranchAddress("volume",volume, &branchvolume);
  tree->SetBranchAddress("process",process, &branchprocess);
  tree->SetBranchAddress("X",&X, branchX);
  tree->SetBranchAddress("Y",&Y, branchY);
  tree->SetBranchAddress("Z",&Z, branchZ);
  tree->SetBranchAddress("Px",&Px, branchPx);
  tree->SetBranchAddress("Py",&Py, branchPy);
  tree->SetBranchAddress("Pz",&Pz, branchPz);
  tree->SetBranchAddress("kE",&kE, branchkE);
  tree->SetBranchAddress("depE",&depE, branchdepE);
  tree->SetBranchAddress("track",&ntrack, branchtrack);
  tree->SetBranchAddress("step",&nstep, branchstep);
  tree->SetBranchAddress("copyno",&copyno, branchcopyno);    
  entries = tree->GetEntries();
  nbranches = tree->GetListOfBranches()->GetEntriesFast();
}

void muonstopping::CreateRootFile(void){
  file = TFile::Open(run_num+=".root","RECREATE");
  if(tree->Write()) std::cout << run_num << " is made." << std::endl;             
  file->Close();
  delete file;
}

void muonstopping::Vis_particle_trackxy(Int_t track, Int_t step){
  TCanvas* c3 = new TCanvas("c3","c3",1200,900);
  TGraph* dt = new TGraph();
  for(Int_t n=0;n<entries;n++){
    tree->GetEntry(n);
    if((std::string(particle)=="mu+")&&(std::string(process)=="DecayWithSpin")){
      dt->SetPoint(n,Z,Y);
      //std::cout << "track:" << ntrack << "\t" << "step:" << nstep << std::endl;
      //std::cout <<"loop:"<< n <<"\t" << "Z:" << Z << "\t" << "X:" << X << "\t" << particle << "\t" <<"step_num:" << nstep << std::endl;
    }
  }
  dt->Draw();
  c3->SaveAs("tracking num=x.png");
  delete dt;                                                                                                                                                                                           
  delete c3;                                                                                                                                                                
}

void muonstopping::Vis_particle_track(Int_t track, Int_t step){
  char title_dt[65];
  sprintf(title_dt,"Tracking number%d; Z axis [/m]; Y axis [/m]; X axis [/m]", track);
  char title_dt2[35];
  sprintf(title_dt2,"tracking number%d.png", track);
  TCanvas* c3 = new TCanvas("c3","c3",1200,900);
  TGraph2D* dt = new TGraph2D();
  dt->SetTitle(title_dt);
  for(Int_t n=0;n<entries;n++){tree->GetEntry(n); if((ntrack==track)&&(0<time<5*1.0e-6)) dt->SetPoint(n,Z*1.0e-3,Y*1.0e-3,X*1.0e-3);}
  gStyle->SetPalette(1);
  dt->Draw(); // "PO"                                             
  dt->GetXaxis()->SetTitleOffset(2.0);
  dt->GetYaxis()->SetTitleOffset(2.0);
  dt->GetZaxis()->SetTitleOffset(1.5);
  c3->SaveAs(title_dt2);
  delete dt;
  delete c3;
}

void muonstopping::Vis_stopping_distXY(double Z){
  TString title_dt = "XY-Distribution";/*
  c = new TCanvas("c", "c",900,900);
  gStyle->SetOptStat(0);
  TPad* center_pad = new TPad("center_pad", "center_pad",0.0,0.0,0.5,0.5);
  center_pad->Draw();
  right_pad = new TPad("right_pad", "right_pad",0.5,0.0,1.0,0.5);
  right_pad->Draw();
  top_pad = new TPad("top_pad", "top_pad",0.0,0.5,0.5,1.0);
  top_pad->Draw();
  
  dtxy = new TH2D("dtxy", title_dt, 201, -100, 100, 201, -100, 100);
  center_pad->cd();
  dtxy->SetXTitle("X [/mm]");
  dtxy->SetYTitle("Y [/mm]");                         
  center_pad->SetLeftMargin(0.15);
  center_pad->SetRightMargin(-0.03)
  
  TH1D* projh2X = dtxy->ProjectionX();
  projh2X->SetXTitle("X [/mm]");
  TH1D* projh2Y = dtxy->ProjectionY();
  projh2Y->SetYTitle("");
  projh2Y->SetXTitle("Y [/mm]");

  center_pad->cd();
  gStyle->SetPalette(1);
  dtxy->Draw("Colz");
  dtxy->GetZaxis()->SetTitleOffset(1.3);
  //dtxy->SetStats(1);

  top_pad->cd();
  projh2X->SetFillColor(kBlue+1);
  top_pad->SetLeftMargin(0.15);
  top_pad->SetRightMargin(-0.03);
  projh2X->Draw("bar");

  right_pad->cd();
  projh2Y->SetFillColor(kBlue-2);
  projh2Y->Draw("hbar");

  c->SaveAs(title_dt+=".png");
  delete dtxy;
  delete c;*/
}

void muonstopping::Vis_stopping_distZ(){
  TString title_dt = "Z-Distribution";
  c2 = new TCanvas("c2", "c2",900,600);
  gStyle->SetOptStat(0);
  //dtz = new TH2D("dtz", "", 40, -200, 200, 24, -120, 120);
  dtz = new TH2D("dtz", "", 2900, -1800, 1100, 240, -120, 120);
  dtz->SetXTitle("Position on the beam axis [/mm]");
  dtz->SetYTitle("Position on the vertical axis [/mm]");
  for(Int_t n=0;n<entries;n++){
    tree->GetEntry(n);
    if((std::string(particle)=="mu+")&&(std::string(process)=="DecayWithSpin")) dtz->Fill(Z,Y);
  }
  dtz->Draw("Colz");
  dtz->GetXaxis()->SetTitleOffset(1.3);
  dtz->GetYaxis()->SetTitleOffset(1.2);    
  c2->SaveAs(title_dt+=".png");
  delete dtz;
  delete c2;
}
