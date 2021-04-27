#ifndef UNTITLED7_READFILES_H
#define UNTITLED7_READFILES_H
#include <iostream>
#include<vector>
using namespace std;
class ReadFiles {//This class reads Files and arranges inputs
public:
    static vector<string> splitTab(string str,const string& splitter);
    static vector<string> readFile(const string& fileName);
};


#endif //UNTITLED7_READFILES_H
