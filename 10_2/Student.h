//
// Created by Adek on 2021. 12. 08..
//

#ifndef INC_10_2_STUDENT_H
#define INC_10_2_STUDENT_H
#include <iostream>
#include <map>
#include <string>
#include <algorithm>



using namespace std;

class Student{
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average = 0;
public:
    Student(int, string&, string&);

    int getId() const;

    const string &getFirstName() const;

    const string &getLastName() const;

    const map<string, double> &getGrades() const;

    double getAverage() const;

    void addGrade(const string&, double);

    double getGrade(string &) const;

    void computeAverage();

    friend ostream &operator<<(ostream &os, const Student &student);
};
#endif //INC_10_2_STUDENT_H
