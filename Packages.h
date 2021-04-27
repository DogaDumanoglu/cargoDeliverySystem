#ifndef UNTITLED7_PACKAGES_H
#define UNTITLED7_PACKAGES_H
#include <iostream>
using namespace std;
class Packages {
private:
    string name;
public:
    //getter setters
    const string &getName() const;

    void setName(const string &packageName);
};


#endif //UNTITLED7_PACKAGES_H
