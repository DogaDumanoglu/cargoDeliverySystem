#include "ReadFiles.h"
#include <fstream>
using namespace std;
vector<string> ReadFiles::readFile(const string& fileName) {
    //Reads given documents returns it in a vector
    ifstream myFile;
    string str;
    vector<string> infos;
    myFile.open(fileName);
    while(!myFile.eof()){//until the end of the file
        while(getline(myFile,str)){//reads line by line
            infos.push_back(str);//pushes in a vector
        }
    }
    myFile.close();
    return infos;
}

vector<string> ReadFiles::splitTab(string str,const string& splitter) {
    //This function splits strings from given parameter(splitter) and returns it in a vector
    vector<string> splitVector;
    string word;
    int separator=str.find(splitter);//first separator pos
    while(separator!=-1){
        word=str.substr(0,separator);//Splits the string up to the separator into the substring and assigns it to the word
        splitVector.push_back(word);//pushes the word in the vector
        str=str.substr(separator+1,str.length());//arranges the remaining string discarding the previous part
        separator=str.find(splitter);//position of next separator
    }
    splitVector.push_back(str);//pushes the remaining word
    return splitVector;
}
