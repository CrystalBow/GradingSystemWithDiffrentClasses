#ifndef COP3014_H
#define COP3014_H
#include "COP3014.h"
#include "Summer23.h"
#endif
#include <iostream>
#include <string>
#include <limits>
#include <regex>


//The size of the array for my classes. A class actually only has 75 students, but index 0 will be used for class averages.
const int MAXCLASSSIZE = 76;
//The max number sections available.
const int MAXNUMBEROFSECTIONS = 7;

using namespace std;
using namespace studentTypesYimerDuggan;

//shows and adds the example data from the instructions
void demonstration(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]);

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

//Removes class from the system
void removeClass(COP3014 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses);

//Overload for removing summer classes
void removeClass(Summer23 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses);

//Menus for removing students
void removeStudents(COP3014 students[], int* NumOfStudents);

//Menus for removing students
void removeStudents(Summer23 students[], int* NumOfStudents);

//Menus for changing grades
void editGradesMenu(Summer23* Student);

//Overload for changing grades of normal students
void editGradesMenu(COP3014* Student);

//Updates Class Averages
void AverageUpdater(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]);


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
                finder(summerClass, normalClass, &summerSections, &normalSections, summerStudents, normalStudents);
                break;
            case 5: //Removal
                removalMenu(summerClass, normalClass, &summerSections, &normalSections,summerStudents, normalStudents);
                break;
            case 6: //Demonstration
                demonstration(summerClass, normalClass, &summerSections, &normalSections, summerStudents, normalStudents);
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
void demonstration(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
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
    if (*NumOfSectionsNorm < MAXNUMBEROFSECTIONS) {
        NormStu[*NumOfSectionsNorm][1] = frankBase;
        NormStu[*NumOfSectionsNorm][2] = ginaBase;
        normSize[*NumOfSectionsNorm] = 2;
        NormStu[*NumOfSectionsNorm][0].setFirstName("NormalSection" + to_string(*NumOfSectionsNorm));
        NormStu[*NumOfSectionsNorm][0].setLastName("\nSize: " + to_string(2) + "\n");
        NormStu[*NumOfSectionsNorm][0].setZNumber("COP3014-" + to_string(*NumOfSectionsNorm));
        averageCalc(NormStu[*NumOfSectionsNorm], normSize[*NumOfSectionsNorm]);
        *NumOfSectionsNorm = *NumOfSectionsNorm + 1;
    }
    if (*NumOfSectionsSum < MAXNUMBEROFSECTIONS) {
        SumStu[*NumOfSectionsSum][1] = frankDerived;
        SumStu[*NumOfSectionsSum][2] = ginaDerived;
        sumSize[*NumOfSectionsSum] = 2;
        SumStu[*NumOfSectionsSum][0].setFirstName("SummerSection" + to_string(*NumOfSectionsSum));
        SumStu[*NumOfSectionsSum][0].setLastName("\nSize: " + to_string(2) + "\n");
        SumStu[*NumOfSectionsSum][0].setZNumber("Summer23-" + to_string(*NumOfSectionsSum));
        averageCalc(SumStu[*NumOfSectionsSum], normSize[*NumOfSectionsSum]);
        *NumOfSectionsSum = *NumOfSectionsSum + 1;
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

//Viewing Menu
void viewerMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    //input reception variable
    int select;
    //select which class prompt
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
    //makes sure there is an actual class available to display
    if (select == 1 && *NumOfSectionsNorm > 0) {
        //COP3014
        cout << "\nwhich class will you view in? (please enter the last digit in name or a negative number to view averages for all classes)\n";
        //Displays classes available for viewing
        for (int i = 0; i < *NumOfSectionsNorm; i++) {
            cout << NormStu[i][0].getZNumber();
            cout << "\n";
        }
        //Receive input
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
            //view a selected class
            viewClass(NormStu[select], normSize[select] + 1);
        } else {
            //view all the averages
            COP3014 Holder[*NumOfSectionsNorm];
            //Creates a class built of the averages to plug into viewClass()
            for (int i = 0; i < *NumOfSectionsNorm; i++) {
                Holder[i] = NormStu[i][0];
            }
            viewClass(Holder, *NumOfSectionsNorm);
        }
    } else if (select == 2 && *NumOfSectionsSum > 0) {
        //summer23
        cout << "\nwhich class will you view in? (please enter the last digit in name or a negative number to view averages for all classes)\n";
        //Displays classes available for viewing
        for (int i = 0; i < *NumOfSectionsSum; i++) {
            cout << SumStu[i][0].getZNumber();
            cout << "\n";
        }
        //Receive input
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
            //view a selected class
            viewClass(SumStu[select], sumSize[select] + 1);
        } else {
            //view all the averages
            Summer23 Holder[*NumOfSectionsNorm];
            //Creates a class built of the averages to plug into viewClass()
            for (int i = 0; i < *NumOfSectionsSum; i++) {
                Holder[i] = SumStu[i][0];
            }
            viewClass(Holder, *NumOfSectionsSum);
        }
    } else {
        //display when there are no classes of the type specified
        cout << "\nthere are no classes of that type\n";
    }

}

//Adding Menu
void addingMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    //input reception variable
    int select;
    //prompt to select class type
    cout << "\nWhat type of section is the student in?";
    cout << "\n1: COP3014 \t2: Summer23\n";
    //receive input
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
    //Check to see if there is a class to put a student in
    if (select == 1 && *NumOfSectionsSum > 0) {
        //COP3014
        //prompt and class display
        cout << "\nwhich section are they in? (please enter the last digit in name)\n";
        for (int i = 0; i < *NumOfSectionsNorm; i++) {
            cout << NormStu[i][0].getZNumber();
            cout << "\n";
        }
        //receive input
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
        //makes sure that we don't add a student to an already full class
        if (normSize[select] < MAXCLASSSIZE - 1) {
            //adds the student
            normSize[select] = normSize[select] + 1;
            NormStu[select][normSize[select]].setAllInput();
            averageCalc(NormStu[select], normSize[select]);
            //updates the string the average with the correct value
            NormStu[select][0].setLastName("\nSize: " + to_string(normSize[select]) + "\n");
        } else {
            //message for class that is too big
            cout << "class is to big";
        }
    } else if (select == 2 && *NumOfSectionsSum > 0){
        //Summer23
        //prompt and class display
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
        //makes sure that we don't add a student to an already full class
        if (sumSize[select] < MAXCLASSSIZE - 1) {
            //adds the student
            sumSize[select] = sumSize[select] + 1;
            SumStu[select][sumSize[select]].setAllInput();
            averageCalc(SumStu[select], sumSize[select]);
            //updates the string the average with the correct value
            SumStu[select][0].setLastName("\nSize: " + to_string(sumSize[select]) + "\n");
        } else {
            //message for class that is too big
            cout << "Class is to big";
        }
    } else {
        //message for when there is no class of the type specified
        cout << "\nthere are no sections of that type\n";
    }
}

//Class Maker Menus: for making a class section
void classMaker(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    //select will be used to receive menu inputs
    int select;
    //prompt
    cout << "\nwhat type of class will be added?";
    cout << "\n1: COP3014 \t2: Summer23\n";
    //receive input
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
        //1: COP3014 classes
        if (*NumOfSectionsNorm < MAXNUMBEROFSECTIONS) {
            //^Made sure there is still room in array^
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
            //Setting up the class average. Storing information in the strings to make displaying easier
            //The FirstName will hold the section type and number
            NormStu[*NumOfSectionsNorm][0].setFirstName("NormalSection" + to_string(*NumOfSectionsNorm));
            //The LastName will hold the class size
            NormStu[*NumOfSectionsNorm][0].setLastName("\nSize: " + to_string(select) + "\n");
            //The zNumber will be the display name in the menus
            NormStu[*NumOfSectionsNorm][0].setZNumber("COP3014-" + to_string(*NumOfSectionsNorm));
            //Fills out students equal to the amount specified earlier
            for (int i = 1; i <= select; i++) {
                cout << "\n---Student #" << i << "---\n";
                NormStu[*NumOfSectionsNorm][i].setAllInput();
            }
            //Put in the class size, increase the class count, and Set up the rest of the average values
            normSize[*NumOfSectionsNorm] = select;
            *NumOfSectionsNorm = *NumOfSectionsNorm + 1;
            //The NumOfSectionsSum and NumOfSectionsNorm need to adapted for index. We subtract by one to achieve that.
            averageCalc(NormStu[*NumOfSectionsSum - 1], normSize[*NumOfSectionsSum - 1]);
        } else {
            //message if you have to many classes
            cout << "\nYou already have to many sections don't overwork yourself!\n";
        }
    } else  {
        //2: Summer23 classes
        if (*NumOfSectionsSum < MAXNUMBEROFSECTIONS) {
            //^Made sure there is still room in array^
            //prompt and receive input
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
            //Setting up the class average. Storing information in the strings to make displaying easier
            //The FirstName will hold the section type and number
            SumStu[*NumOfSectionsSum][0].setFirstName("SummerSection" + to_string(*NumOfSectionsSum));
            //The LastName will hold the class size
            SumStu[*NumOfSectionsNorm][0].setLastName("\nSize: " + to_string(select) + "\n");
            //The zNumber will be the display name in the menus
            SumStu[*NumOfSectionsNorm][0].setZNumber("Summer23-" + to_string(*NumOfSectionsSum));
            //Fills out students equal to the amount specified earlier
            for (int i = 1; i <= select; i++) {
                cout << "\n---Student #" << i << "---\n";
                SumStu[*NumOfSectionsNorm][i].setAllInput();
            }
            //Put in the class size, increase the class count, and Set up the rest of the average values
            sumSize[*NumOfSectionsSum] = select;
            *NumOfSectionsSum = *NumOfSectionsSum + 1;
            //The NumOfSectionsSum and NumOfSectionsNorm need to adapted for index. We subtract by one to achieve that.
            averageCalc(SumStu[*NumOfSectionsSum - 1], sumSize[*NumOfSectionsSum - 1]);
        } else {
            //message if you have to many classes
            cout << "\nYou already have to many sections don't overwork yourself!\n";
        }
    }

}

//Student Finder Menu
void finder(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    //I'm using regex to make searching for students easier.
    //This will be used to receive the search input form the user
    string quarry;
    //This will be used to receive input for the later menus
    int select;
    //This will be used to store data form select so select can be reused
    int target;
    //These vectors hold data about the results and their location.
    //Is the match itself
    vector<string> Items;
    //Is the status of the match as a normal student (true) or summer student (false)
    vector<bool> IsNormal;
    //Holds the location of the match in their class
    vector<int> studentNumLocation;
    //Holds the class they are in
    vector<int> classNumber;
    //counts how many matches have been found
    int MatchCount = 0;
    //prompt and receive quarry
    cout << "\nPlease enter a z number, first name, or Last name\n";
    cin >> quarry;
    //turns the quarry into type regex for searching.
    //used ECMAScript and icase constant. For improved searching and ignoring letter case (respectively)
    regex quarryX(quarry, regex_constants::ECMAScript | regex_constants::icase);\
    cout << "\nHere are the matches:\n";
    //match hunting
    for (int i = 0; i < *NumOfSectionsNorm; i++) {
        //COP3014
        for (int j = 1; j <= normSize[i]; j++) {
            /*We check each string independently.
             * If we get a match we add the necessary data to the vectors, display the student, and then move on to next student.
             * That way we prevent a student form matching more than once.
             */
            if (regex_search(NormStu[i][j].getFirstName(), quarryX)) {
                //first name
                MatchCount++;
                Items.push_back("First Name: " + NormStu[i][j].getFirstName() + "\n");
                IsNormal.push_back(true);
                classNumber.push_back(i);
                studentNumLocation.push_back(j);
                cout << "\nMatch #" << MatchCount << "\n";
                cout << Items[MatchCount - 1] << "\n";
                NormStu[i][j].displayData();
                continue;
            }
            if (regex_search(NormStu[i][j].getLastName(), quarryX)){
                //last name
                MatchCount++;
                Items.push_back("Last Name: " + NormStu[i][j].getLastName());
                IsNormal.push_back(true);
                classNumber.push_back(i);
                studentNumLocation.push_back(j);
                cout << "\nMatch #" << MatchCount << "\n";
                cout << Items[MatchCount - 1] << "\n";
                NormStu[i][j].displayData();
                continue;
            }
            if (regex_search(NormStu[i][j].getZNumber(), quarryX)){
                //zNumber
                MatchCount++;
                Items.push_back("Znumber: " + NormStu[i][j].getZNumber());
                IsNormal.push_back(true);
                classNumber.push_back(i);
                studentNumLocation.push_back(j);
                cout << "\nMatch #" << MatchCount << "\n";
                cout << Items[MatchCount - 1] << "\n";
                NormStu[i][j].displayData();
                continue;
            }
        }
    }
    for (int i = 0; i < *NumOfSectionsSum; i++) {
        //Summer23
        for (int j = 0; j <= sumSize[i]; j++) {
            /*We check each string independently.
 * If we get a match we add the necessary data to the vectors, display the student, and then move on to next student.
 * That way we prevent a student form matching more than once.
 */
            if (regex_search(SumStu[i][j].getFirstName(), quarryX)) {
                MatchCount++;
                Items.push_back("First Name: " + SumStu[i][j].getFirstName() + "\n");
                IsNormal.push_back(false);
                classNumber.push_back(i);
                studentNumLocation.push_back(j);
                cout << "\nMatch #" << MatchCount << "\n";
                cout << Items[MatchCount - 1] << "\n";
                SumStu[i][j].displayData();
                continue;
            }
            if (regex_search(SumStu[i][j].getLastName(), quarryX)){
                MatchCount++;
                Items.push_back("Last Name: " + SumStu[i][j].getLastName());
                IsNormal.push_back(false);
                classNumber.push_back(i);
                studentNumLocation.push_back(j);
                cout << "\nMatch #" << MatchCount << "\n";
                cout << Items[MatchCount - 1];
                SumStu[i][j].displayData();
                continue;
            }
            if (regex_search(SumStu[i][j].getZNumber(), quarryX)){
                MatchCount++;
                Items.push_back("Znumber: " + SumStu[i][j].getZNumber());
                IsNormal.push_back(false);
                classNumber.push_back(i);
                studentNumLocation.push_back(j);
                cout << "\nMatch #" << MatchCount << "\n";
                cout << Items[MatchCount - 1];
                SumStu[i][j].displayData();
                continue;
            }
        }
    }
    //makes sure we actually have matches
    if (MatchCount > 0) {
        //prompt and receive input
        cout << "\nwhich student would you like to inspect? (enter the match number)";
        do {
            cin >> select;
            //ensure input is a number
            while (cin.fail()) {
                cout << "\nInvalid input, please try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> select;
            }
            //error message
            if (select > MatchCount || select <= 0) {
                cout << "\nInvalid input, please try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (select > MatchCount || select <= 0);
        target = select - 1;
        if (IsNormal[target]) {
            NormStu[classNumber[target]][studentNumLocation[target]].displayData();
            cout << "\nWhat would you like to do with them? (0 for nothing)\n";
            cout << "\n\t1: Change Grades\n\t2: Remove Student\n\t";
            do {
                cin >> select;
                //ensure input is a number
                while (cin.fail()) {
                    cout << "\nInvalid input, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> select;
                }
                //error message
                if (select > 2 || select < 0) {
                    cout << "\nInvalid input, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (select > 2 || select < 0);
            if (select == 1) {
                editGradesMenu(&NormStu[classNumber[target]][studentNumLocation[target]]);
            } else if (select == 2) {
                if (normSize[classNumber[target]] >= MAXCLASSSIZE - 1) {
                    COP3014 Empty;
                    for (int i = target; i <= normSize[classNumber[target]] - 1; i++) {
                        NormStu[classNumber[target]][i] = NormStu[classNumber[target]][i+1];
                    }
                    NormStu[classNumber[target]][MAXCLASSSIZE - 1] = Empty;
                    normSize[classNumber[target]] = normSize[classNumber[target]] - 1;
                } else {
                    for (int i = target; i <= normSize[classNumber[target]]; i++) {
                        NormStu[classNumber[target]][i] = NormStu[classNumber[target]][i+1];
                    }
                    normSize[classNumber[target]] = normSize[classNumber[target]] - 1;
                }
            }
            averageCalc(NormStu[classNumber[target]], normSize[classNumber[target]]);
        } else {
            SumStu[classNumber[target]][studentNumLocation[target]].displayData();
            cout << "\nWhat would you like to do with them?";
            cout << "\n\t1: Change Grades\n\t2: Remove Student\n\t";
            do {
                cin >> select;
                //ensure input is a number
                while (cin.fail()) {
                    cout << "\nInvalid input, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> select;
                }
                //error message
                if (select > 2 || select < 0) {
                    cout << "\nInvalid input, please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (select > 2 || select < 0);
            if (select == 1) {
                editGradesMenu(&SumStu[classNumber[target]][studentNumLocation[target]]);
            } else if (select == 2) {
                if (sumSize[classNumber[target]] >= MAXCLASSSIZE - 1) {
                    Summer23 Empty;
                    for (int i = target; i <= sumSize[classNumber[target]] - 1; i++) {
                        SumStu[classNumber[target]][i] = SumStu[classNumber[target]][i+1];
                    }
                    SumStu[classNumber[target]][MAXCLASSSIZE - 1] = Empty;
                    sumSize[classNumber[target]] = sumSize[classNumber[target]] - 1;
                } else {
                    for (int i = target; i <= sumSize[classNumber[target]]; i++) {
                        SumStu[classNumber[target]][i] = SumStu[classNumber[target]][i+1];
                    }
                    sumSize[classNumber[target]] = sumSize[classNumber[target]] - 1;
                }
            }
            averageCalc(SumStu[classNumber[target]], sumSize[classNumber[target]]);
        }

    }
}

//Student and Class Section Removal
void removalMenu(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    int select;
    cout << "\n-----Removal Menu-----\n";
    cout << "\n\t0:Remove Normal Student\n\t1:Remove Summer Student\n\t2:Remove Normal Class\n\t3:Remove Summer Class\n";
    do {
        cin >> select;
        //ensure input is a number
        while (cin.fail()) {
            cout << "\nInvalid input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > 3 || select < 0) {
            cout << "\nInvalid input, please try again\n";
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
                    cout << "\nInvalid input, please try again\n";
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
                    cout << "\nInvalid input, please try again\n";
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

//calculates the average for a COP3014 class
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

//Overload to calculate the average for a Summer23 class
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
    students[0].removeBonus();
    students[0].computeTotalGrade();
    students[0].addBonus();
    students[0].determineLetterGrade();
}

//Removes class from the system
void removeClass(COP3014 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses) {
    int select;
    cout << "Which class will you be removing?\n";
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

//Overload for removing summer classes
void removeClass(Summer23 students[][MAXCLASSSIZE], int NumOfStudents[], int *NumOfClasses) {
    int select;
    cout << "Which class will you be removing?\n";
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

//Menus for removing students
void removeStudents(COP3014 students[], int *NumOfStudents) {
    int select;
    cout << "Which Student would you like to remove? (please use the number order they are in)\n";
    viewClass(students, *NumOfStudents + 1);
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
    if (*NumOfStudents >= MAXCLASSSIZE - 1) {
        COP3014 Empty;
        for (int i = select; i <= *NumOfStudents - 1; i++) {
            students[i] = students[i+1];
        }
        students[MAXCLASSSIZE - 1] = Empty;
        *NumOfStudents = *NumOfStudents - 1;
    } else {
        for (int i = select; i <= *NumOfStudents; i++) {
            students[i] = students[i+1];
        }
        *NumOfStudents = *NumOfStudents - 1;
    }
    averageCalc(students = students, *NumOfStudents);
}

//Menus for removing students
void removeStudents(Summer23 students[], int *NumOfStudents) {
    int select;
    cout << "Which Student would you like to remove? (please use the number order they are in)\n";
    viewClass(students, *NumOfStudents + 1);
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
    if (*NumOfStudents >= MAXCLASSSIZE - 1) {
        Summer23 thing;
        for (int i = select; i <= *NumOfStudents - 1; i++) {
            students[i] = students[i+1];
        }
        students[MAXCLASSSIZE - 1] = thing;
        *NumOfStudents = *NumOfStudents - 1;
    } else {
        for (int i = select; i <= *NumOfStudents; i++) {
            students[i] = students[i+1];
        }
        *NumOfStudents = *NumOfStudents - 1;
    }
    averageCalc(students = students, *NumOfStudents);
}

//Menus for changing grades
void editGradesMenu(Summer23* Student) {
    int select;
    cout << "\nWhich grades are you changing?";
    cout << "\n\t1:Quiz1\n\t2:Quiz2\n\t3:Quiz3\n\t4:AllQuiz's\n\t5:Midterm\n\t6:Final\n\t7:Everything";
    do {
        cin >> select;
        //ensure input is a number
        while (cin.fail()) {
            cout << "\nInvalid input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > 7 || select < 1) {
            cout << "\nInvalid input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (select > 7 || select < 1);
    double NewGrade;
    switch (select) {
        case 1:
            do {
                cout << "Please enter the grade for quiz #1\n";
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 20) || (NewGrade < 0)) {
                    cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 20) || (NewGrade < 0));
            Student->setQuizGrades(NewGrade, Student->getQuizGrades(2), Student->getQuizGrades(3));
            break;
        case 4:
            double NewGrades[3];
            for (int i = 0; i < 3; i++) {
                //the do while ensures we get a valid quiz grade between 0 and 20 inclusive
                do {
                    cout << "Please enter the grade for quiz #" + to_string(i + 1) + "\n";
                    cin >> NewGrades[i];
                    //ensures we actually get a number
                    while (cin.fail()) {
                        cout << "\nInvalid Grade\n";
                        cout << "\nplease try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> NewGrades[i];
                    }
                    //error message
                    if ((NewGrades[i] > 20) || (NewGrades[i] < 0)) {
                        cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                        cout << "\nplease try again (:\n";
                    }
                } while ((NewGrades[i] > 20) || (NewGrades[i] < 0));
            }
            Student->setQuizGrades(NewGrades);
            break;
        case 2:
            do {
                cout << "Please enter the grade for quiz #2\n";
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 20) || (NewGrade < 0)) {
                    cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 20) || (NewGrade < 0));
            Student->setQuizGrades(Student->getQuizGrades(1), NewGrade, Student->getQuizGrades(3));
            break;
        case 3:
            do {
                cout << "Please enter the grade for quiz #3\n";
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 20) || (NewGrade < 0)) {
                    cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 20) || (NewGrade < 0));
            Student->setQuizGrades(Student->getQuizGrades(1), Student->getQuizGrades(2), NewGrade);
            break;
        case 5:
            cout << "\nPlease enter the midterm grade\n";
            //ensures that num is between 0 and 100 inclusive
            do {
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 100) || (NewGrade < 0)) {
                    cout << "\nmidterm have a maximum of 100 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 100) || (NewGrade < 0));
            //ensures we receive a final grade between 0 and 100 inclusive
            Student->setMidtermGrade(NewGrade);
            break;
        case 6:
            cout << "\nPlease enter the final grade\n";
            do {
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 100) || (NewGrade < 0)) {
                    cout << "\nmidterm have a maximum of 100 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 100) || (NewGrade < 0));
            //ensures we receive a final grade between 0 and 100 inclusive
            Student->setFinalGrade(NewGrade);
            break;
        case 7:
            Student->setAllInput();
            break;
        case 8:
            cout << "\nPlease enter the new bonus percent (max 3%)\n";
            cin >> NewGrade;
            //do-while ensures we have a bonus between 0 and 3 inclusive
            do {
                //ensures an actual number is received
                while (cin.fail()){
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade < 0) || (NewGrade > 3)) {
                    cout << "\nbonus have a maximum of 3 percent. bonuses can't be less than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade < 0) || (NewGrade > 3));
            Student->setBonus(NewGrade);
            break;
        default:
            break;
    }
    Student->removeBonus();
    Student->computeTotalGrade();
    Student->addBonus();
    Student->determineLetterGrade();
}

//Overload for changing grades of normal students
void editGradesMenu(COP3014* Student) {
    int select;
    cout << "\nWhich grades are you changing?";
    cout << "\n\t1:Quiz1\n\t2:Quiz2\n\t3:Quiz3\n\t4:AllQuiz's\n\t5:Midterm\n\t6:Final\n\t7:Everything\n\t8:Bonus";
    do {
        cin >> select;
        //ensure input is a number
        while (cin.fail()) {
            cout << "\nInvalid input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> select;
        }
        //error message
        if (select > 7 || select < 1) {
            cout << "\nInvalid input, please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (select > 7 || select < 1);
    double NewGrade;
    switch (select) {
        case 1:
            do {
                cout << "Please enter the grade for quiz #1\n";
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 20) || (NewGrade < 0)) {
                    cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 20) || (NewGrade < 0));
            Student->setQuizGrades(NewGrade, Student->getQuizGrades(2), Student->getQuizGrades(3));
            break;
        case 4:
            double NewGrades[3];
            for (int i = 0; i < 3; i++) {
                //the do while ensures we get a valid quiz grade between 0 and 20 inclusive
                do {
                    cout << "Please enter the grade for quiz #" + to_string(i + 1) + "\n";
                    cin >> NewGrades[i];
                    //ensures we actually get a number
                    while (cin.fail()) {
                        cout << "\nInvalid Grade\n";
                        cout << "\nplease try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> NewGrades[i];
                    }
                    //error message
                    if ((NewGrades[i] > 20) || (NewGrades[i] < 0)) {
                        cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                        cout << "\nplease try again (:\n";
                    }
                } while ((NewGrades[i] > 20) || (NewGrades[i] < 0));
            }
            Student->setQuizGrades(NewGrades);
            break;
        case 2:
            do {
                cout << "Please enter the grade for quiz #2\n";
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 20) || (NewGrade < 0)) {
                    cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 20) || (NewGrade < 0));
            Student->setQuizGrades(Student->getQuizGrades(1), NewGrade, Student->getQuizGrades(3));
            break;
        case 3:
            do {
                cout << "Please enter the grade for quiz #3\n";
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 20) || (NewGrade < 0)) {
                    cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 20) || (NewGrade < 0));
            Student->setQuizGrades(Student->getQuizGrades(1), Student->getQuizGrades(2), NewGrade);
            break;
        case 5:
            cout << "\nPlease enter the midterm grade\n";
            //ensures that num is between 0 and 100 inclusive
            do {
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 100) || (NewGrade < 0)) {
                    cout << "\nmidterm have a maximum of 100 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 100) || (NewGrade < 0));
            //ensures we receive a final grade between 0 and 100 inclusive
            Student->setMidtermGrade(NewGrade);
            break;
        case 6:
            do {
                cin >> NewGrade;
                //ensures we actually get a number
                while (cin.fail()) {
                    cout << "\nInvalid Grade\n";
                    cout << "\nplease try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> NewGrade;
                }
                //error message
                if ((NewGrade > 100) || (NewGrade < 0)) {
                    cout << "\nmidterm have a maximum of 100 points. Grades must be greater than 0\n";
                    cout << "\nplease try again (:\n";
                }
            } while ((NewGrade > 100) || (NewGrade < 0));
            //ensures we receive a final grade between 0 and 100 inclusive
            Student->setFinalGrade(NewGrade);
            break;
        case 7:
            Student->setAllInput();
            break;
        default:
            break;
    }
    Student->computeTotalGrade();
    Student->determineLetterGrade();
}

//Updates Class Averages
void AverageUpdater(Summer23 SumStu[][MAXCLASSSIZE], COP3014 NormStu[][MAXCLASSSIZE], int* NumOfSectionsSum, int* NumOfSectionsNorm, int sumSize[], int normSize[]) {
    for (int i = 0; i <= *NumOfSectionsNorm; i++) {
        averageCalc(NormStu[i], normSize[i]);
    }
    for (int i = 0; i <= *NumOfSectionsSum; i++) {
        averageCalc(SumStu[i], sumSize[i]);
    }
}