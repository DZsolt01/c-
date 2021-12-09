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
    virtual int getNumEnrolled() const override;
    virtual int getNumPassed() const override;
    virtual int getNumFailed() const override;
    virtual Student& getStudent(int id) const override;
    virtual string getFirstname(int id) const override;
    virtual string getLastName(int id) const override;
    virtual double getAverage(int) const override;
    virtual map<string, double> getResult(int) const override;
    virtual void printResults(ostream &) const override;
    virtual void printPassed(ostream &) const override;
    virtual void printFailed(ostream &) const override;

};
#endif //INC_10_2_GRADUATIONINFO_H
