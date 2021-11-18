//
// Created by Adek on 2021. 11. 11..
//
#include "AppStore.h"

int main(){
    AppStore store("applications.csv");
    cout << store.bestApp(false, 2012) << endl;
    cout << endl;
    cout << store.bestApp(true, 2012) << endl;
    cout << endl;
    store.print(cout, "free");
    store.remove(4);
    cout << endl;
    store.print(cout, "free");
    store.sortByFreeAndRating();
    cout << endl;
    store.print(cout, "free");
    cout << store.size();
    cout << endl;
    store.print(cout, "Pycharm");

}