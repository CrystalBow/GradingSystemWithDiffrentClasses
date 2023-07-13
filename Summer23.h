//
// Created by Yimer on 7/13/2023.
//
#include <iostream>
#include <string>
#include <limits>
#include "COP3014.h"

using namespace std;

//child class of COP3014. Holds information of a student in the summer 2023 class.
class Summer23:public COP3014 {
public:

    //overloaded Constructor
    Summer23(double *quizGrades, double midtermGrade, double finalGrade, double totalGrade, char finalLetterGrade,
             const string &firstName, const string &lastName, const string &zNumber, double bonus);

    //Constructor
    Summer23();
    // redefined sets all the variables in COP3014 and Summer23 using user input
    void setAllInput();
    // displays all data in parent and child class in a readable way
    void displayData();
    // adds the bonus if it isn't already on
    void addBonus();
    //getter and setter for bonus
    double getBonus();
    void setBonus(double bonus);
    //setsTotalGrade while also manging the isBonusON variable
    void setTotalGrade(double totalGrade);
    //removes the bonus if it is on
    void removeBonus();

private:
    double bonus;
    //So I noticed in the instructions that the display on totalGrade doesn't include the bonus, but it is added and used for the final calculation.
    //I also realized if add bonus or remove bonus where to happen more than once the totalGrade would be wrong, so this variable monitors the status of the bonus to help prevent this issue.
    //I don't want it to be accessible outside of class, so no getters or setters are provided for it.
    bool isBonusON;
};
#ifndef GRADINGSYSTEMWITHDIFFRENTCLASSES_SUMMER23_H
#define GRADINGSYSTEMWITHDIFFRENTCLASSES_SUMMER23_H

#endif //GRADINGSYSTEMWITHDIFFRENTCLASSES_SUMMER23_H
