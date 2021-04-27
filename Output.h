#ifndef UNTITLED7_OUTPUT_H
#define UNTITLED7_OUTPUT_H
#include <vector>
#include "Destinations.h"
class Output {
    //This class writes outputs to given file
public:
    static void writeFile(const vector<Destinations*>& destination,const string& output);
};


#endif //UNTITLED7_OUTPUT_H
