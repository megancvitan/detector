#include "det1ActionInitialization.hh"
#include "det1PrimaryGeneratorAction.hh"
#include "det1RunAction.hh"
#include "det1EventAction.hh"
#include "det1SteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1ActionInitialization::det1ActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1ActionInitialization::~det1ActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void det1ActionInitialization::BuildForMaster() const
{
 det1RunAction* runAction = new det1RunAction;
 SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void det1ActionInitialization::Build() const
{
  SetUserAction(new det1PrimaryGeneratorAction);

  det1RunAction* runAction = new det1RunAction;
  SetUserAction(runAction);
  
  det1EventAction* eventAction = new det1EventAction(runAction);
  SetUserAction(eventAction);
  
  SetUserAction(new det1SteppingAction(eventAction));
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
