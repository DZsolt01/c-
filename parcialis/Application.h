//
// Created by Adek on 2021. 11. 11..
//

#ifndef C_APPLICATION_H
#define C_APPLICATION_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Application{
    public:
    Application(const string & name, const string & category, const string & developer, int version, int rating, double price);

    const string &getName() const;

    const string &getCategory() const;

    const string &getDeveloper() const;

    int getVersion() const;

    int getRating() const;

    double getPrice() const;

    friend ostream &operator<<(ostream &os, const Application &application);

private:
        string name;
        string category;
        string developer;
        int version;
        int rating;
        double price;
};

#endif //C_APPLICATION_H
