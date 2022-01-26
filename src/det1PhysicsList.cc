
#include "det1PhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1PhysicsList::det1PhysicsList() 
: G4VModularPhysicsList(){
  SetVerboseLevel(1);

  // Default physics
  RegisterPhysics(new G4DecayPhysics());

  // EM physics
  RegisterPhysics(new G4EmStandardPhysics());

  // Radioactive decay
  RegisterPhysics(new G4RadioactiveDecayPhysics());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1PhysicsList::~det1PhysicsList()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void det1PhysicsList::SetCuts()
{
  G4VUserPhysicsList::SetCuts();
}  
