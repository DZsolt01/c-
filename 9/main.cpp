//
// Created by Adek on 2021. 11. 18..
//
#include <vector>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

int main(){
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    auto it = find_if(fruits.begin(), fruits.end(), [](const string &value) {
        return value.find("berry") != string::npos;
    });
    cout << "tartalmaz:" << (it != fruits.end() ) << endl;

    vector<int> integers {
        2,4,6,8,10
        //1,3,5,7,9
    };
    cout << all_of(integers.begin(), integers.end(), [](const int &value){
        return value % 2 == 0;
    });
    cout << endl;

    for_each(integers.begin(), integers.end(), [](int &value){
        value *= 2;
    });
    for_each(integers.begin(), integers.end(), [](const int & value){
        cout << value << " ";
    });
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    cout << endl;
    auto it2 = count_if(months.begin(), months.end(), [](const string &value){
        return value.size() == 5;
    });
    cout << it2;
    cout << endl;
    vector<int> integers2 {
            2,4,6,8,10
            //1,3,5,7,9
    };
    vector<int> integers3 {
            2,4,6,8,10
            //1,3,5,7,9
    };
    sort(integers2.begin(), integers2.end(), [](const int &val1, const int &val2){
        return val1 > val2;
    });

    for_each(integers2.begin(), integers2.end(), [](const int & value){
        cout << value << " ";
    });

    cout << endl;
    less l1;
    sort(integers3.begin(), integers3.end(), l1);

    for_each(integers3.begin(), integers3.end(), [](const int & value){
        cout << value << " ";
    });

    cout << endl;

    vector<pair<double, string>> mavgtemp {
            {1, "January"}, {2, "February"}, {3, "March"}, {4, "April"}, {5, "May"}, {6, "June"},
            {7, "July"}, {8, "August"}, {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}
    };

    sort(mavgtemp.begin(), mavgtemp.end(), [](const pair<double, string> &p1, const pair<double, string> &p2){
        return p1.first < p2.first;
    });

    for_each(mavgtemp.begin(), mavgtemp.end(), [](const pair<double, string> &p){
        cout << p.first << " " << p.second <<endl;
    });

    sort(integers3.begin(), integers3.end(), [](const int &val1, const int &val2){
        return abs(val1) < abs(val2);
    });

    for_each(months.begin(), months.begin(), [](string &s){
       s[0] = tolower(s[0]);
    });
}