//
// Created by Adek on 2021. 11. 11..
//

#ifndef C_APPSTORE_H
#define C_APPSTORE_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Application.h"
using namespace std;
class AppStore{
    public:
        AppStore(const string &filename);
        void print(ostream &out, const string& term);
        Application bestApp(bool freeOnly, int minVersion);
        void remove(int belowRating);
        void sortByFreeAndRating();
        int size();
        Application &operator[](int index);
        Application operator[](int index) const;
    private:
    vector<Application> applications;
};

#endif //C_APPSTORE_H
