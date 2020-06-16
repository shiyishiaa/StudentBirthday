//
// Created by Administrator on 2020/6/15.
//

#ifndef HW03_STUDENTBIRTHDAY_H
#define HW03_STUDENTBIRTHDAY_H

#define uint unsigned int
#define ullong unsigned long long

#include <iostream>
#include <ctime>
#include "function.cpp"

using namespace std;
using namespace function;

class studentBirthday {
private:
    string name;
    bool gender;// male==1, female=0
    ullong idNumber;
    uint year, month, day;
    ullong phoneNumber;
    string major;
    string mail;

public:
    studentBirthday();

    explicit studentBirthday(string str);

    static studentBirthday parseStudent(string str);

    studentBirthday &operator=(const int &null);

    bool operator==(const studentBirthday &another);

    bool operator>(const studentBirthday &after) const;

    bool operator<(const studentBirthday &after) const;

    bool isSameDay(const studentBirthday &another) const;

    bool isEmpty() const;

    string getName() const;

    uint getMonth() const;

    uint getDay() const;

    int daysToBirthday() const;
};


#endif //HW03_STUDENTBIRTHDAY_H
