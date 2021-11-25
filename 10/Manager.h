//
// Created by Adek on 2021. 11. 25..
//

#ifndef INC_10_MANAGER_H
#define INC_10_MANAGER_H

#include "Alkalmazott.h"
#include <vector>

class Manager: public Alkalmazott{
    public:
        Manager(const string &v2, const string &k2, const int &ev2, const string &munkakor2);
        void addAlkalmazott(Alkalmazott* alk);
        void deleteAlkalmazott(int alkalmazottId);
        int beosztottakSzama() const;
        virtual void print(ostream &os2) override const;

    private:
        vector<Alkalmazott*> alkalmazottak;
        static const string MANAGER_MUNKAKOR;
};

#endif //INC_10_MANAGER_H
