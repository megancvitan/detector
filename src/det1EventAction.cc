#include "det1EventAction.hh"
#include "det1RunAction.hh"
#include "detector1Analysis.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"

#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4THitsMap.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1EventAction::det1EventAction(det1RunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction),
  fEdep(0.)
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1EventAction::~det1EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void det1EventAction::BeginOfEventAction(const G4Event*)
{    
  fEdep = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void det1EventAction::EndOfEventAction(const G4Event*)
{   
  // accumulate statistics in run action
  fRunAction->AddEdep( fEdep );
    
 // Get Analysis Manager
    G4AnalysisManager* analysis = G4AnalysisManager::Instance();
    
    //Fill ntuple
    analysis->FillNtupleDColumn(0, fEdep);
    analysis->AddNtupleRow();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
