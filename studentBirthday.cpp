//
// Created by Administrator on 2020/6/15.
//

#include "studentBirthday.h"

studentBirthday::studentBirthday(string str) {
    studentBirthday newStudent = parseStudent(move(str));
    name = newStudent.name;
    gender = newStudent.gender;
    idNumber = newStudent.idNumber;
    year = newStudent.year;
    month = newStudent.month;
    day = newStudent.day;
    phoneNumber = newStudent.phoneNumber;
    major = newStudent.major;
    mail = newStudent.mail;
}

studentBirthday studentBirthday::parseStudent(string str) {
    studentBirthday newStudent;
    // 姓名
    newStudent.name = str.substr(0, str.find(','));

    str = str.substr(str.find(',') + 1);

    // 身份证
    newStudent.idNumber = parseLongLong(str.substr(0, str.find(',')));
    newStudent.year = (uint) parseLongLong(str.substr(6, 4));
    newStudent.month = (uint) parseLongLong(str.substr(10, 2));
    newStudent.day = (uint) parseLongLong(str.substr(12, 2));
    newStudent.gender = ((parseLongLong(str.substr(16, 1)) % 2) == 1);

    str = str.substr(str.find(',') + 1);

    //专业
    newStudent.major = str.substr(0, str.find(','));

    str = str.substr(str.find(',') + 1);

    //电话号码
    newStudent.phoneNumber = parseLongLong(str.substr(0, str.find(',')));

    str = str.substr(str.find(',') + 1);

    //邮箱
    newStudent.mail = str.substr(str.find(',') + 1);

    return newStudent;
}

studentBirthday::studentBirthday() {
    name = "";
    gender = false;
    idNumber = 0;
    year = month = day = 0;
    phoneNumber = 0;
    major = "";
    mail = "";
}

studentBirthday &studentBirthday::operator=(const int &null) {
    studentBirthday nullStudent;
    this->name = nullStudent.name;
    this->gender = nullStudent.gender;
    this->idNumber = nullStudent.idNumber;
    this->year = nullStudent.year;
    this->month = nullStudent.month;
    this->day = nullStudent.day;
    this->phoneNumber = nullStudent.phoneNumber;
    this->major = nullStudent.major;
    this->mail = nullStudent.mail;
    return *this;
}

bool studentBirthday::operator>(const studentBirthday &after) const {
    if (this->isEmpty())
        return false;
    else if (after.isEmpty())// The latter is empty while the former is not.
        return true;

    if (this->month > after.month)
        return true;
    else if (this->month < after.month)
        return false;
    return this->day > after.day;
}

bool studentBirthday::operator<(const studentBirthday &after) const {
    return !(*this > after || this->isSameDay(after));
}

bool studentBirthday::operator==(const studentBirthday &another) {
    return this->name == another.name &&
           this->gender == another.gender &&
           this->idNumber == another.idNumber &&
           this->year == another.year &&
           this->month == another.month &&
           this->day == another.day &&
           this->phoneNumber == another.phoneNumber &&
           this->major == another.major &&
           this->mail == another.mail;
}

bool studentBirthday::isSameDay(const studentBirthday &another) const {
    return this->month == another.month && this->day == another.day;
}

bool studentBirthday::isEmpty() const {
    auto *emptyStudent = new studentBirthday;
    return (studentBirthday) *this == *emptyStudent;
}

string studentBirthday::getName() const {
    return this->name;
}

uint studentBirthday::getMonth() const {
    return this->month;
}

uint studentBirthday::getDay() const {
    return this->day;
}

int studentBirthday::daysToBirthday() const {
    if (this->isEmpty())return NULL;

    int days;
    time_t time_seconds = time(nullptr);
    struct tm now_time{};
    localtime_s(&now_time, &time_seconds);

    days = (int) daysPassed((uint) now_time.tm_year + 1900, this->getMonth(), this->getDay()) -
           (int) daysPassed((uint) now_time.tm_year + 1900, (uint) now_time.tm_mon + 1, (uint) now_time.tm_mday);

    if (days < 0) {
        if (isLeapYear((uint) now_time.tm_year + 1900 + 1))
            days += 366;
        else
            days += 365;
    }
    return days;
}







