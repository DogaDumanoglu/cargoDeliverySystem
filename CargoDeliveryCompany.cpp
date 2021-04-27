#include "CargoDeliveryCompany.h"
#include "Destinations.h"
#include "ReadFiles.h"
#include "CargoTruck.h"
#include "DoublyLinkedList.cpp"
#include <algorithm>
const vector<Destinations*> &CargoDeliveryCompany::getDestinations() const {
    return destinations;
}

void CargoDeliveryCompany::setDestinations(const vector<Destinations*> &destination) {
    CargoDeliveryCompany::destinations = destination;
}


void CargoDeliveryCompany::setDestinationInfos(const vector<string> &infos) {
    //sets the destinations in the read file
    for(const auto & info : infos){
        auto* destinations1=new Destinations();
        destinations1->setName(info);
        destinations.push_back(destinations1);
    }
    setDestinations(destinations);
}
CargoTruck CargoDeliveryCompany::prepareTheVehicle(Destinations *startDestination,DoublyLinkedList<Packages> &distributionVehicle) {
    Queue<CargoTruck> garage=startDestination->getGarage();//garage of first destination
    CargoTruck truck=garage.getFront();//we pick the first truck in the garage
    garage.dequeue();//deleted from garage of first destination
    startDestination->setGarage(garage);//updates the latest version of the garage
    distributionVehicle.insertAtEnd(truck);//vehicle name added(truck T?)
    return truck;
}

void CargoDeliveryCompany::uploadPackageFromDestinationToVehicle(Destinations* &givenDestination,DoublyLinkedList<Packages> &distributionVehicle,int numberOfPackages) {
    for(int j=0;j<numberOfPackages;j++){
        Stack<Packages> storage=givenDestination->getStorage();
        distributionVehicle.insertAtEnd(storage.getTop());//adds packages to the vehicle
        storage.pop();//Deletes from the storage
        givenDestination->setStorage(storage);//updates the latest version of the storage
    }
}

void CargoDeliveryCompany::uploadPackageFromVehicleToMid(Destinations* &midDestination,DoublyLinkedList<Packages> &distributionVehicle,vector<int> &midPackages) {
    //when in midway station ,takes the package at a specific point, deletes it and adds it to the mid storage
    for(int midPackage : midPackages){
        Stack<Packages> storage=midDestination->getStorage();
        Packages delivery=distributionVehicle.removeSpecificNode(midPackage);//deletes from vehicle
        storage.push(delivery);//adds to storage
        midDestination->setStorage(storage);//updates the latest version of the storage
    }
}

vector<int> CargoDeliveryCompany::reIndexPackages(vector<string> &strMidPackages) {
    vector<int> midPackages;
    if(!strMidPackages[0].empty()){
        for(auto & strMidPackage : strMidPackages){
            midPackages.push_back(stoi(strMidPackage));//converts elements from string to integer
        }
        for(int j=0;j<midPackages.size();j++){//adjusts indexes according to how much smaller element is deleted from before itself
            for(int k=0;k<j;k++){
                if(midPackages[k]<midPackages[j]){
                    midPackages[j]=midPackages[j]-1;
                }
            }
        }
    }
    return midPackages;
}
void CargoDeliveryCompany::uploadPackageFromVehicleToFinal(Destinations* &finalDestination,DoublyLinkedList<Packages> &distributionVehicle,CargoTruck &truck) {
    //transfers packages that need to be delivered at the last station from the very beginning of the vehicle and sets truck to garage
    distributionVehicle.removeFromBeginning();//truck is no longer on the road
    Queue<CargoTruck> finalGarage=finalDestination->getGarage();//garage of the last destination
    finalGarage.enqueue(truck);//truck enters the garage of the last destination
    finalDestination->setGarage(finalGarage);//updates the latest version of the garage of final destination
    int size=distributionVehicle.size();
    for(int j=0;j<size;j++){
        Stack<Packages> storage=finalDestination->getStorage();
        Packages delivery=distributionVehicle.removeFromBeginning();//removes from beginning
        storage.push(delivery);//adds packages to storage
        finalDestination->setStorage(storage);//updates the latest version of the storage
    }
}

void CargoDeliveryCompany::distributionOfPackages(const vector<string> &missions, vector<Destinations*> &destination) {
    for(const auto & mission : missions){
        vector<string> missionInfos=ReadFiles::splitTab(mission,"-");
        DoublyLinkedList<Packages> distributionVehicle;//vehicle
        Destinations *startDestination=findDestinationPosition(missionInfos[0],destination);//first destination
        CargoTruck truck=prepareTheVehicle(startDestination,distributionVehicle);
        uploadPackageFromDestinationToVehicle(startDestination,distributionVehicle,stoi(missionInfos[3]));
        Destinations* midDestination=findDestinationPosition(missionInfos[1],destination);//midway destination
        uploadPackageFromDestinationToVehicle(midDestination,distributionVehicle, stoi(missionInfos[4]));
        vector<string> strMidPackages=ReadFiles::splitTab(missionInfos[5],",");
        vector<int> midPackages=reIndexPackages(strMidPackages);
        uploadPackageFromVehicleToMid(midDestination,distributionVehicle,midPackages);
        Destinations* finalDestination=findDestinationPosition(missionInfos[2],destination);//final destination
        uploadPackageFromVehicleToFinal(finalDestination,distributionVehicle,truck);//all packages drop off from the beginning to final storage
    }

}

Destinations* CargoDeliveryCompany::findDestinationPosition(const string& name,vector<Destinations*> &destination) {
    //Returns the position inside the destinations vector
    for(auto & i : destination){
        if(i->getName()==name){
            return i;
        }
    }
    return nullptr;
}





