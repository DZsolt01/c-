//
// Created by Adek on 2021. 12. 08..
//

#include "Student.h"

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

double Student::getAverage() const {
    return average;
}

int Student::getId() const {
    return id;
}

Student::Student(int id, string &firstName, string &lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

void Student::addGrade(const string &name, double grade) {
    grades.insert(make_pair(name, grade));
}

double Student::getGrade(string &name) const {
    return grades.find(name)->second;
}

void Student::computeAverage() {
    double avg = 0;
    for(auto &p: grades){
        avg += p.second;
    }
    avg = avg/grades.size();
    if(avg >= 6){
        this->average = avg;
    }
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "id: " << student.id << " firstName: " << student.firstName << " lastName: " << student.lastName
       << " grades: ";
    for_each(student.grades.begin(), student.grades.end(), [&os](const pair<string, double> &p){
        os << p.first << ":" << p.second << " ";
    });
    os << endl;
    return os;
}
