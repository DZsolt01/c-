//
// Created by Home on 11/4/2021.
//

#include "Customer.h"
#include <algorithm>
int Customer::counter = 0;
Customer::Customer(const string &firstName, const string &lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = counter;
    counter++;
}

const string &Customer::getFirstName() const {
    return firstName;
}

void Customer::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

void Customer::setLastName(const string &lastName) {
    this->lastName = lastName;
}

Account &Customer::getAccount(int id) {
    for(Account &account: this->accounts){
        if(account.getId() == id){
            return account;
        }
    }
    throw runtime_error("Account not found!");
}

int Customer::newAccount(double balance) {
    this->accounts.emplace_back(Account(balance));
    return accounts[accounts.size()-1].getId();
}

bool Customer::deleteAccount(int id) {
    auto end = accounts.end();
    auto it = accounts.erase(find_if(accounts.begin(), accounts.end(), [=](Account &account){
        return account.getId() == id;
    }));

    return end == it;
}

int Customer::getNumAccounts() const {
    return accounts.size();
}

void Customer::print(ostream &os) const {
    os << this->id << " " << this->firstName << " " << this->lastName << ":" << endl;
    for(const Account &account: accounts){
        os << '\t' << account << endl;
    }
}

ostream &operator<<(ostream &os, const Customer &customer) {
    customer.print(os);
    return os;
}

Account &Customer::operator[](int index) {
    if(index < 0 || index > accounts.size()){
        throw out_of_range("Nincs ilyen index!");
    }
    return accounts[index];
}

const Account &Customer::operator[](int index) const {
    if(index < 0 || index > accounts.size()){
        throw out_of_range("Nincs ilyen index!");
    }
    return accounts[index];
}
