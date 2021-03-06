//
// Created by Adek on 2021. 12. 08..
//

#ifndef INC_10_2_GRADUATIONEXAM_H
#define INC_10_2_GRADUATIONEXAM_H

#include <sstream>
#include <fstream>

#include "Student.h"

class GraduationInfo;
class GraduationExam{
    int year;
    map<int, Student> students;
    friend class GraduationInfo;
public:
    void enrollment(const string&);

    int numStudents() const;

    void readGradesOfSubject(const string&, const string&);

    void computeFinalGrades();

    map<string, double> getGrades(int) const;

    int numPassed() const;
};
#endif //INC_10_2_GRADUATIONEXAM_H
