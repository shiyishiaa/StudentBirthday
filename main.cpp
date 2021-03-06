#include <iostream>
#include <string>
#include <fstream>
#include "StudentBirthday.h"
#include "List.h"

using namespace std;
using namespace function;

List<StudentBirthday> readText(const string &filePath);

void printBirth(List<StudentBirthday> studentList);

StudentBirthday nextBirthday(List<StudentBirthday> studentList);

int main(int argc, char *argv[]) {
    if (argc != 2)
        printf("空文件\n");
    else {
        /**
         * 数据格式：
         * 姓名,身份证号码,专业,电话号码,邮箱
         * 所有逗号均为西文符号
         */
        string filePath = argv[1];
        filePath = replaceString(filePath, "\\", "\\\\");
        List<StudentBirthday> studentList = readText(filePath);
        printBirth(studentList);
        cout << "下一个过生日的人是：" << nextBirthday(studentList).getName() << endl;
    }
    return 0;
}

List<StudentBirthday> readText(const string &filePath) {
    List<StudentBirthday> studentList;
    ifstream inFile(filePath);
    if (inFile.is_open()) {
        string nowLine;
        while (getline(inFile, nowLine)) {
            StudentBirthday newStudent(nowLine);
            for (uint posi = 1;; posi++) {
                if (newStudent < studentList[posi - 1]
                    || posi - 1 == studentList.getSize()
                    || studentList.isEmpty()) {
                    studentList.insert(newStudent, posi);
                    break;
                }
            }
        }
    }
    inFile.close();
    return studentList;
}

void printBirth(List<StudentBirthday> studentList) {
    for (int i = 0; i < studentList.getSize(); i++) {
        StudentBirthday nowStudent = studentList[i];
        cout << nowStudent.getName() << "的生日是" << nowStudent.getMonth() << "月"
             << nowStudent.getDay() << "日，";
        cout << "还有" << nowStudent.daysToBirthday() << "天" << endl;
    }
}

StudentBirthday nextBirthday(List<StudentBirthday> studentList) {
    int index = -1, minDays = 366;
    for (int i = 0; i < studentList.getSize(); i++) {
        if (studentList[i].daysToBirthday() < minDays) {
            minDays = studentList[i].daysToBirthday();
            index = i;
        }
    }
    return studentList[index];
}