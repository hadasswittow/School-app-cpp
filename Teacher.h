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
    Teacher(const std::string& name, const std::string& lesson):Person(name),m_lesson(lesson){};
    /*virtual*/void action();
    const std::string& getLesson();
private:
    std::string m_lesson;
};
inline const std::string& Teacher::getLesson() {
    return m_lesson;
}
inline void Teacher::action() {
    std::cout<<"Hi teacher! you are teaching lesson "<<m_lesson<<std::endl;
}

#endif //SCHOOLEXE_TEACHER_H
