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
    return customers[customers.size()].getId();
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
    os << name << ":"<< endl;
    for(const Customer &customer:customers){
        os << customer.getFirstName() << " " << customer.getLastName();
    }
}

void Bank::printCustomersAndAccounts(ostream &os) const {
    os << name << ":" << endl;
    for(const Customer &customer: customers){
        os << customer;
    }
}

vector<int> Bank::loadCustomers(const string &filename) {
    ifstream MyReadFile("customers.txt");
    string line;
    while (getline (MyReadFile, line)) {
        istringstream ss(line);
        // Output the text from the file
        cout << "1";
    }

    MyReadFile.close();
    return vector<int>();
}

