//
// Created by Adek on 2021. 12. 09..
//

#include "GraduationInfo.h"

GraduationInfo::GraduationInfo(GraduationExam &graduationExam) : graduationExam(graduationExam) {
}

int GraduationInfo::getNumEnrolled () const {
    return graduationExam.students.size();
}

int GraduationInfo::getNumPassed() const {
    return graduationExam.numPassed();
}

int GraduationInfo::getNumFailed() const {
    return graduationExam.numStudents() - graduationExam.numPassed();
}

Student& GraduationInfo::getStudent(int id) const{
    return graduationExam.students.at(id);
}

string GraduationInfo::getFirstname(int id) const{
    return getStudent(id).getFirstName();
}

string GraduationInfo::getLastName(int id) const{
    return getStudent(id).getLastName();
}

double GraduationInfo::getAverage(int id) const {
    return getStudent(id).getAverage();
}

map<string, double> GraduationInfo::getResult(int id) const{
    return getStudent(id).getGrades();
}

void GraduationInfo::printResults(ostream &os) const {
    for_each(graduationExam.students.begin(), graduationExam.students.end(), [](const pair<int, Student> &p){
            cout << p.second;
    });
}

void GraduationInfo::printPassed(ostream &os) const {
    for_each(graduationExam.students.begin(), graduationExam.students.end(), [](const pair<int, Student> &p){
        if(p.second.getAverage() > 6){
            cout << p.second;
        }
    });
}

void GraduationInfo::printFailed(ostream &os) const {
    for_each(graduationExam.students.begin(), graduationExam.students.end(), [](const pair<int, Student> &p){
        if(p.second.getAverage() < 6){
            cout << p.second;
        }
    });
}
