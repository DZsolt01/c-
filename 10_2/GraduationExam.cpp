//
// Created by Adek on 2021. 12. 08..
//

#include "GraduationExam.h"

void GraduationExam::enrollment(string &filename) {
    ifstream MyReadFile(filename);
    if (!MyReadFile) {
        throw runtime_error("ERROR1!");
    }
    string line;
    while (getline(MyReadFile, line)) {
        if (line.empty()) {
            continue;
        }
        istringstream ss(line);
        int id;
        string firstName;
        string lastName;

        ss >> id;
        ss >> firstName;
        ss >> lastName;
        students.insert(make_pair(id, Student(id, firstName, lastName)));
    }
    MyReadFile.close();
}

int GraduationExam::numStudents() const {
    return students.size();
}

void GraduationExam::readGradesOfSubject(string &filename, string &subject){
    ifstream MyReadFile(filename);
    if(!MyReadFile){
        throw runtime_error("ERROR2!");
    }
    string line;
    while (getline (MyReadFile, line)) {
        if(line.empty()){
            continue;
        }
        istringstream ss(line);
        int id;
        double grade;

        ss >> id; ss >> grade;
        students.find(id)->second.addGrade(subject, grade);
    }
    MyReadFile.close();
}

void GraduationExam::computeFinalGrades() const {
    for_each(students.begin(), students.end(), [](const pair<int, Student> &p){
        double avg = 0;
        for_each(p.second.getGrades().begin(), p.second.getGrades().end(), [&avg](const pair<string, double> &p2){
            avg += p2.second;
        });
        cout << p.first << ":" << avg << endl;
    });
}

map<string, double> GraduationExam::getGrades(int) const {
    return map<string, double>();
}

int GraduationExam::numPassed() const {
    int succes = 0;
    for_each(students.begin(), students.end(), [&succes](const pair<int, Student> &p){
        double avg = 0;
        for_each(p.second.getGrades().begin(), p.second.getGrades().end(), [&avg](const pair<string, double> &p2){
            avg += p2.second;
        });
        if(avg > 5){
            succes++;
        }
    });
    return succes;
}


