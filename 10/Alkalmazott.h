//
// Created by Adek on 2021. 11. 25..
//

#include "Szemely.h"

#ifndef INC_10_ALKALMAZOTT_H
#define INC_10_ALKALMAZOTT_H

#endif //INC_10_ALKALMAZOTT_H

class Alkalmazott : public Szemely{
    public:
        Alkalmazott(const string &v1, const string &k1, const int &ev1, const string &munkakor);
        virtual void print(ostream &os1) const;
        int getId() const;

protected:
        int id;
        string munkakor;
private:
    static int counter;
};