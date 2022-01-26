#include "det1DetectorConstruction.hh"

#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4SDManager.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PSDoseDeposit.hh"
#include "G4VisAttributes.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1DetectorConstruction::det1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)                  // this added scoring volume (not sure why here)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

det1DetectorConstruction::~det1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* det1DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
    
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool fCheckOverlaps = false;
    
    
  //     
  // World
  //
    
  G4double world_sizeXY = 50*cm, world_sizeZ = 50*cm;
  G4Material* world_mat = nist -> FindOrBuildMaterial("G4_AIR"); 
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size  (we multiply my half because this will be the distance from 0)
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      fCheckOverlaps);        //overlaps checking
    
    ///
    /// cylinder of Germanium
    ///
    
    
    // cylinder shape
    G4double detector_Rmin = 0, Rmax = 5*cm;
    G4double detector_Z = 10*cm;    //sets detector thickness
    
    G4double distance_from_detector = 5*cm;
    G4double pos_z_val = distance_from_detector + 0.5*detector_Z;
    
    G4Material* detector_mat = nist -> FindOrBuildMaterial("G4_Ge");   // this defines the detector material as Ge
    
    //G4Material* detector_mat = nist -> FindOrBuildMaterial("G4_SODIUM_IODIDE");   // this defines the detector material as NaI
    
    G4ThreeVector detector_pos1 = G4ThreeVector(0,0, pos_z_val) ; // this defines a vector for the detectors position
                               
    
    G4Tubs* solid_detector = 
        new G4Tubs("detector",detector_Rmin, Rmax, 0.5*detector_Z, 0., twopi);
    
    G4LogicalVolume* logic_detector = 
        new G4LogicalVolume(solid_detector, //solid 
                            detector_mat,   //material
                            "detector_LV");  //name
    
    
    
    
    // layer 1 of shielding
    G4double shield_thickness_1 = 2*mm ;
    G4double layer_1_min = Rmax ;
    G4double layer_1_max = Rmax+shield_thickness_1 ;
    G4double layer_1_Z = 0.5*detector_Z + 2*shield_thickness_1;
    
    G4Material* shield_1_mat = nist -> FindOrBuildMaterial("G4_Al"); // defines shield layer 1 as Aluminium
    
    G4Tubs* solid_shield_1 = 
        new G4Tubs("shield_1", layer_1_min , layer_1_max , layer_1_Z , 0., twopi);
    
    G4LogicalVolume* logic_shield_1 = 
        new G4LogicalVolume(solid_shield_1, //solid 
                            shield_1_mat,   //material
                            "shield_1_LV");  //name 
    
    
    
     // layer 2 of shielding
    G4double shield_thickness_2 = 2*mm ;
    G4double layer_2_min = layer_1_max ;
    G4double layer_2_max = layer_1_max+shield_thickness_2 ;
    G4double layer_2_Z = layer_1_Z + 2*shield_thickness_2;
    
    G4Material* shield_2_mat = nist -> FindOrBuildMaterial("G4_Cu"); 
    
    G4Tubs* solid_shield_2 = 
        new G4Tubs("shield_2", layer_2_min , layer_2_max , layer_2_Z , 0., twopi);
    
    G4LogicalVolume* logic_shield_2 = 
        new G4LogicalVolume(solid_shield_2, //solid 
                            shield_2_mat,   //material
                            "shield_2_LV");  //name      
    
    
    // layer 3 of shielding
    G4double shield_thickness_3 = 2*mm ;
    G4double layer_3_min = layer_2_max ;
    G4double layer_3_max = layer_2_max+shield_thickness_3 ;
    G4double layer_3_Z = layer_2_Z + 2*shield_thickness_3;
    
    G4Material* shield_3_mat = nist -> FindOrBuildMaterial("G4_Pb"); 
    
    G4Tubs* solid_shield_3 = 
        new G4Tubs("shield_3", layer_3_min , layer_3_max , layer_3_Z , 0., twopi);
    
    G4LogicalVolume* logic_shield_3 = 
        new G4LogicalVolume(solid_shield_3, //solid 
                            shield_3_mat,   //material
                            "shield_3_LV");  //name 
    
   
    
  ///
  // place detector in world
  //                    
  new G4PVPlacement(0,                       //no rotation
                    detector_pos1,         //at postition
                    logic_detector,            //its logical volume
                    "detector",               //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    fCheckOverlaps);         // checking overlaps 
    
    
 // commenting out these next 3 G4 PVPlacements will get rid of shielding when "make" ing you will get unused warning but this is fine just a warning :)
    
    
    
 
 new G4PVPlacement(0,
                      detector_pos1,
                      logic_shield_1,
                      "shield_1",
                      logicWorld,
                      false,
                      0,
                      fCheckOverlaps);
    
 new G4PVPlacement(0,
                      detector_pos1,
                      logic_shield_2,
                      "shield_2",
                      logicWorld,
                      false,
                      0,
                      fCheckOverlaps);
    
 new G4PVPlacement(0,
                      detector_pos1,
                      logic_shield_3,
                      "shield_3",
                      logicWorld,
                      false,
                      0,
                      fCheckOverlaps);
    
          
    
    
    
    
  // set the detector as the scoring volume
    fScoringVolume = logic_detector;
    
    
    
  //always return the physical World
  //
  return physWorld;
    
}