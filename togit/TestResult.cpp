//
// Created by terje on 13.02.2022.
//

#include "TestResult.h"

    TestResult::TestResult(int studIdentifier, int testIdentifier, int gradeOfStudent) {

        this->studentId = studIdentifier;
        this->testId = testIdentifier;
        this->grade = gradeOfStudent;
    }

    int TestResult::getStudentId() const {
        return this->studentId;
    }

    int TestResult::getTestId() const {
        return this->testId;
    }

    void TestResult::setGrade(int gradeEdit) {
        this->grade = 0;
        this->grade = gradeEdit;
    }

    int TestResult::getGrade() const {
        return this->grade;
    }
