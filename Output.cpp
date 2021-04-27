#include "Output.h"
#include <fstream>
void Output::writeFile(const vector<Destinations*>& destination,const string& output) {
    ofstream myFile;
    myFile.open(output);
    for(auto & des : destination){
        myFile<<des->getName()<<endl;//Writes destination names
        myFile<<"Packages:\n";
        Stack<Packages> packages=des->getStorage();
        int pSize=packages.size();
        for(int j=0;j<pSize;j++){
            myFile<<packages.getTop().getName()<<"\n";//writes the name of the packages in the repository
            packages.pop();
        }
        myFile<<"Trucks:\n";
        Queue<CargoTruck> trucks=des->getGarage();
        int tSize=trucks.size();
        for(int j=0;j<tSize;j++){
            myFile<<trucks.getFront().getName()<<"\n";//writes the name of the trucks in the garages
            trucks.dequeue();
        }
        myFile<<"-------------\n";

    }
    myFile.close();
}


