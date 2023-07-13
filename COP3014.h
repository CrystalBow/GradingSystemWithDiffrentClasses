//
// Created by Yimer on 7/13/2023.
//
#include <iostream>
#include <string>
#include <limits>
using namespace std;
//The class holds all the grade data for 1 student of COP3014
class COP3014 {

private:
    //The quiz's are held in array of doubles. I overloaded the getters and setters to make them accessible in different ways.
    double quizGrades[3];
    //The other important grades
    double midtermGrade, finalGrade, totalGrade;
    //the letter grade of the student. Determined by the totalGrade
    char finalLetterGrade;
    //other student data
    string firstName, lastName, zNumber;

public:

    //Overloaded constructor
    COP3014(double *quizGrades, double midtermGrade, double finalGrade, double totalGrade, char finalLetterGrade,
            const string &firstName, const string &lastName, const string &zNumber);

    //default constructor
    COP3014();

    //This version of getQuizGrades allows you to extract all 3 grades as an array.
    void getQuizGrades(double location[]);

    //This gets one specific quiz grade via the integer specified
    //1 for quiz 1, 2 for quiz 2, 3 for quiz 3.
    double getQuizGrades(int quizNum);

    //This getter allows you to save each quiz value in the array to a double variable outside the class
    void getQuizGrades(double* q1, double* q2, double* q3);

    //this setter allows you to set each of quiz of the array from 3 individual double variables
    void setQuizGrades(double q1, double q2, double q3);

    //this setter allow you to input all the quiz grades as one array
    void setQuizGrades(double quizes[]);

    //other getters and setters nothing special
    double getMidtermGrade();

    void setMidtermGrade(double midtermGrade);

    double getFinalGrade();

    void setFinalGrade(double finalGrade);

    double getTotalGrade();

    void setTotalGrade(double totalGrade);

    char getFinalLetterGrade();

    void setFinalLetterGrade(char finalLetterGrade);

    //prompts for and gets values for all the variables in the class
    void setAllInput();

    //calculates total grade
    void computeTotalGrade();

    //determines letter grade
    void determineLetterGrade();

    //displays all the data in the class in a readable fashion
    void displayData();

    //getters and setters for the string variables
    const string &getFirstName();

    void setFirstName(const string &firstName);

    const string &getLastName();

    void setLastName(const string &lastName);

    const string &getZNumber();

    void setZNumber(const string &zNumber);

};

#ifndef GRADINGSYSTEMWITHDIFFRENTCLASSES_COP3014_H
#define GRADINGSYSTEMWITHDIFFRENTCLASSES_COP3014_H

#endif //GRADINGSYSTEMWITHDIFFRENTCLASSES_COP3014_H
