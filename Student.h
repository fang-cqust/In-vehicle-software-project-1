#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string studentId;
    std::string name;

    // �������Ĺ��캯��
    Student(const std::string& id, const std::string& name);
};

#endif // STUDENT_H