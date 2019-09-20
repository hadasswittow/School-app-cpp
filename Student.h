//
// Created by hadasswittow on 9/19/19.
//
#pragma once
#ifndef SCHOOLEXE_STUDENT_H
#define SCHOOLEXE_STUDENT_H

#include <iostream>
#include "Person.h"

class Student : public Person{
public:
    Student(const std::string& name, unsigned char grade):Person(name),m_grade(grade){};
    void action();
    unsigned char getGrade();
private:
    unsigned char m_grade;
};
inline unsigned char Student::getGrade(){
    return m_grade;
}
inline void Student::action(){
    std::cout << "Hey there " << m_name << "! you are in grade  " <<(int)m_grade<< std::endl;
}


#endif //SCHOOLEXE_STUDENT_H
