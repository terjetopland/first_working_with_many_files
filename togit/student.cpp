//
// Created by terje on 13.02.2022.
//

#include "student.h"


void student::setStudent(int studentId, string name, string mail) {
    this->studId = studentId;
    this->studName = move(name);
    this->studEmail = move(mail);
}

int student::getStudId() const {
    return this->studId;
}

string student::getStudName() {
    return this->studName;
}

string student::getStudEmail() {
    return this->studEmail;
}

void student::editStudent(string name, string eMail) {
    this->studName = move(name);
    this->studEmail = move(eMail);
}

