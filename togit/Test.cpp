//
// Created by terje on 13.02.2022.
//

#include "Test.h"



    Test::Test(int testId, string testName, string courseName, string dateAndTime) {
        this->testId = testId;
        this->courseName = move(courseName);
        this->testName = move(testName);
        this->dateAndTime = move(dateAndTime);
    }

    int Test::getTestId() const {
        return this->testId;
    }

    string Test::getCourseName() {
        return this->courseName;
    }

    string Test::getTestName() {
        return this->testName;
    }

    string Test::getDateAndTime() {
        return this->dateAndTime;
    }

    void Test::editTest(string editTestName, string editCourseName, string editDateAndTime) {
        this->testName = move(editTestName);
        this->courseName = move(editCourseName);
        this->dateAndTime = move(editDateAndTime);
    }
