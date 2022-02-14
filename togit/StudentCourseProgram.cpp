//
// Created by terje on 13.02.2022.
//

#include "StudentCourseProgram.h"
#include <string>
#include <iostream>


using namespace std;

void StudentCourseProgram::addStudent() {
    student temp;
    string name;
    string email;

    cout << "Please enter student name\n";
    getline(cin, name);

    cout << "Please enter student email\n";
    getline(cin, email);

    temp.setStudent(++countStudId, name, email);

    manyStudents.push_back(temp);
}

//case 2
void StudentCourseProgram::editOneStudent(int editId) {
    string name = {0};
    string email = {0};

    for (auto &manyStudent: manyStudents) {
        if (editId == manyStudent.getStudId()) {
            cout << "Please enter student name\n";
            getline(cin, name);

            cout << "Please enter student email\n";
            getline(cin, email);

            manyStudent.editStudent(name, email);
        }
    }
}

//case 3
void StudentCourseProgram::removeStudent(int removeId) {
    for (int i = 0; i <= manyStudents.size(); i++) {
        if (manyStudents[i].getStudId() == removeId) {
            manyStudents.erase(manyStudents.begin() + i);
        }
    }
}

//case 2 and 3
void StudentCourseProgram::studMenu(subMenu back) {
    for (auto &manyStudent: manyStudents) {
        if (manyStudent.getStudId() < 10) {
            cout << "    " << manyStudent.getStudId() << ".               "
                 << manyStudent.getStudName() << endl;
        } else if (manyStudent.getStudId() >= 10 && manyStudent.getStudId() < 100) {
            cout << "   " << manyStudent.getStudId() << ".               "
                 << manyStudent.getStudName() << endl;
        }
    }

    if (back == backToMainMenu) {

        if ((manyStudents.size() < 10))
            cout << endl << "    " << manyStudents.size() + 1 << ".               " << "Back to main menu\n";
        else
            cout << endl << "   " << manyStudents.size() + 1 << ".               " << "Back to main menu\n";
    }
}

//case 2
void StudentCourseProgram::editStudent() {
    if (!manyStudents.empty()) {
        cout << "Choose which student to edit:\n";

        cout << "Student id:          Name:" << endl << endl;
        studMenu(backToMainMenu);

        int studChoice = 0;
        cin >> studChoice;
        getchar();
        for (int i = 0; i <= manyStudents.size(); i++) {
            if (manyStudents[i].getStudId() == studChoice) {
                editOneStudent(studChoice);
            }
        }
    } else
        cout << "You have to add a student first\n";
}

//case 3
void StudentCourseProgram::displayAndRemoveStudent() {
    if (!manyStudents.empty()) {
        cout << "Choose which student to remove:\n";
        cout << "Student id:          Name:" << endl << endl;
        studMenu(backToMainMenu);

        int studChoice = 0;
        cin >> studChoice;
        getchar();

        removeStudent(studChoice);
    } else
        cout << "You have to add a student first\n";
}

//case 4
void StudentCourseProgram::addTest() {

    string testName = {0};
    string courseName = {0};
    string dateAndTime = {0};

    cout << "Please enter course name: " << endl;
    getline(cin, courseName);

    cout << "Please enter test name: " << endl;
    getline(cin, testName);

    cout << "Please enter date of test: " << endl;
    getline(cin, dateAndTime);

    //create an object of tests
    Test tempTest(++countTestId, testName, courseName, dateAndTime);

    manyTests.push_back(tempTest);

}

//case 5 and 6
void StudentCourseProgram::testMenu(subMenu back) {

    for (auto &manyTest: manyTests) {
        if (manyTest.getTestId() < 10) {
            cout << "    " << manyTest.getTestId() << ".            "
                 << manyTest.getTestName() << endl;
        } else if (manyTest.getTestId() >= 10 && manyTest.getTestId() < 100) {
            cout << "   " << manyTest.getTestId() << ".            "
                 << manyTest.getTestName() << endl;
        }
    }

    if (back == backToMainMenu) {
        if ((manyTests.size() + 1) < 10)
            cout << endl << "    " << manyTests.size() + 1 << ".            " << "Back to main menu\n";
        else
            cout << endl << "   " << manyTests.size() + 1 << ".            " << "Back to main menu\n";
    }
}

//case 5
void StudentCourseProgram::editOneTest(int editId) {
    if (!manyTests.empty()) {
        string testName = {0};
        string course = {0};
        string dateAndTime = {0};

        for (auto &manyTest: manyTests) {
            if (editId == manyTest.getTestId()) {
                cout << "Please enter course name\n";
                getline(cin, course);

                cout << "Please enter test name\n";
                getline(cin, testName);

                cout << "Please enter new date and time\n";
                getline(cin, dateAndTime);

                manyTest.editTest(testName, course, dateAndTime);

            }
        }
    }


}

//case 5
void StudentCourseProgram::displayAndEditTest() {

    if (!manyTests.empty()) {
        cout << "Choose which test to edit:\n";

        cout << "Test id:          Name:" << endl << endl;
        testMenu(backToMainMenu);

        int choice = 0;
        cin >> choice;
        getchar();
        for (int i = 0; i <= manyTests.size(); i++) {
            if (manyTests[i].getTestId() == choice) {
                editOneTest(choice);
            }

        }
    } else
        cout << "You have to add a test first\n";
}

//case 6
void StudentCourseProgram::displayAndRemoveTest() {
    if (!manyTests.empty()) {
        cout << "Chose which test to remove\n";
        cout << "Test id:          Name:" << endl << endl;
        testMenu(backToMainMenu);

        int choice = 0;
        cin >> choice;
        getchar();

        for (int i = 0; i < manyTests.size(); i++) {
            if (manyTests[i].getTestId() == choice) {
                manyTests.erase(manyTests.begin() + i);
            }

        }
    } else
        cout << "You have to add a test first\n";
}

//case 7
void StudentCourseProgram::AddTestResult() {
    if (!manyStudents.empty() && !manyTests.empty()) {
        cout << "Please choose which student to add a result\n";
        studMenu(listInfo);
        int studChoice{};
        cin >> studChoice;
        getchar();
        if (studChoice <= manyStudents.size()) {
            cout << "Pleas choose which test the student took\n";
            testMenu(listInfo);
            int testChoice{};
            cin >> testChoice;
            getchar();

            if (testChoice <= manyTests.size()) {
                cout << "Please enter the grade the student got (between 1 and 10):\n";
                int gradeChoice{};
                cin >> gradeChoice;

                allResults.emplace_back(studChoice, testChoice, gradeChoice);
            } else
                cout << "What you entered didnt match\n;";
        } else
            cout << "What you entered didnt match\n;";

    } else
        cout << "You have to add student and/or test before you can add a result\n";

}

//case 8
void StudentCourseProgram::editTestResult() {
    if (!allResults.empty()) {
        cout << "Please choose which student to edit result\n";
        cout << "Student id:          Test id:\n";
        for (auto allRes: allResults) {
            cout << "   " << allRes.getStudentId() << "                "
                 << allRes.getTestId() << endl;
        }

        cout << "   " << allResults.size() + 1 << "                "
             << "Back to main menu\n";

        int studChoice{};
        cin >> studChoice;
        getchar();

        int highestStudId{0};

        for (auto &allResult: allResults) {
            allResult.getStudentId();
            if (allResult.getStudentId() > highestStudId) {
                highestStudId = allResult.getStudentId();
            }
        }

        if (studChoice <= highestStudId) {
            cout << "Please choose which test id\n";

            int testChoice{};
            cin >> testChoice;
            getchar();

            for (auto &allRes: allResults) {
                if (allRes.getStudentId() == studChoice && allRes.getTestId() == testChoice) {
                    cout << "Please enter the grade the student got (between 1 and 10):\n";
                    int gradeChoice{};
                    cin >> gradeChoice;
                    getchar();

                    allRes.setGrade(gradeChoice);
                }
            }
        }
    } else
        cout << "You have to add student and/or test before you can add a result\n";

}

//case 9
void StudentCourseProgram::removeTestResult() {
    if (!allResults.empty()) {
        cout << "Please choose which student to remove result\n";
        cout << "Student id:          Test id:\n";
        for (auto allRes: allResults) {
            cout << "   " << allRes.getStudentId() << "                "
                 << allRes.getTestId() << endl;
        }

        cout << "   " << allResults.size() + 1 << "                "
             << "Back to main menu\n";

        int studChoice{};
        cin >> studChoice;
        getchar();

        if (studChoice <= allResults.size()) {
            cout << "Pleas choose which test id\n";

            int testChoice{};
            cin >> testChoice;
            getchar();

            for (int i = 0; i <= allResults.size(); i++) {
                if (allResults[i].getStudentId() == studChoice && allResults[i].getTestId() == testChoice) {
                    allResults.erase(allResults.begin() + i);
                }
            }
        }
    } else
        cout << "You have to add student and/or test before you can remove a result\n";

}

//case 10
void StudentCourseProgram::displayAllInfo() {
    cout << "Student details:" << endl;
    for (auto &manyStudent: manyStudents) {
        cout << "student id = " << manyStudent.getStudId() << ", "
             << "name = " << manyStudent.getStudName() << ", "
             << "email = " << manyStudent.getStudEmail() << endl;
    }

    cout << endl << "Test details:" << endl;
    for (auto &manyTest: manyTests) {
        cout << "test id = " << manyTest.getTestId() << ", "
             << "course name = " << manyTest.getCourseName() << ", "
             << "test name = " << manyTest.getTestName() << ", "
             << "date = " << manyTest.getDateAndTime() << endl;
    }

    cout << endl << "Test results:" << endl;
    for (auto allRes: allResults) {

        cout << "student id = " << allRes.getStudentId() << ", ";

        for (auto manyTest: manyTests) {
            if (allRes.getTestId() == manyTest.getTestId()) {
                cout << "course name = " << manyTest.getCourseName() << ", "
                     << "test id = " << manyTest.getTestId() << ", "
                     << "test name = " << manyTest.getTestName() << ", ";
            }
        }

        cout << "grade = " << allRes.getGrade() << endl;
    }

}

