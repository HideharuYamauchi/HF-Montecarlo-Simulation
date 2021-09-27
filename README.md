# HF-Montecarlo Simulation
The codes of MonteCarlo which aims to give the simulation of MuSEUM experiment; particle/nuclear physics experiment to measure the Hyperfine Splitting of Muonium at J-PARC. The full codes of simulation is based on ROOT and GEANT4.<br>

GEANT4 is the radiation simulation packages. It is used in the fields of physics, etc. medical, space...
https://geant4.web.cern.ch/node/1<br>
ROOT is the analysis software flamework base on C++ programming language for high energy physis experiment. It has been devloped by cern.
https://root.cern/<br> 
High Field MuSEUM experiment will be held at Materials and Life Science Experimental Facility of J-PARC. J-PARC (Japan Proton Accelerator Research Complex) is a high intensity proton accelerator facility. It is a joint project between KEK and JAEA and is located at the Tokai campus of JAEA.  
https://j-parc.jp/c/index.html
https://g-2.kek.jp/portal/index.html
https://g-2.kek.jp/gakusai/research_MuHFS.html

1. RF.cc and RF.hh.<br>
To calculate the TMmode of microware in the cavity. We respectively use TM110 and TM210 mode to demonstrate the frequency which cause hyperfine splitting in the high magnetic field.

2. magnet.cc and magnet.hh.<br>
To calculate the magnetic field about 1.7 T of superconductive magnet. The magnet will use at MuSEUM experiment and muon(g-2) experiment in the future.

3. stop.cc and stop.hh.<br>
To calculate and analysis the muon stopping distribution in the RFcavity Using Geant4. 

4. simulator.cc and simulator.hh.<br>
To calculate the effective microwave distribution by superposition of RF field and muons distribution.
