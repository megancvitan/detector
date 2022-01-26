#ifndef det1EventAction_h
#define det1EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class det1RunAction;

/// Event action class
///

class det1EventAction : public G4UserEventAction
{
  public:
    det1EventAction(det1RunAction* runAction);
    virtual ~det1EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddEdep(G4double edep) { fEdep += edep; }

  private:
    det1RunAction* fRunAction;
    G4double     fEdep;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
