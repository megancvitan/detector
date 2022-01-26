#ifndef det1SteppingAction_h
#define det1SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class det1EventAction;

class G4LogicalVolume;

/// Stepping action class
/// 

class det1SteppingAction : public G4UserSteppingAction
{
  public:
    det1SteppingAction(det1EventAction* eventAction);
    virtual ~det1SteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    det1EventAction*  fEventAction;
    G4LogicalVolume* fScoringVolume;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
