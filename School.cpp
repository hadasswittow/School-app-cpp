//
// Created by hadasswittow on 9/19/19.
//
#include "School.h"


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
        m_teachersAndStudents[(*teacher_it)->getId()]=temp;
        temp.clear();
    }
}
void School::removeStudent(size_t student_id){

    std::list<Student*>::iterator student_list_it;
    for (schoolMap::iterator it = m_teachersAndStudents.begin(); it != m_teachersAndStudents.end(); ++it)
    {
        std::list<Student*> lst=it->second;
        student_list_it=lst.begin();
        while(student_list_it!=lst.end()){
            if((*student_list_it)->getId()==student_id){
                it->second.erase(student_list_it);
            }
            ++student_list_it;
        }/**
        for(;student_list_it!=lst.end();student_list_it++){
            if((*student_list_it)->getId()==student_id){
                it->second.erase(student_list_it);
            }
        }*/
    }
    std::vector<Student*>::iterator student_it = m_students.begin();

    for(;student_it!=m_students.end();++student_it){
        if((*student_it)->getId()==student_id){
            m_students.erase(student_it);
        }
    }

}
void School::removeTeacher(size_t teacher_id){
    std::vector<Teacher*>::iterator teacher_it = m_teachers.begin();
    for(;teacher_it!=m_teachers.end();++teacher_it){
        if((*teacher_it)->getId()==teacher_id){
            m_teachers.erase(teacher_it);
        }
    }
    m_teachersAndStudents.erase(teacher_id);
}