#ifndef det1RunAction_h
#define det1RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class det1RunAction : public G4UserRunAction
{
  public:
   det1RunAction();
  virtual ~det1RunAction();

   virtual void BeginOfRunAction(const G4Run*);
   virtual void EndOfRunAction(const G4Run*);
   
   void AddEdep (G4double edep); 

  private:
   G4String fFileName;   
   G4Accumulable<G4double> fEdep;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif




