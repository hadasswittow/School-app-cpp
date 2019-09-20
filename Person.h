//
// Created by hadasswittow on 9/19/19.
//S

#ifndef SCHOOLEXE_PERSON_H
#define SCHOOLEXE_PERSON_H

#pragma once
#include <string>

class Person {
public:
    static size_t s_idCounter;
    Person(const std::string& _name);
    const std::string& getName();
    size_t getId();
    virtual void action()=0;
protected:
    size_t m_id;
    std::string m_name;

};

inline Person::Person(const std::string& _name):m_id(s_idCounter++),m_name(_name){}
inline const std::string& Person::getName(){
    return m_name;
}
inline size_t Person::getId(){
    return m_id;
}


#endif //SCHOOLEXE_PERSON_H
