//
// Created by Adek on 2021. 12. 09..
//

#ifndef INC_10_2_GRADUATIONINFO_H
#define INC_10_2_GRADUATIONINFO_H
#include "IGraduation.h"

class GraduationInfo: public IGraduation{
    GraduationExam& graduationExam;
public:
    GraduationInfo(GraduationExam &graduationExam);
    virtual int getNumEnRolled() const;
    virtual int getNumPassed() const;
    virtual int getNumFailed() const;
    virtual Student getStudent(int id) const;
    virtual string getFirstname(int id) const;
    virtual string getLastName(int id);
    virtual double getAverage(int) const;
    virtual map<string, double> getResult(int);
    virtual void printResults(ostream &);
    virtual void printPassed(ostream &);
    virtual void printFailed(ostream &);
};
#endif //INC_10_2_GRADUATIONINFO_H
