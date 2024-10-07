#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string studentId;
    std::string name;

    // 带参数的构造函数
    Student(const std::string& id, const std::string& name);
};

#endif // STUDENT_H