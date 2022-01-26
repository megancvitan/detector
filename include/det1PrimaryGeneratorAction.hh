#ifndef det1PrimaryGeneratorAction_h
#define det1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"
#include "globals.hh"

class G4GeneralParticleSource;
class G4Event;
class G4Box;

/// The primary generator action class with particle gun.
///
/// The default kinematic is a 6 MeV gamma, randomly distribued 
/// in front of the phantom across 80% of the (X,Y) phantom size.

class det1PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    det1PrimaryGeneratorAction();    
    virtual ~det1PrimaryGeneratorAction();
    
        // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
  
    // method to access particle gun
    const G4GeneralParticleSource* GetParticleSource() const { return fParticleGun; }
  
  private:
    G4GeneralParticleSource*  fParticleGun; // pointer a to G4 gun class
    G4Box* fEnvelopeBox;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
