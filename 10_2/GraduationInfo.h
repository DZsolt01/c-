//
// Created by Adek on 2021. 12. 09..
//

#ifndef INC_10_2_GRADUATIONINFO_H
#define INC_10_2_GRADUATIONINFO_H
#include "GraduationExam.h"

class GraduationInfo{
    GraduationExam& graduationExam;
public:
    GraduationInfo();
    int getNumEnRolled();
    int getNumPassed();
    int getNumFailed();
    Student getStudent(int id);
    string getFirstname(int id);
    string getLastName(int id);
    double getAverage(int);
    map<string, double> getResult(int);
    void printResults(ostream &);
    void printPassed(ostream &);
    void printFailed(ostream &);
};
#endif //INC_10_2_GRADUATIONINFO_H
