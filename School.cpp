//
// Created by hadasswittow on 9/19/19.
//
#include "School.h"


void School::pairTeacherToStudent(size_t ratio){
    if(ratio>m_students.size())
        throw std::invalid_argument("ratio is bigger than theamount of students ");
    if(m_teachers.size()*ratio<m_students.size())
        throw std::logic_error("there are too few teachers!! not all students will have a teacher");
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
    std::vector<Student*>::iterator student_it = m_students.begin();
    bool flag=false;
    for(;student_it!=m_students.end();++student_it){
        if((*student_it)->getId()==student_id){
            m_students.erase(student_it);
            flag=true;
            break;
        }
    }
    if(!flag)
        throw std::invalid_argument("You are trying to remove a student that is not in this school...");
    std::list<Student*>::iterator student_list_it;
    for (schoolMap::iterator it = m_teachersAndStudents.begin(); it != m_teachersAndStudents.end(); ++it)
    {
        student_list_it=(it->second).begin();
        while(student_list_it!=it->second.end()){
            if((*student_list_it)->getId()==student_id){
                it->second.erase(student_list_it);
                break;
            }

            ++student_list_it;
        }
    }


}
void School::removeTeacher(size_t teacher_id){
    bool flag=false;
    std::vector<Teacher*>::iterator teacher_it = m_teachers.begin();
    for(;teacher_it!=m_teachers.end();++teacher_it){
        if((*teacher_it)->getId()==teacher_id){
            m_teachers.erase(teacher_it);
            flag=true;
            break;
        }
    }
    if(!flag)
        throw std::invalid_argument("You are trying to remove a teacher that is not in this school...");
    m_teachersAndStudents.erase(teacher_id);
}