//
// Created by Adek on 2021. 12. 08..
//

#include "GraduationExam.h"

int main(){
    GraduationExam gradutation;
    string filename = "names.txt";
    gradutation.enrollment(filename);
    filename="math.txt";
    string subject = "math";
    gradutation.readGradesOfSubject(filename, subject);
    filename="romanian.txt";
    subject = "romanian";
    gradutation.readGradesOfSubject(filename, subject);
    filename="hungarian.txt";
    subject ="hungarian";
    gradutation.readGradesOfSubject(filename, subject);
}