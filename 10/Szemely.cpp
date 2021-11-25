//
// Created by Adek on 2021. 11. 25..
//

#include "Szemely.h"

Szemely::Szemely(const string &v, const string &k, const int &ev) {
    this->keresztNev = k;
    this->vezetekNev = v;
    this->szuletesiEv = ev;
}

void Szemely::print(ostream &os) const{
    os << "vezetekNev: " << vezetekNev << " keresztNev: " << keresztNev << " szuletesiEv: "
       << szuletesiEv;
}
