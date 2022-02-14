//
// Created by terje on 13.02.2022.
//

#ifndef ASSIGNMENT_2_1_STUDENT_H
#define ASSIGNMENT_2_1_STUDENT_H
#include <string>

using namespace std;


class student {
protected:
    int studId;
    string studName;
    string studEmail;

public:
    void setStudent(int studentId, string name, string mail);

    int getStudId() const;

    string getStudName();

    string getStudEmail();

    void editStudent(string name, string eMail);



};

#endif //ASSIGNMENT_2_1_STUDENT_H
