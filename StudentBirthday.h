//
// Created by Administrator on 2020/6/15.
//

#ifndef STUDENTBIRTHDAY_STUDENTBIRTHDAY_H
#define STUDENTBIRTHDAY_STUDENTBIRTHDAY_H

#define uint unsigned int
#define ullong unsigned long long

#include <iostream>
#include <ctime>
#include "function.cpp"

using namespace std;
using namespace function;

class StudentBirthday {
private:
    string name;
    bool gender;// male==1, female=0
    ullong idNumber;
    uint year, month, day;
    ullong phoneNumber;
    string major;
    string mail;

public:
    StudentBirthday();

    explicit StudentBirthday(string str);

    static StudentBirthday parseStudent(string str);

    StudentBirthday &operator=(const int &null);

    bool operator==(const StudentBirthday &another);

    bool operator>(const StudentBirthday &after) const;

    bool operator<(const StudentBirthday &after) const;

    bool isSameDay(const StudentBirthday &another) const;

    bool isEmpty() const;

    string getName() const;

    uint getMonth() const;

    uint getDay() const;

    int daysToBirthday() const;
};


#endif //STUDENTBIRTHDAY_STUDENTBIRTHDAY_H
