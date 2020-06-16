//
// Created by Administrator on 2020/6/15.
//

#include <iostream>

using namespace std;

namespace function {
    static unsigned int
            monthLeap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            monthNonLeap[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    static int numOfChar(string str, char ch);

    static unsigned long long parseLongLong(string str);

    static bool isDigit(const string &ch);

    static bool isDigit(const char &ch);

    static int parseDigit(const string &ch);

    static int parseDigit(const char &ch);

    static char charAt(const string &str, int pos);

    static bool isLeapYear(unsigned int year);

    static string &replaceString(string &str, const string &old_value, const string &new_value);

    static string *splitString(string str, const string &splitAt);

    static unsigned int daysPassed(unsigned int year, unsigned int month, unsigned int days);

    int numOfChar(string str, char ch) {
        int num = 0;
        int k = str.find(ch);
        while (k >= 0) {
            num++;
            str = str.substr(str.find(ch) + 1);
            k = str.find(ch);
        }
        return num;
    }

    unsigned long long parseLongLong(string str) {
        unsigned long long phone = 0;
        while (!str.empty()) {
            char ch = charAt(str, 1);
            if (isDigit(ch)) {
                phone = phone * 10 + parseDigit(ch);
                str = str.substr(1);
            } else
                return NULL;
        }
        return phone;
    }

    bool isDigit(const string &ch) {
        if (ch.length() != 1)
            return false;
        return isDigit(charAt(ch, 1));
    }

    int parseDigit(const string &ch) {
        if (isDigit(ch))
            return charAt(ch, 1) - '0';
        else
            return -1;
    }

    char charAt(const string &str, int pos) {
        char *digit = new char;
        strcpy_s(digit,
                 str.length() + 1,
                 str.substr((const unsigned int) pos - 1, (const unsigned int) pos).c_str());
//        strcpy(digit, str.substr(pos - 1, pos).c_str());
        return *digit;
    }

    bool isDigit(const char &ch) {
        return ch >= '0' && ch <= '9';
    }

    int parseDigit(const char &ch) {
        if (isDigit(ch))
            return ch - '0';
        else
            return -1;
    }

    bool isLeapYear(unsigned int year) {
        return year % 400 == 0 || (year % 400 != 0 && year % 4 == 0);
    }

    static string &replaceString(string &str, const string &old_value, const string &new_value) {
        for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
            if ((pos = str.find(old_value, pos)) != string::npos)
                str.replace(pos, old_value.length(), new_value);
            else break;
        }
        return str;
    }

    static string *splitString(string str, const string &splitAt) {
        if (str.find(splitAt) == -1)return nullptr;

        string newStr = str;
        unsigned int num = 0;
        do {
            num++;
            newStr = newStr.substr(newStr.find(splitAt) + splitAt.length());
        } while (newStr.find(splitAt) != -1);

        auto *stringArray = new string[num + 1];
        for (int i = 0; i <= num; i++) {
            stringArray[i] = str.substr(0, str.find(splitAt));
            if (str.empty()) {
                break;
            }
            str = str.substr(str.find(splitAt) + splitAt.length());
        }

        return stringArray;
    }

    unsigned int daysPassed(unsigned int year, unsigned int month, unsigned int days) {
        if (month <= 0 || month >= 13 || days <= 0 || days >= 32)return 366;

        unsigned int daysPassed = 0;
        for (int i = 1; i < month; i++) {
            if (i == 2 && isLeapYear(year)) {
                daysPassed += monthLeap[i - 1];
                continue;
            }
            daysPassed += monthNonLeap[i - 1];
        }
        return (daysPassed + days);
    }
}