//
// Created by Yimer on 7/13/2023.
//
#include <iostream>
#include <string>
#include <limits>
#include "Summer23.h"

//overloaded Constructor
Summer23::Summer23(double *quizGrades, double midtermGrade, double finalGrade, double totalGrade, char finalLetterGrade,
                   const string &firstName, const string &lastName, const string &zNumber, double bonus) : COP3014(
        quizGrades, midtermGrade, finalGrade, totalGrade, finalLetterGrade, firstName, lastName, zNumber),
                                                                                                           bonus(bonus) {}
//Constructor
Summer23::Summer23() {
    COP3014();
    bonus = 0.00;
    isBonusON = false;
}

// redefined sets all the variables in COP3014 and Summer23 using user input
void Summer23::setAllInput() {
    //use the previous setAllInput
    COP3014::setAllInput();
    isBonusON = false;
    //now receive and add bonus
    cout << "\nPlease enter " << getFirstName() << "'s bonus percent (max 3%)\n";
    cin >> bonus;
    //do-while ensures we have a bonus between 0 and 3 inclusive
    do {
        //ensures an actual number is received
        while (cin.fail()){
            cout << "\nInvalid Grade\n";
            cout << "\nplease try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> bonus;
        }
        //error message
        if ((bonus < 0) || (bonus > 3)) {
            cout << "\nbonus have a maximum of 3 percent. bonuses can't be less than 0\n";
            cout << "\nplease try again (:\n";
        }
    } while ((bonus < 0) || (bonus > 3));
    //calculate and redetermine grade with bonus
    COP3014::computeTotalGrade();
    addBonus();
    determineLetterGrade();
}

// displays all data in parent and child class in a readable way
void Summer23::displayData() {
    //very similar to original one we just add or removed the bonus. for the last display to be consistent with the display in the instructions.
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "\n" + getFirstName() + " " + getLastName() + "-" +getZNumber() + "\n";
    cout << "\n\tQuiz 1: " << getQuizGrades(1);
    cout << "\n\tQuiz 2: " << getQuizGrades(2);
    cout << "\n\tQuiz 3: " << getQuizGrades(3);
    cout << "\n\tMidterm: " << getMidtermGrade();
    cout << "\n\tFinal: " << getFinalGrade();
    removeBonus();
    cout << "\n\tTotal grade: " << getTotalGrade();
    cout << "\n\tBonus: " << bonus;
    cout << "\n\tFinal grade: " << getFinalLetterGrade();
    addBonus();
}

//getter and setter for bonus
double Summer23::getBonus() {
    return bonus;
}

void Summer23::setBonus(double bonus) {
    //removes the bonus before changing it if necessary
    removeBonus();
    Summer23::bonus = bonus;
}

// adds the bonus if it isn't already on
void Summer23::addBonus() {
    if (!isBonusON) {
        setTotalGrade(getTotalGrade() + bonus);
        isBonusON = true;
    }
}

//removes the bonus if it is on
void Summer23::removeBonus() {
    if (isBonusON) {
        setTotalGrade(getTotalGrade() - bonus);
        isBonusON = false;
    }
}

//setsTotalGrade while also manging the isBonusON variable
void Summer23::setTotalGrade(double totalGrade) {
    COP3014::setTotalGrade(totalGrade);
    isBonusON = false;
}