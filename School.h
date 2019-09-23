//
// Created by hadasswittow on 9/19/19.
//
#pragma once

#ifndef SCHOOLEXE_SCHOOL_H
#define SCHOOLEXE_SCHOOL_H

using namespace std;
#include <vector>
#include <map>
#include <list>
#include "Teacher.h"
#include "Student.h"

typedef map<std::string,list<Student*> > schoolMap;
class School {
public:
    void addStudent(Student* student);
    void addTeacher(Teacher* teacher);
    size_t getNumOfStudents() const;
    size_t getNumOfTeachers() const;
    void pairTeacherToStudent(size_t ratio);
    std::list<Student*> getTeacherStudents(const std::string& teacherName) const ;
private:
    vector<Student*> m_students;
    vector<Teacher*> m_teachers;
    mutable schoolMap m_teachersAndStudents;


};


inline size_t School::getNumOfStudents() const{
    return m_students.size();
}
inline size_t School::getNumOfTeachers() const{
    return m_teachers.size();
}
inline std::list<Student*> School::getTeacherStudents(const std::string& teacherName) const {
    return m_teachersAndStudents[teacherName];
}
#endif //SCHOOLEXE_SCHOOL_H
