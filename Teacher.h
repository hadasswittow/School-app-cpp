//
// Created by hadasswittow on 9/19/19.
//
#pragma once
#ifndef SCHOOLEXE_TEACHER_H
#define SCHOOLEXE_TEACHER_H

#include <iostream>
#include "Person.h"

class Teacher: public Person {
public:
    Teacher(const MyString& name, const MyString& lesson):Person(name),m_lesson(lesson){};
    /*virtual*/void action();
    const MyString& getLesson();
private:
    MyString m_lesson;
};
inline const MyString& Teacher::getLesson() {
    return m_lesson;
}
inline void Teacher::action() {
    std::cout<<"Hi teacher! you are teaching lesson "<<m_lesson<<std::endl;
}

#endif //SCHOOLEXE_TEACHER_H
