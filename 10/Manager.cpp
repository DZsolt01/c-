//
// Created by Adek on 2021. 11. 25..
//

#include "Manager.h"
#include <algorithm>

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const string &v2, const string &k2, const int &ev2, const string &munkakor2) : Alkalmazott(v2, k2, ev2, munkakor2){

}

void Manager::addAlkalmazott(Alkalmazott *alk) {
    alkalmazottak.emplace_back(alk);
}

void Manager::deleteAlkalmazott(int alkalmazottId) {
    erase_if(alkalmazottak, [alkalmazottId](const Alkalmazott* alk2){
        return alk2->getId() == alkalmazottId;
    });

}

int Manager::beosztottakSzama() const {
    return alkalmazottak.size();
}

void Manager::print(ostream &os) const {
    Alkalmazott::print(os);
    os << " beosztottjai:" << endl;
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [&os](const Alkalmazott* alk){
        os << "\t";
        alk->print(os);
        os << endl;
    });
}

