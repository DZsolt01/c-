//
// Created by Home on 11/4/2021.
//

#include "Bank.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Bank::Bank(const string &name) {
    this->name = name;
}

int Bank::newCustomer(const string &firstName, const string &lastName) {
    this->customers.emplace_back(Customer(firstName, lastName));
    return customers[customers.size()-1].getId();
}

bool Bank::deleteCustomer(int id) {
    auto end = customers.end();
    auto it = customers.erase(find_if(customers.begin(), customers.end(), [=](Customer &customer){
        return customer.getId() == id;
    }));

    return end == it;
}

Customer &Bank::getCustomer(int id) {
    for(Customer &customer: this->customers){
        if(customer.getId() == id){
            return customer;
        }
    }
    throw runtime_error("Customer not found!");
}

void Bank::printCustomers(ostream &os) const {
    os << "BANK NAME:" << name << endl;
    for(const Customer &customer:customers){
        os << customer.getId() << " "<< customer.getFirstName() << " " << customer.getLastName() <<endl;
    }
}

void Bank::printCustomersAndAccounts(ostream &os) const {
    os << name << ":" << endl;
    for(const Customer &customer: customers){
        os << customer;
    }
}

vector<int> Bank::loadCustomers(const string &filename) {
    vector<int> ids;
    ifstream MyReadFile(filename);
    string line;
    while (getline (MyReadFile, line)) {
        istringstream ss(line);
        string firstname;
            while(ss >> firstname){
                string lastname;
                ss >> lastname;
                cout << firstname << " " << lastname << endl;
                ids.emplace_back(newCustomer(firstname, lastname));
            }
    }

    MyReadFile.close();
    return ids;
}

