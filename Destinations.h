#ifndef UNTITLED7_DESTINATIONS_H
#define UNTITLED7_DESTINATIONS_H
#include "Queue.cpp"
#include "CargoTruck.h"
#include "Packages.h"
#include "Stack.cpp"
#include <vector>
class Destinations {
private:
    string name;
    Queue<CargoTruck> garage;
    Stack<Packages> storage;

public:
    // setStorageInfos: Fills the repository with the information read from the file
    static void setStorageInfos(const vector<string> &infos,vector<Destinations*>& destinations);
    // setGarageInfos: Fills the garages with the information read from the file
    static void setGarageInfos(const vector<string> &infos,vector<Destinations*>& destinations);
    //getters and setters
    const string &getName() const;

    void setName(const string &name);

    const Queue<CargoTruck> &getGarage() const;

    void setGarage(const Queue<CargoTruck> &garage);

    const Stack<Packages> &getStorage() const;

    void setStorage(const Stack<Packages> &storage);


};


#endif //UNTITLED7_DESTINATIONS_H
