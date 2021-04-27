#include "ReadFiles.h"
#include <vector>
#include "CargoDeliveryCompany.h"
#include "Destinations.h"
#include "Output.h"
int main(int argc,char*argv[]) {//compile=g++ -std=c++11 *.cpp -o Main run:./Main dests.txt packages.txt trucks.txt missions.txt result.txt
    CargoDeliveryCompany cargoDeliveryCompany;
    vector<string> destinationInfos=ReadFiles::readFile(argv[1]);//read dests.txt
    cargoDeliveryCompany.setDestinationInfos(destinationInfos);//we set the destinations in cargo delivery company

    vector<string> packagesInfos=ReadFiles::readFile(argv[2]);//read packages.txt
    vector<Destinations*> destinations =cargoDeliveryCompany.getDestinations();//
    Destinations::setStorageInfos(packagesInfos,destinations);//we set storages(packages) in destinations

    vector<string>truckInfos=ReadFiles::readFile(argv[3]);//read trucks.txt
    Destinations::setGarageInfos(truckInfos,destinations);//we set garages(trucks) in destinations


    vector<string> missionsInfos=ReadFiles::readFile(argv[4]);//read missions.txt
    CargoDeliveryCompany::distributionOfPackages(missionsInfos,destinations);//picks up the cargo packages from the relevant stations and leave them where they need to be delivered
    Output::writeFile(destinations,argv[5]);//write result.txt
}
