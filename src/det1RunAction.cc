
#include "det1RunAction.hh"
#include "det1PrimaryGeneratorAction.hh"
#include "det1DetectorConstruction.hh"
#include "detector1Analysis.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"  
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1RunAction::det1RunAction()
 : G4UserRunAction(), fFileName("test-123.csv"), fEdep(0.)
{

    
  // Register accumulable to the accumulable manager
  G4AccumulableManager* accumulableManager =         G4AccumulableManager::Instance();
  accumulableManager->RegisterAccumulable(fEdep);
     
  G4AnalysisManager* analysis = G4AnalysisManager::Instance();
     
  analysis->SetVerboseLevel(1);
  analysis->SetNtupleDirectoryName("data");
  analysis->SetFileName(fFileName);

  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1RunAction::~det1RunAction()
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void det1RunAction::BeginOfRunAction(const G4Run*)
{

    
    // reset accumulables to their initial values
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Reset();
    
      
  G4AnalysisManager* analysis = G4AnalysisManager::Instance();
  
  
    
    
    //Open an output file
    analysis ->OpenFile();       // change this everytime
    
    
    //Create Histograms?
    analysis -> CreateNtuple("MyNtuple","Energy Deposit");
    analysis -> CreateNtupleDColumn("Eabs");
    analysis -> FinishNtuple();
    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void det1RunAction::EndOfRunAction(const G4Run* )
{
  // Merge accumulables 
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Merge();

  // Compute dose = total energy deposit in a run and its variance
  //
  G4double edep  = fEdep.GetValue();
    
  //save histograms
  //      
  G4AnalysisManager* analysis = G4AnalysisManager::Instance();
  
    analysis->Write();
    analysis->CloseFile();
  
}

void det1RunAction::AddEdep(G4double edep)
{
  fEdep  += edep;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
