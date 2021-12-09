#include <iostream>
#include "Student.h"
#include "GraduationExam.h"
#include "GraduationInfo.h"
#include "IGraduation.h"
string subjects[] {"Romanian", "Hungarian", "Math"};
int main() {
    GraduationExam exam;
    exam.enrollment("names.txt");
    cout<<exam.numStudents()<<endl;
    exam.readGradesOfSubject(subjects[0], "romanian.txt");
    exam.readGradesOfSubject(subjects[1], "hungarian.txt");
    exam.readGradesOfSubject(subjects[2], "math.txt");
    exam.computeFinalGrades();
    cout<<exam.numPassed()<<endl;
// Service
    IGraduation * graduation = new GraduationInfo( exam );
    cout<<"Graduation Information"<<endl;
    cout<<"Number of enrolled students: "<<graduation->getNumEnrolled()<<endl;
    cout<<"Number of passed students: "<<graduation->getNumPassed()<<endl;
    cout<<"Number of failed students: "<<graduation->getNumFailed()<<endl;
    int ID;
    for( ;; ){
        cout<<"Enter an ID <0 for termination>: ";
        cin>>ID;
        if( ID == 0 ){
            break;
        }
        cout<<"Information:"<<endl;
        try{
            const Student& student = graduation->getStudent( ID );
            cout<<student<<endl;
        }catch( domain_error& e){
            cout<<e.what()<<endl;
        }
    }
    delete graduation;
    return 0;
}