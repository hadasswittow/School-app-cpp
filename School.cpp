//
// Created by hadasswittow on 9/19/19.
//
#include "School.h"

void School::addStudent(Student* student){
    if(student)
        m_students.push_back(student);
}
void School::addTeacher(Teacher* teacher){
    if(teacher)
        m_teachers.push_back(teacher);
}
void School::pairTeacherToStudent(size_t ratio){
    std::vector<Teacher*>::iterator teacher_it = m_teachers.begin();
    std::vector<Student*>::iterator student_it = m_students.begin();
    list<Student*> temp;
    for ( ; teacher_it != m_teachers.end(); ++teacher_it){
        for(size_t i=0;i<ratio;++i){
            if(student_it == m_students.end()) {
                student_it=m_students.begin();
            }
            temp.push_back(*student_it++);
        }
        m_teachersAndStudents[(*teacher_it)->getName()]=temp;
        temp.clear();
    }
}