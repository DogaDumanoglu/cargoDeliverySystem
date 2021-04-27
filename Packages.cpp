#include "Packages.h"
const string &Packages::getName() const {
    return name;
}

void Packages::setName(const string &packageName) {
    Packages::name = packageName;
}