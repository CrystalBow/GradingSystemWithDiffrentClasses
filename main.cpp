#ifndef COP3014_H
#define COP3014_H
#include <iostream>
#include <string>
#include <limits>
#include <regex>
#include "COP3014.h"
#include "Summer23.h"
#endif




const int MAXCLASSSIZE = 76;
const int MAXNUMBEROFSECTIONS = 7;
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

//calculates the average for a COP3014 class
void averageCalc(COP3014 students[], int NumStudents);


//Overload to calculate the average for a Summer23 class
void averageCalc(Summer23 students[], int NumStudents);

//Adds a student to a class
void addStudent(int* StudentsN, int* StudentsS, COP3014 nClass[], Summer23 sClass[]);

//Viewing Menu
void viewerMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]);

//Adding Menu
void addingMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]);

//Class Maker Menus
void classMaker(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]);

//Student Finder Menu
void finder(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]);

//Student and Class Section Removal
void removalMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]);

void removeClass(COP3014 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses);

void removeClass(Summer23 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses);

void removeStudents(COP3014 students[], int* NumOfStudents);

void removeStudents(Summer23 students[], int* NumOfStudents);

int main() {
//I've put a limit at 75 students per class
    //the two classes have their own arrays
    COP3014 normalClass[MAXNUMBEROFSECTIONS][MAXCLASSSIZE];
    Summer23 summerClass[MAXNUMBEROFSECTIONS][MAXCLASSSIZE];
    //Are used to know how many students are actually in the arrays
    int summerStudents[MAXNUMBEROFSECTIONS], normalStudents[MAXNUMBEROFSECTIONS];
    //Are used to know how many class sections there are already
    int summerSections = 0, normalSections = 0;
    //handles selection process in the main menu
    int Selection;
    welcome();
    //main menu kicks in
    do {
        //the slection form user input is used in the switch case to path to the correct chosen action
        MainMenu(&Selection);
        switch (Selection) {
            case 1: //view students or class averages
                viewerMenu(summerClass, normalClass, &summerSections, &normalSections, summerStudents, normalStudents);
                break;
            case 2: //add new student(s)
                addingMenu(summerClass, normalClass, &summerSections, &normalSections, summerStudents, normalStudents);
                break;
            case 3: //create new class section
                classMaker(summerClass, normalClass, &summerSections, &normalSections, summerStudents, normalStudents);
                break;
            case 4: //student find
                break;
            case 5: //Removal
                break;
            case 6: //Demonstration
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
    cout << "\n5: Remove Student or Section";
    cout << "\n6: Add Demonstration Data";
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
        if (*selection > 7) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (*selection > 7);
}

//views all the students in a COP3014 Class
void viewClass(COP3014 classes[], int NumStudents) {
    cout <<"\n----COP3014 Regular Class----\n";
    //iterates over array and uses display data function to show the data for each student
    for (int i = 0; i < NumStudents; i++) {
        cout << "\n#" << i << "\n";
        classes[i].displayData();
        cout << "\n";
    }
}

//Overload to view all students in a Summer23 Class
void viewClass(Summer23 classes[], int NumStudents) {
    cout <<"\n----COP3014 Summer Class----\n";
    //iterates over array and uses display data function to show the data for each student
    for (int i = 0; i < NumStudents; i++) {
        cout << "\n#" << i << "\n";
        classes[i].displayData();
        cout << "\n";
    }
}

//Adds a student to a class
void addStudent(int *StudentsN, int *StudentsS, COP3014 nClass[], Summer23 sClass[]) {
    int select;
    //select which class
    cout << "what type of section will be adding to?";
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

void viewerMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    int select;
    //select which class
    cout << "what type of section will you be viewing?";
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
    if (select == 1 && *NumOfSectionsNorm > 0) {
        cout << "\nwhich class will you view in? (please enter the last digit in name or a negative number to view averages for all classes)\n";
        for (int i = 0; i < *NumOfSectionsNorm; i++) {
            cout << NormStu[i][0].getZNumber();
            cout << "\n";
        }
        do {
            cin >> select;
            //ensures the selection is a number
            while (cin.fail()) {
                cout << "\nInvalid Input, please try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> select;
            }
            //error message
            if (select > *NumOfSectionsNorm) {
                cout << "\nInvalid input, pleas try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (select >= *NumOfSectionsNorm);
        if (select >= 0) {
            viewClass(NormStu[select], normSize[select] + 1);
        } else {
            COP3014 Holder[*NumOfSectionsNorm];
            for (int i = 0; i < *NumOfSectionsNorm; i++) {
                Holder[i] = NormStu[i][0];
            }
            viewClass(Holder, *NumOfSectionsNorm);
        }
    } else if (select == 2 && *NumOfSectionsSum > 0) {
        cout << "\nwhich class will you view in? (please enter the last digit in name or a negative number to view averages for all classes)\n";
        for (int i = 0; i < *NumOfSectionsSum; i++) {
            cout << SumStu[i][0].getZNumber();
            cout << "\n";
        }
        do {
            cin >> select;
            //ensures the selection is a number
            while (cin.fail()) {
                cout << "\nInvalid Input, please try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> select;
            }
            //error message
            if (select > *NumOfSectionsSum) {
                cout << "\nInvalid input, pleas try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (select >= *NumOfSectionsSum);
        if (select >= 0) {
            viewClass(SumStu[select], sumSize[select] + 1);
        } else {
            Summer23 Holder[*NumOfSectionsNorm];
            for (int i = 0; i < *NumOfSectionsSum; i++) {
                Holder[i] = SumStu[i][0];
            }
            viewClass(Holder, *NumOfSectionsSum);
        }
    } else {
        cout << "\nthere are no classes of that type\n";
    }

}

void addingMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    int select;
    cout << "\nWhat type of section is the student in?";
    cout << "\n1: COP3014 \t2: Summer23\n";
    do {
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
    if (select == 1 && *NumOfSectionsSum > 0) {
        cout << "\nwhich section are they in? (please enter the last digit in name)\n";
        for (int i = 0; i < *NumOfSectionsNorm; i++) {
            cout << NormStu[i][0].getZNumber();
            cout << "\n";
        }
        do {
            cin >> select;
            //ensures the selection is a number
            while (cin.fail()) {
                cout << "\nInvalid Input, please try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> select;
            }
            //error message
            if (select > *NumOfSectionsNorm || select < 0) {
                cout << "\nInvalid input, pleas try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (select >= *NumOfSectionsNorm || select < 0);
        if (normSize[select] < MAXCLASSSIZE - 1) {
            normSize[select] = normSize[select] + 1;
            NormStu[select][normSize[select]].setAllInput();
            averageCalc(NormStu[select], normSize[select]);
        } else {
            cout << "class is to big";
        }
    } else if (select == 2 && *NumOfSectionsSum > 0){
        cout << "\nwhich section are they in? (please enter the last digit in name)\n";
        for (int i = 0; i < *NumOfSectionsSum; i++) {
            cout << SumStu[i][0].getZNumber();
            cout << "\n";
        }
        do {
            cin >> select;
            //ensures the selection is a number
            while (cin.fail()) {
                cout << "\nInvalid Input, please try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> select;
            }
            //error message
            if (select > *NumOfSectionsSum || select < 0) {
                cout << "\nInvalid input, pleas try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (select >= *NumOfSectionsSum || select < 0);
        if (sumSize[select] < MAXCLASSSIZE - 1) {
            sumSize[select] = sumSize[select] + 1;
            SumStu[select][sumSize[select]].setAllInput();
            averageCalc(SumStu[select], sumSize[select]);
        } else {
            cout << "Class is to big";
        }
    } else {
        cout << "\nthere are no sections of that type\n";
    }
}

void classMaker(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    int select;
    cout << "\nwhat type of class will be added?";
    cout << "\n1: COP3014 \t2: Summer23\n";
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
    if (select == 1) {
        if (*NumOfSectionsNorm < MAXNUMBEROFSECTIONS) {
            cout << "\nHow many students are you adding? (max 75)\n";
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
                if ((select < 0) || (select > 75)) {
                    cout << "\nInvalid input, the max is 75, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while ((select < 0) || (select > 75));
            NormStu[*NumOfSectionsNorm][0].setFirstName("NormalSection" + to_string(*NumOfSectionsNorm));
            NormStu[*NumOfSectionsNorm][0].setLastName("Size: " + to_string(select));
            NormStu[*NumOfSectionsNorm][0].setZNumber("COP3014-" + to_string(*NumOfSectionsNorm));
            for (int i = 1; i <= select; i++) {
                cout << "\n---Student #" << i << "---\n";
                NormStu[*NumOfSectionsNorm][i].setAllInput();
            }
            normSize[*NumOfSectionsNorm] = select;
            *NumOfSectionsNorm = *NumOfSectionsNorm + 1;
            averageCalc(NormStu[*NumOfSectionsSum - 1], normSize[*NumOfSectionsSum - 1]);
        } else {
            cout << "\nYou already have to many sections don't overwork yourself!\n";
        }
    } else  {
        if (*NumOfSectionsSum < MAXNUMBEROFSECTIONS) {
            cout << "\nHow many students are you adding? (max 75)\n";
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
                if ((select < 0) || (select > 75)) {
                    cout << "\nInvalid input, the max is 75, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while ((select < 0) || (select > 75));
            SumStu[*NumOfSectionsSum][0].setFirstName("SummerSection" + to_string(*NumOfSectionsSum));
            SumStu[*NumOfSectionsNorm][0].setLastName("Size: " + to_string(select));
            SumStu[*NumOfSectionsNorm][0].setZNumber("Summer23-" + to_string(*NumOfSectionsSum));
            for (int i = 1; i <= select; i++) {
                cout << "\n---Student #" << i << "---\n";
                SumStu[*NumOfSectionsNorm][i].setAllInput();
            }
            sumSize[*NumOfSectionsSum] = select;
            *NumOfSectionsSum = *NumOfSectionsSum + 1;
            averageCalc(SumStu[*NumOfSectionsSum - 1], sumSize[*NumOfSectionsSum - 1]);
        } else {
            cout << "\nYou already have to many sections don't overwork yourself!\n";
        }
    }

}

void finder(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {

}

void removalMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    int select;
    cout << "\n-----Removal Menu-----\n";
    cout << "\n\t0:Remove Normal Student\n\t1:Remove Summer Student\n\t2:Remove Normal Class\n\t3:Remove Summer Class\n";
    do {
        cin >> select;
        //ensure input is a number
        while (cin.fail()) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > 3 || select < 0) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (select > 3 || select < 0);
    switch (select) {
        case 0:
            cout << "\nwhich section are they in? (please enter the last digit in name)\n";
            for (int i = 0; i < *NumOfSectionsNorm; i++) {
                cout << NormStu[i][0].getZNumber();
                cout << "\n";
            }
            do {
                cin >> select;
                //ensures the selection is a number
                while (cin.fail()) {
                    cout << "\nInvalid Input, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> select;
                }
                //error message
                if (select > *NumOfSectionsNorm || select < 0) {
                    cout << "\nInvalid input, pleas try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (select >= *NumOfSectionsNorm || select < 0);
            removeStudents(NormStu[select], &normSize[select]);
            break;
        case 1:
            cout << "\nwhich section are they in? (please enter the last digit in name)\n";
            for (int i = 0; i < *NumOfSectionsSum; i++) {
                cout << SumStu[i][0].getZNumber();
                cout << "\n";
            }
            do {
                cin >> select;
                //ensures the selection is a number
                while (cin.fail()) {
                    cout << "\nInvalid Input, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> select;
                }
                //error message
                if (select > *NumOfSectionsSum || select < 0) {
                    cout << "\nInvalid input, pleas try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (select >= *NumOfSectionsSum || select < 0);
            removeStudents(SumStu[select], &sumSize[select]);
            break;
        case 2:
            removeClass(NormStu, normSize, NumOfSectionsNorm);
            break;
        case 3:
            removeClass(SumStu, sumSize, NumOfSectionsSum);
            break;
    }
}

void averageCalc(COP3014 students[], int NumStudents) {
    double quiz[3] = {0, 0, 0};
    double midterm = 0;
    double final = 0;
    for (int i = 1; i <= NumStudents; i++) {
        quiz[0] = quiz[0] + students[i].getQuizGrades(1);
        quiz[1] = quiz[1] + students[i].getQuizGrades(2);
        quiz[2] = quiz[2] + students[i].getQuizGrades(3);
        midterm = midterm + students[i].getMidtermGrade();
        final = final + students[i].getFinalGrade();
    }
    quiz[0] = quiz[0]/NumStudents;
    quiz[1] = quiz[1]/NumStudents;
    quiz[2] = quiz[2]/NumStudents;
    midterm = midterm/NumStudents;
    final = final/NumStudents;
    students[0].setQuizGrades(quiz);
    students[0].setMidtermGrade(midterm);
    students[0].setFinalGrade(final);
    students[0].computeTotalGrade();
    students[0].determineLetterGrade();
}

void averageCalc(Summer23 students[], int NumStudents) {
    double quiz[3] = {0, 0, 0};
    double midterm = 0;
    double final = 0;
    double bonus = 0;
    for (int i = 1; i <= NumStudents; i++) {
        quiz[0] = quiz[0] + students[i].getQuizGrades(1);
        quiz[1] = quiz[1] + students[i].getQuizGrades(2);
        quiz[2] = quiz[2] + students[i].getQuizGrades(3);
        midterm = midterm + students[i].getMidtermGrade();
        final = final + students[i].getFinalGrade();
        bonus = bonus + students[i].getBonus();
    }
    quiz[0] = quiz[0]/NumStudents;
    quiz[1] = quiz[1]/NumStudents;
    quiz[2] = quiz[2]/NumStudents;
    midterm = midterm/NumStudents;
    final = final/NumStudents;
    bonus = bonus/NumStudents;
    students[0].setQuizGrades(quiz);
    students[0].setMidtermGrade(midterm);
    students[0].setFinalGrade(final);
    students[0].setBonus(bonus);
    students[0].computeTotalGrade();
    students[0].addBonus();
    students[0].determineLetterGrade();
}

void removeClass(COP3014 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses) {
    int select;
    cout << "Which class will you be removing?";
    for (int i = 0; i < *NumOfClasses; i++) {
        cout << students[i][0].getZNumber();
        cout << "\n";
    }
    do {
        cin >> select;
        //ensures the selection is a number
        while (cin.fail()) {
            cout << "\nInvalid Input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > *NumOfClasses || select < 0) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (select > *NumOfClasses || select < 0);
    if (*NumOfClasses == MAXCLASSSIZE) {
        COP3014 Empty;
        for (int i = 0; i < NumOfStudents[*NumOfClasses]; i++) {
           students[NumOfStudents[*NumOfClasses]][i] = Empty;
        }
        NumOfStudents[*NumOfClasses] = 0;
        *NumOfClasses = *NumOfClasses - 1;
    } else {
        for (int i = select; i < *NumOfClasses; i++) {
            for (int j = 0; j <= NumOfStudents[i+1]; j++) {
                students[i][j] = students[i + 1][j];
            }
            NumOfStudents[i] = NumOfStudents[i+1];
        }
        *NumOfClasses = *NumOfClasses - 1;
    }
}

void removeClass(Summer23 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses) {
    int select;
    cout << "Which class will you be removing?";
    for (int i = 0; i < *NumOfClasses; i++) {
        cout << students[i][0].getZNumber();
        cout << "\n";
    }
    do {
        cin >> select;
        //ensures the selection is a number
        while (cin.fail()) {
            cout << "\nInvalid Input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > *NumOfClasses || select < 0) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (select > *NumOfClasses || select < 0);
    if (*NumOfClasses == MAXCLASSSIZE) {
        Summer23 Empty;
        for (int i = 0; i < NumOfStudents[*NumOfClasses]; i++) {
            students[NumOfStudents[*NumOfClasses]][i] = Empty;
        }
        NumOfStudents[*NumOfClasses] = 0;
        *NumOfClasses = *NumOfClasses - 1;
    } else {
        for (int i = select; i < *NumOfClasses; i++) {
            for (int j = 0; j <= NumOfStudents[i+1]; j++) {
                students[i][j] = students[i + 1][j];
            }
            NumOfStudents[i] = NumOfStudents[i+1];
        }
        *NumOfClasses = *NumOfClasses - 1;
    }
}

void removeStudents(COP3014 students[], int *NumOfStudents) {
    int select;
    cout << "Which Student would you like to remove? (please use the number order they are in)";
    viewClass(students, *NumOfStudents);
    do {
        cin >> select;
        //ensures the selection is a number
        while (cin.fail()) {
            cout << "\nInvalid Input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > *NumOfStudents || select <= 0) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (select > *NumOfStudents || select <= 0);
    for (int i = select; i <= *NumOfStudents; i++) {
        students[i] = students[i+1];
    }
    *NumOfStudents = *NumOfStudents - 1;
    averageCalc(students = students, *NumOfStudents);
}

void removeStudents(Summer23 students[], int *NumOfStudents) {
    int select;
    cout << "Which Student would you like to remove? (please use the number order they are in)";
    viewClass(students, *NumOfStudents);
    do {
        cin >> select;
        //ensures the selection is a number
        while (cin.fail()) {
            cout << "\nInvalid Input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > *NumOfStudents || select <= 0) {
            cout << "\nInvalid input, pleas try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (select > *NumOfStudents || select <= 0);
    for (int i = select; i <= *NumOfStudents; i++) {
        students[i] = students[i+1];
    }
    *NumOfStudents = *NumOfStudents - 1;
    averageCalc(students = students, *NumOfStudents);
}