//
// Created by Adek on 2021. 11. 25..
//

#include "Ceg.h"

Ceg::Ceg()= default;

void Ceg::addAlkalmazott(Alkalmazott *alk) {
    alkalmazottak.emplace_back(alk);
}

void Ceg::removeAlkalmazott(int id) {
    erase_if(alkalmazottak, [id](const Alkalmazott* alk2){
       return alk2->getId() == id;
    });
}

void Ceg::addAlkalmazottToManager(Manager* man, Alkalmazott* alk) {
    man->addAlkalmazott(alk);
}

void Ceg::removeAlkalmazottFromManager(Manager* man, int id) {
    man->deleteAlkalmazott(id);
}

void Ceg::print(ostream &os) const {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [](const Alkalmazott* alk){
        alk->print(cout);
        cout <<endl;
    });
}

void Ceg::printManagers() const {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [](const Alkalmazott* alk){
        if(dynamic_cast<const Manager*>(alk) != nullptr){
            alk->print(cout);
            cout <<endl;
        }
    });
}


