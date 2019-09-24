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
#include <exception>

typedef map<size_t ,list<Student*> > schoolMap;
class School {
public:
    void addStudent(Student* student);
    void addTeacher(Teacher* teacher);
    size_t getNumOfStudents() const;
    size_t getNumOfTeachers() const;
    void pairTeacherToStudent(size_t ratio);
    void removeStudent(size_t student_id);
    void removeTeacher(size_t Teacher_id);
    std::list<Student*> getTeacherStudents(const size_t teacherName) const ;
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
inline std::list<Student*> School::getTeacherStudents(const size_t teacherName) const {
    if(m_teachersAndStudents.find(teacherName) == m_teachersAndStudents.end())
        throw std::runtime_error("no such teacher in the map!!");

    return m_teachersAndStudents[teacherName];
}
inline void School::addStudent(Student* student){
    if(!student)
       throw std::runtime_error("Student is null!");
    m_students.push_back(student);
}
inline void School::addTeacher(Teacher* teacher){
    if(!teacher)
        throw std::runtime_error("Teacher is null");
    m_teachers.push_back(teacher);
}

#endif //SCHOOLEXE_SCHOOL_H
