//
// Created by terje on 13.02.2022.
//

#ifndef ASSIGNMENT_2_1_TEST_H
#define ASSIGNMENT_2_1_TEST_H

#include <string>
using  namespace std;

class Test {
protected:
    int testId;
    string courseName;
    string testName;
    string dateAndTime;
public:
    Test(int testId, string testName, string courseName, string dateAndTime);


    int getTestId() const;

    string getCourseName();

    string getTestName();

    string getDateAndTime();

    void editTest(string editTestName, string editCourseName, string editDateAndTime);
};


#endif //ASSIGNMENT_2_1_TEST_H
