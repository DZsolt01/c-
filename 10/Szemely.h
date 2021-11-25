//
// Created by Adek on 2021. 11. 25..
//

#ifndef INC_10_SZEMELY_H
#define INC_10_SZEMELY_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Szemely{
    protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;

    public:
        Szemely(const string& v, const string & k, const int &Ev = 0);
        virtual void print(ostream& o) const;


};


#endif //INC_10_SZEMELY_H
