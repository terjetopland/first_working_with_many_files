//
// Created by terje on 13.02.2022.
//

#ifndef ASSIGNMENT_2_1_TESTRESULT_H
#define ASSIGNMENT_2_1_TESTRESULT_H



class TestResult {
protected:
    int studentId;
    int testId;
    int grade;

public:
    TestResult(int studIdentifier, int testIdentifier, int gradeOfStudent);

    int getStudentId() const;

    int getTestId() const;

    void setGrade(int gradeEdit);

    int getGrade() const;

};

#endif //ASSIGNMENT_2_1_TESTRESULT_H
