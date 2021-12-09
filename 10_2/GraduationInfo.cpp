//
// Created by Adek on 2021. 12. 09..
//

#include "GraduationInfo.h"

GraduationInfo::GraduationInfo(GraduationExam &graduationExam) : graduationExam(graduationExam) {
}

int GraduationInfo::getNumEnRolled () const {
    return 0;
}

int GraduationInfo::getNumPassed() const {
    return 0;
}

int GraduationInfo::getNumFailed() const {
    return 0;
}

Student GraduationInfo::getStudent(int id) const{
    return Student(0, __cxx11::basic_string(), __cxx11::basic_string());
}

string GraduationInfo::getFirstname(int id) const{
    return std::string();
}

string GraduationInfo::getLastName(int id) {
    return std::string();
}

double GraduationInfo::getAverage(int) const {
    return 0;
}

map<string, double> GraduationInfo::getResult(int) {
    return map<string, double>();
}

void GraduationInfo::printResults(ostream &) {

}

void GraduationInfo::printPassed(ostream &) {

}

void GraduationInfo::printFailed(ostream &) {

}
