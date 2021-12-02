//
// Created by Adek on 2021. 11. 25..
//

#ifndef INC_10_CEG_H
#define INC_10_CEG_H

#include "Manager.h"

class Ceg{
    vector<Alkalmazott*> alkalmazottak;

    public:
        Ceg();
        void addAlkalmazott(Alkalmazott* alk);
        void removeAlkalmazott(int id);
        void addAlkalmazottToManager(Manager* man, Alkalmazott* alk);
        void removeAlkalmazottFromManager(Manager* man, int id);
        virtual void print(ostream &os) const;
        void printManagers() const;

};

#endif //INC_10_CEG_H
