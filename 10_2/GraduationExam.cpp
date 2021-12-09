//
// Created by Adek on 2021. 12. 08..
//

#include "GraduationExam.h"

void GraduationExam::enrollment(const string &filename) {
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

void GraduationExam::readGradesOfSubject(const string &subject, const string &filename){
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

void GraduationExam::computeFinalGrades() {
    for_each(students.begin(), students.end(), [](pair<const int, Student> &p){
        p.second.computeAverage();
    });
}

map<string, double> GraduationExam::getGrades(int id) const {

    return students.at(id).getGrades();
}

int GraduationExam::numPassed() const {
    int succes = 0;
    for_each(students.begin(), students.end(), [&succes](const pair<int, Student> &p){
        if(p.second.getAverage() > 6){
            succes++;
        }
    });
    return succes;
}


