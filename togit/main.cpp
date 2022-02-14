
#include "StudentCourseProgram.h"
#include <iostream>


using namespace std;

StudentCourseProgram ass_2;
//Here is the switch that runs the functions
void runChoicesMM() {
    cin.clear();
    menuChoice mMenuChoice = defaultChoice;

    while (mMenuChoice != exiProgramMenu) {

        mainMenu();

        int choiceMM{};
        cin >> choiceMM;
        mMenuChoice = static_cast<menuChoice>(choiceMM);
        getchar();

        switch (mMenuChoice) {

            case addStudentMenu:
                ass_2.addStudent();

                break;

            case editStudentMenu:
                ass_2.editStudent();
                break;

            case removeStudentMenu:
                ass_2.displayAndRemoveStudent();
                break;

            case addTestMenu:
                ass_2.addTest();
                break;

            case editTestMenu:
                ass_2.displayAndEditTest();
                break;

            case removeTestMenu:
                ass_2.displayAndRemoveTest();
                break;

            case addTestResultMenu:
                ass_2.AddTestResult();
                break;

            case editTestResultMenu:
                ass_2.editTestResult();
                break;

            case removeTestResultMenu:
                ass_2.removeTestResult();
                break;

            case showAllInfoMenu:
                if (!ass_2.manyStudents.empty() || !ass_2.manyTests.empty()) {
                    ass_2.displayAllInfo();

                } else {
                    cout << "There aren't any data in the system at the moment" << endl << endl
                         << "Please choose another choice" << endl;
                }
                break;

            case exiProgramMenu:
                //Exit the program

                break;

            default:
                cin.clear();
                cout << endl << "What you entered didn't match." << endl << endl;

        }
    }
};


int main() {
    //Check out this about vector: https://stackoverflow.com/questions/19657728/create-a-vector-of-instances-of-a-class-in-c

    //This contains functions that shall run in each case including mainMenu

    runChoicesMM();


    return 0;
}

