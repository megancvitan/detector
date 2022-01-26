
#ifndef det1PhysicsList_h
#define det1PhysicsList_h 1

#include "G4VModularPhysicsList.hh"

/// Modular physics list
///
/// It includes the folowing physics builders
/// - G4DecayPhysics
/// - G4RadioactiveDecayPhysics
/// - G4EmStandardPhysics

class det1PhysicsList: public G4VModularPhysicsList
{
public:
  det1PhysicsList();
  virtual ~det1PhysicsList();

  virtual void SetCuts();
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

