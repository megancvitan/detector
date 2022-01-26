#ifndef det1ActionInitialization_h
#define det1ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class det1ActionInitialization : public G4VUserActionInitialization
{
  public:
    det1ActionInitialization();
    virtual ~det1ActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
