#include <iostream>
#include <string>
#include <limits>

#include "Summer23.h"

using namespace std;

//shows and adds the example data from the instructions
void demonstration(Summer23 summerClass[], COP3014 normClass[], int* summerNum, int* normNum);

//welcome message
void welcome();

//mainMenu Display and selection
void MainMenu(int *selection);

//views all the students in a COP3014 Class
void viewClass(COP3014 classes[], int NumStudents);

//Overload to view all students in a Summer23 Class
void viewClass(Summer23 classes[], int NumStudents);

//Adds a student to a class
void addStudent(int* StudentsN, int* StudentsS, COP3014 nClass[], Summer23 sClass[]);

//Viewing Menu
void viewerMenu();

//Adding Menu
void addingMenu();

//Class Maker Menus
void classMaker();

//student finder menu
void finder();

int main() {
//I've put a limit at 75 students per class
    //the two classes have their own arrays
    COP3014 normalClass[75];
    Summer23 summerClass[75];
    //Are used to know how many students are actually in the arrays
    int summerStudents = 0, normalStudents = 0;
    //handles selection process in the main menu
    int Selection;
    welcome();
    //main menu kicks in
    do {
        //the slection form user input is used in the switch case to path to the correct chosen action
        MainMenu(&Selection);
        switch (Selection) {
            case 1: //view students or class averages
                viewClass(normalClass, normalStudents);
                break;
            case 2: //add new student(s)
                viewClass(summerClass, summerStudents);
                break;
            case 3: //create new class section
                addStudent(&normalStudents, &summerStudents, normalClass, summerClass);
                break;
            case 4: //student find
                demonstration(summerClass, normalClass, &summerStudents, &normalStudents);
                break;
            default:
                //the user has chosen to leave the program by enter a 0 or less
                //Goodbye message
                cout << "--Thank you for grading with us!--";
        }
    } while (Selection > 0);
    return 0;
}

//shows and adds the example data from the instructions
void demonstration(Summer23 summerClass[], COP3014 normClass[], int* summerNum, int* normNum) {
    //initialization of all data from the instructions using overloaded constructors
    double frankQuiz[] = {20, 20, 10}, ginaQuiz[] ={20, 20, 20};
    COP3014 frankBase(frankQuiz , 0, 90, 100, 'A', "Frank", "Fabulous", "Z12345678");
    COP3014 ginaBase(ginaQuiz, 98, 95, 100, 'A', "Gina", "Genius", "Z98765432");
    Summer23 frankDerived(frankQuiz , 0, 90, 100, 'A', "Frank", "Fabulous", "Z12345678", 2);
    Summer23 ginaDerived(ginaQuiz, 98, 95, 100, 'A', "Gina", "Genius", "Z98765432", 3);
    //displaying the data in COP3014 form
    cout << "\n---Example data provided by professor---\n";
    cout << "\n----------COP3014{the base class}----------\n";
    frankBase.computeTotalGrade();
    frankBase.determineLetterGrade();
    frankBase.displayData();
    cout << "\n";
    ginaBase.computeTotalGrade();
    ginaBase.determineLetterGrade();
    ginaBase.displayData();
    cout << "\n";
    //displaying the data in Summer23 form
    cout << "\n----------Summer23{the derived class}----------\n";
    frankDerived.computeTotalGrade();
    frankDerived.determineLetterGrade();
    frankDerived.displayData();
    cout << "\n";
    ginaDerived.computeTotalGrade();
    ginaDerived.determineLetterGrade();
    ginaDerived.displayData();
    cout << "\n";
    //adding the data to the classes if space permits
    if (*normNum < 73) {
        normClass[*normNum] = frankBase;
        *normNum += 1;
        normClass[*normNum] = ginaBase;
        *normNum += 1;
    }
    if (*summerNum < 73) {
        summerClass[*summerNum] = frankDerived;
        *summerNum += 1;
        summerClass[*summerNum] = ginaDerived;
        *summerNum += 1;
    }
}

//welcome message
void welcome() {
 cout << "\n---Welcome Professor!---\n";
 cout <<"\n lets get grading! \n";
}

//mainMenu Display and selection
void MainMenu(int* selection) {
    //display choices
    cout << "\n-----Main Manu-----\n";
    cout << "\n what can we help you with today?";
    cout << "\n1: view students/class averages";
    cout << "\n2: add new student";
    cout << "\n3: create new class section";
    cout << "\n4: Student Find";
    cout << "\n5: Add Demonstration Data";
    cout << "\n0 or less: exit program\n";
    //ensure choices are valid
    do {
        cin >> *selection;
        //ensure input is a number
        while (cin.fail()) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> *selection;
        }
        //error message
        if (*selection > 6) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (*selection > 6);
}

//views all the students in a COP3014 Class
void viewClass(COP3014 classes[], int NumStudents) {
    cout <<"\n----COP3014 Regular Class----\n";
    //iterates over array and uses display data function to show the data for each student
    for (int i = 0; i < NumStudents; i++) {
        classes[i].displayData();
        cout << "\n";
    }
}

//Overload to view all students in a Summer23 Class
void viewClass(Summer23 classes[], int NumStudents) {
    cout <<"\n----COP3014 Summer Class----\n";
    //iterates over array and uses display data function to show the data for each student
    for (int i = 0; i < NumStudents; i++) {
        classes[i].displayData();
        cout << "\n";
    }
}

//Adds a student to a class
void addStudent(int *StudentsN, int *StudentsS, COP3014 nClass[], Summer23 sClass[]) {
    int select;
    //select which class
    cout << "what section will be adding to?";
    cout << "\n1: COP3014 \t2: Summer23\n";
    //ensures valid option
    do  {
        cin >> select;
        //ensures the selection is a number
        while (cin.fail()) {
            cout << "\nInvalid Input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if ((select != 1) && (select != 2)) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while ((select != 1) && (select != 2));
    //adds student to specified class if there is enough room
    //uses setAllInput for the data inputting process
    if ((select == 1) && (*StudentsN < 75)) {
        COP3014 newStudent;
        newStudent.setAllInput();
        nClass[*StudentsN] = newStudent;
        *StudentsN += 1;
    }
    else if ((select == 2) && (*StudentsS < 75)) {
        Summer23 newSummerStudent;
        newSummerStudent.setAllInput();
        sClass[*StudentsS] = newSummerStudent;
        *StudentsS += 1;
    } else {
        //message for when to many students are in one class
        cout << "Max number of students in selected class has already been reached";
    }
}