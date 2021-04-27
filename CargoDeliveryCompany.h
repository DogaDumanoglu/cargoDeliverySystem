#ifndef UNTITLED7_CARGODELIVERYCOMPANY_H
#define UNTITLED7_CARGODELIVERYCOMPANY_H
#include "Destinations.h"
#include <vector>
#include "DoublyLinkedList.h"

class CargoDeliveryCompany {
private:
    vector<Destinations*> destinations;
public:
    const vector<Destinations*> &getDestinations() const;//getter
    void setDestinations(const vector<Destinations*> &destinations);//setter
    void setDestinationInfos(const vector<string> &infos);
    static void distributionOfPackages(const vector<string> &missions,vector<Destinations*> &destination);
    //all private functions help distributionOfPackages function
private:
    //This function takes the truck from the garage and prepares the vehicle
    static CargoTruck prepareTheVehicle(Destinations* startDestination,DoublyLinkedList<Packages> &distributionVehicle);
    //returns index position of given destination
    static Destinations* findDestinationPosition(const string& name,vector<Destinations*> &destination);
    //uploadPackageFromStartToVehicle:Receives packages to be taken to other stations in the given station
    static void uploadPackageFromDestinationToVehicle(Destinations* &givenDestination,DoublyLinkedList<Packages>&distributionVehicle,int numberOfPackages);
    //uploadPackageFromVehicleToMid:Leaves packages in the middle station
    static void uploadPackageFromVehicleToMid(Destinations* &midDestination,DoublyLinkedList<Packages>&distributionVehicle,vector<int>&midPackages);
    //reIndexPackages:rearrange changing indexes due to deletion
    static vector<int> reIndexPackages(vector<string> &strMidPackages);
    //uploadPackageFromVehicleToFinal:leaves packages in last position
    static void uploadPackageFromVehicleToFinal(Destinations* &finalDestination,DoublyLinkedList<Packages>&distributionVehicle,CargoTruck &truck);
};

#endif //UNTITLED7_CARGODELIVERYCOMPANY_H
