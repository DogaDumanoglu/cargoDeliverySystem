#include "Destinations.h"
#include <vector>
#include "ReadFiles.h"
#include <string>
const string &Destinations::getName() const {
    return name;
}

void Destinations::setName(const string &desName) {
    Destinations::name = desName;
}

const Queue<CargoTruck> &Destinations::getGarage() const {
    return garage;
}

void Destinations::setGarage(const Queue<CargoTruck> &desGarage) {
    Destinations::garage = desGarage;
}

const Stack<Packages> &Destinations::getStorage() const {
    return storage;
}

void Destinations::setStorage(const Stack<Packages> &desStorage){
    Destinations::storage = desStorage;
}

void Destinations::setStorageInfos(const vector<string> &infos,vector<Destinations*>& destinations) {
    for (const auto & info : infos) {
        Packages packages;
        vector<string> storageInfos = ReadFiles::splitTab(info," ");
        packages.setName(storageInfos[0]);//sets package name
        for (auto & destination : destinations) {
            if (storageInfos[1] == destination->getName()) {//set according to its location
                Stack<Packages> storages = destination->getStorage();
                storages.push(packages);
                destination->setStorage(storages);
                break;
            }
        }
    }
}
void Destinations::setGarageInfos(const vector<string> &infos,vector<Destinations*>& destinations) {
    for (const auto & info : infos) {
        CargoTruck truck;
        vector<string> storageInfos = ReadFiles::splitTab(info," ");
        truck.setName(storageInfos[0]);//sets trucks name
        truck.setPower(stod(storageInfos[2]));//sets power of truck
        for (auto & destination : destinations) {
            if (storageInfos[1] == destination->getName()) {//set according to its location
                Queue<CargoTruck> garages = destination->getGarage();
                garages.enqueue(truck);
                destination->setGarage(garages);
                break;
            }
        }
    }
}