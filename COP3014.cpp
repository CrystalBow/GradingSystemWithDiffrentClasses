//
// Created by Yimer on 7/13/2023.
//
#include <iostream>
#include <string>
#include <limits>
#include "COP3014.h"
using namespace std;

//simple getters and setters
double COP3014::getMidtermGrade() {
    return midtermGrade;
}


void COP3014::setMidtermGrade(double midtermGrade) {
    COP3014::midtermGrade = midtermGrade;
}


double COP3014::getFinalGrade() {
    return finalGrade;
}


void COP3014::setFinalGrade(double finalGrade) {
    COP3014::finalGrade = finalGrade;
}

double COP3014::getTotalGrade() {
    return totalGrade;
}

void COP3014::setTotalGrade(double totalGrade) {
    COP3014::totalGrade = totalGrade;
}

char COP3014::getFinalLetterGrade() {
    return finalLetterGrade;
}

void COP3014::setFinalLetterGrade(char finalLetterGrade) {
    COP3014::finalLetterGrade = finalLetterGrade;
}

//Overloaded constructor
COP3014::COP3014(double quizGrades[], double midtermGrade, double finalGrade, double totalGrade, char finalLetterGrade,
                 const string &firstName, const string &lastName, const string &zNumber) :
        midtermGrade(midtermGrade),
        finalGrade(finalGrade),
        totalGrade(totalGrade),
        finalLetterGrade(
                finalLetterGrade),
        firstName(firstName),
        lastName(lastName),
        zNumber(zNumber) {
    //initializing quizGrades
    setQuizGrades(quizGrades);
}

//default constructor
COP3014::COP3014() {
    //setting everything to the max as instructed
    for (int i = 0; i < 3; i++) {
        // going through the quiz entries
        quizGrades[i] = 20;
    }
    midtermGrade = 100;
    finalGrade = 100;
    totalGrade = 100;
    finalLetterGrade = 'A';
}

//prompts for and gets values for all the variables in the class
void COP3014::setAllInput() {
    //will be used to ensure the z number is an actual number
    int zDigits;
    //simple string data first
    cout << "\nwhat is the students first name?\n";
    cin >> firstName;
    cout << "\nwhat is the students last name?\n";
    cin >> lastName;
    //now for the z num
    cout << "\nwhat is the students z number?(please enter the number without the z)\n";
    //the do while ensures we have the correct number of digits and that the number isn't negative.
    do {
        cin >> zDigits;
        //this while ensures we don't get any characters
        while (cin.fail()) {
            cout << "\nInvalid Number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nplease try again\n";
            cin >> zDigits;
        }
        //adding the z and making it a string
        zNumber = 'Z' + to_string(zDigits);
        //error message
        if ((zNumber.size() != 9) || (zDigits < 0)) {
            cout << "\nInvalid Number\n";
            cout << "\nplease try again\n";
        }
    } while ((zNumber.size() != 9) || (zDigits < 0));
    //input for the 3 quiz's.
    //iterate over the array using a loop
    for (int i = 0; i < 3; i++) {
        //the do while ensures we get a valid quiz grade between 0 and 20 inclusive
        do {
            cout << "Please enter " + firstName + "'s grade for quiz #" + to_string(i + 1) + "\n";
            cin >> quizGrades[i];
            //ensures we actually get a number
            while (cin.fail()) {
                cout << "\nInvalid Grade\n";
                cout << "\nplease try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> quizGrades[i];
            }
            //error message
            if ((quizGrades[i] > 20) || (quizGrades[i] < 0)) {
                cout << "\nquiz's have a maximum of 20 points. Grades must be greater than 0\n";
                cout << "\nplease try again (:\n";
            }
        } while ((quizGrades[i] > 20) || (quizGrades[i] < 0));
    }
    //input for midterm
    cout << "\nPlease enter " + firstName + "'s grade on the midterm\n";
    //ensures that num is between 0 and 100 inclusive
    do {
        cin >> midtermGrade;
        //ensures we actually get a number
        while (cin.fail()) {
            cout << "\nInvalid Grade\n";
            cout << "\nplease try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> midtermGrade;
        }
        //error message
        if ((midtermGrade > 100) || (midtermGrade < 0)) {
            cout << "\nmidterm have a maximum of 100 points. Grades must be greater than 0\n";
            cout << "\nplease try again (:\n";
        }
    } while ((midtermGrade > 100) || (midtermGrade < 0));
    //ensures we receive a final grade between 0 and 100 inclusive
    do {
        cout << "\nPlease enter " + firstName + "'s grade on the final exam\n";
        cin >> finalGrade;
        //ensures we actually receive a number
        while (cin.fail()) {
            cout << "\nInvalid Grade\n";
            cout << "\nplease try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> finalGrade;
        }
        //error message
        if ((finalGrade > 100 )|| (finalGrade < 0)) {
            cout << "\nfinals have a maximum of 100 points. Grades must be greater than 0\n";
            cout << "\nplease try again (:\n";
        }

    } while ((finalGrade > 100 )|| (finalGrade < 0));
    //computation of total and grade determination
    computeTotalGrade();
    determineLetterGrade();
}

//calculates total grade
void COP3014::computeTotalGrade() {
    //equation given in instructions
    totalGrade = ((quizGrades[0] + quizGrades[1] + quizGrades[2])/3.0) + midtermGrade * 0.3 + finalGrade * 0.5;
}

//determines letter grade
void COP3014::determineLetterGrade() {
    //grading scale provided in instructions.
    if (totalGrade >= 90.00) {
        finalLetterGrade = 'A';
    } else if (totalGrade >= 80.00) {
        finalLetterGrade = 'B';
    } else if (totalGrade >= 70.00) {
        finalLetterGrade = 'C';
    } else if (totalGrade >= 60.00) {
        finalLetterGrade = 'D';
    } else {
        finalLetterGrade = 'F';
    }
    //If they are absent for the midterm or final they get an F
    if ((finalGrade == 0) || (midtermGrade == 0)) {
        finalLetterGrade = 'F';
    }
}

//displays all the data in the class in a readable fashion
void COP3014::displayData() {
    //followed the format shown the instructions
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "\n" + firstName + " " + lastName + "-" +zNumber + "\n";
    cout << "\n\tQuiz 1: " << quizGrades[0];
    cout << "\n\tQuiz 2: " << quizGrades[1];
    cout << "\n\tQuiz 3: " << quizGrades[2];
    cout << "\n\tMidterm: " << midtermGrade;
    cout << "\n\tFinal: " << finalGrade;
    cout << "\n\tTotal grade: " << totalGrade;
    cout << "\n\tFinal grade: " << finalLetterGrade;
}

//This getter allows you to save each quiz value in the array to a double variable outside the class
void COP3014::getQuizGrades(double *q1, double *q2, double *q3) {
    *q1 = getQuizGrades(1);
    *q2 = getQuizGrades(2);
    *q3 = getQuizGrades(3);
}

//this setter allows you to set each of quiz of the array from 3 individual double variables
void COP3014::setQuizGrades(double q1, double q2, double q3) {
    quizGrades[0] = q1;
    quizGrades[1] = q2;
    quizGrades[2] = q3;
}

//this setter allow you to input all the quiz grades as one array
void COP3014::setQuizGrades(double quizes[]) {
    for (int i = 0; i < 3; i++) {
        quizGrades[i] = quizes[i];
    }
}

//This version of getQuizGrades allows you to extract all 3 grades as an array.
void COP3014::getQuizGrades(double location[]) {
    for (int i = 0; i < 3; i++) {
        location[i] = quizGrades[i];
    }
}

//This gets one specific quiz grade via the integer specified
//1 for quiz 1, 2 for quiz 2, 3 for quiz 3.
double COP3014::getQuizGrades(int quizNum) {
    if ((0 < quizNum) && (quizNum <= 3)) {
        return quizGrades[quizNum - 1];
    } else {
        //if wrong number is put in
        cout << "there is no quiz number " << quizNum << "\n";
        return 0.00;
    }
}

//getters and setters
const string &COP3014::getFirstName() {
    return firstName;
}

void COP3014::setFirstName(const string &firstName) {
    COP3014::firstName = firstName;
}

const string &COP3014::getLastName() {
    return lastName;
}

void COP3014::setLastName(const string &lastName) {
    COP3014::lastName = lastName;
}

const string &COP3014::getZNumber() {
    return zNumber;
}

void COP3014::setZNumber(const string &zNumber) {
    COP3014::zNumber = zNumber;
}