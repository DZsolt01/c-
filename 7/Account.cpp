//
// Created by Home on 11/4/2021.
//

#include "Account.h"

int Account::counter = 0;
Account::Account(double balance) {
    this->balance = balance;
    this->id = counter;
    counter++;
}

void Account::deposit(double amount) {
    if(amount < 0){
        throw out_of_range("Amount < 0");
    }
    this->balance += amount;
}

bool Account::withdraw(double amount) {
    if(amount > balance || amount < 0){
        return false;
    }
    this->balance -= amount;
    return true;
}

int Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

void Account::print(ostream &os) const {
    os << id << " " << balance;
}

ostream &operator<<(ostream &os, const Account &account) {
    account.print(os);
    return os;
}
