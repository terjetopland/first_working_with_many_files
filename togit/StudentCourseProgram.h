//
// Created by terje on 13.02.2022.
//

#ifndef ASSIGNMENT_2_1_STUDENTCOURSEPROGRAM_H
#define ASSIGNMENT_2_1_STUDENTCOURSEPROGRAM_H
#include <vector>
#include "student.h"
#include "Test.h"
#include "TestResult.h"
#include "EnumChoices.h"
#include "functionMMenu.h"



class StudentCourseProgram {
    int countStudId;
    int countTestId;




public:
    StudentCourseProgram();

    void addStudent();

    void editOneStudent(int editId);

//case 3
    void removeStudent(int removeId);

//case 2 and 3
    void studMenu(subMenu back);


//case 2
    void editStudent();

//case 3
    void displayAndRemoveStudent();

    void addTest();

//case 5 and 6
    void testMenu(subMenu back);

//case 5
    void editOneTest(int editId);

//case 5
    void displayAndEditTest();

//case 6
    void displayAndRemoveTest();

    //case 7
    void AddTestResult();


//case 8
    void editTestResult();

//case 9
    void removeTestResult();

//case 10
    void displayAllInfo();

    std::vector<student> manyStudents;
    std::vector<Test> manyTests;
    vector<TestResult> allResults;

};



#endif //ASSIGNMENT_2_1_STUDENTCOURSEPROGRAM_H
