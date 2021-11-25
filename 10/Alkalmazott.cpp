//
// Created by Adek on 2021. 11. 25..
//

#include "Alkalmazott.h"
int Alkalmazott::counter{0};
Alkalmazott::Alkalmazott(const string &v1, const string &k1, const int &ev1, const string &munkakor) : Szemely(v1, k1, ev1) {
    this->munkakor = munkakor;
    this->id = counter;
    counter++;
}

void Alkalmazott::print(ostream &os1) const{
    Szemely::print(os1);
    os1 << "Munkakor:" << munkakor;
}

int Alkalmazott::getId() const {
    return id;
}
