//
// Created by Home on 11/4/2021.
//
#include "Account.h"
#include "Customer.h"

int main() {
    /*
    Account b1(0);
    b1.deposit(1000);
    b1.print(cout);
    b1.withdraw(500);
    b1.print(cout);
    b1.withdraw(1000);
    b1.print(cout);
     */

    Customer c("Jack", "Murphy");
    cout <<c.newAccount(100) <<endl;
    cout <<c.newAccount(200) <<endl;
    cout <<c.newAccount(300) <<endl;
    c.deleteAccount(0);
    cout <<endl;
    cout << c;
}