//
// Created by Adek on 2021. 12. 09..
//

#ifndef INC_10_2_IGRADUATION_H
#define INC_10_2_IGRADUATION_H

#include "GraduationExam.h"

class IGraduation{
public:
    virtual int getNumEnRolled() const = 0;
    virtual int getNumPassed() const = 0;
    virtual int getNumFailed() const = 0 ;
    virtual Student getStudent(int id) const;
    virtual string getFirstname(int id) const;
    virtual string getLastName(int id);
    virtual double getAverage(int) const = 0 ;
    virtual map<string, double> getResult(int);
    virtual void printResults(ostream &);
    virtual void printPassed(ostream &);
    virtual void printFailed(ostream &);
}

#endif //INC_10_2_IGRADUATION_H
