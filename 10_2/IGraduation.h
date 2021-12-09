//
// Created by Adek on 2021. 12. 09..
//

#ifndef INC_10_2_IGRADUATION_H
#define INC_10_2_IGRADUATION_H

#include "GraduationExam.h"

class IGraduation{
public:
    virtual int getNumEnrolled() const = 0;
    virtual int getNumPassed() const = 0;
    virtual int getNumFailed() const = 0 ;
    virtual Student& getStudent(int id)  const = 0;
    virtual string getFirstname(int id) const = 0;
    virtual string getLastName(int id) const = 0;
    virtual double getAverage(int) const = 0 ;
    virtual map<string, double> getResult(int) const = 0;
    virtual void printResults(ostream &) const = 0;
    virtual void printPassed(ostream &) const = 0;
    virtual void printFailed(ostream &) const = 0;
};

#endif //INC_10_2_IGRADUATION_H
