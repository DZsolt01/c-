//
// Created by Adek on 2021. 12. 02..
//
#include "Manager.h"
#include "Ceg.h"

int main(){
    Ceg company;
    Alkalmazott alk1("Pet�fi", "J�nos", 1991, "Programmer");
    Alkalmazott alk2("Pet�fi", "J�nos", 1984, "IT");
    Alkalmazott alk3("Pet�fi", "J�nos", 1992, "Programmer");
    Alkalmazott alk4("Pet�fi", "J�nos", 1998, "Programmer");
    Alkalmazott alk5("Pet�fi", "J�nos", 1979, "IT");
    Alkalmazott alk6("Pet�fi", "J�nos", 2001, "Programmer");
    Alkalmazott alk7("Pet�fi", "J�nos", 1993, "IT");
    Manager man1("Pet�fi", "J�nos", 1983, "IT");
    Manager man2("Pet�fi", "J�nos", 1973, "Programmer");
    Manager man3("Pet�fi", "J�nos", 1970, "IT");

    company.addAlkalmazott(&alk1);
    company.addAlkalmazott(&alk2);
    company.addAlkalmazott(&alk3);
    company.addAlkalmazott(&alk4);
    company.addAlkalmazott(&alk5);
    company.addAlkalmazott(&alk6);
    company.addAlkalmazott(&alk7);
    company.addAlkalmazott(&man1);
    company.addAlkalmazott(&man2);
    company.addAlkalmazott(&man3);

    company.print(cout);
    company.printManagers();
}