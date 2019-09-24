//
// Created by hadasswittow on 9/19/19.
//
#include "School.h"
#include "Tests.h"
#include <assert.h>
Student s1("a",1);
Student s2("b",2);
Student s3("c",3);
Student s4("d",4);
Student s5("e",5);
Student s6("f",6);
Student s7("g",7);
Student s8("h",8);
Teacher t1("T1","biology");
Teacher t2("T2","math");
Teacher t3("T3","english");
void test_creating_objects(){
    assert(s1.getId()==0);
    assert(s2.getId()==1);
    assert(s3.getName()=="c");
    assert(s4.getGrade()==4);
    assert(t1.getLesson()=="biology");

}
void test_exceptions(){
    try {
        //Student* stud=NULL;
        //school.addStudent(stud);
        //school.pairTeacherToStudent(15);
        school.removeStudent(40);

    }catch(const std::runtime_error& exception){
        std::cout<<"Runtime error: "<<exception.what();
    }catch(const std::invalid_argument& exception) {
        std::cout << "Invalid argument: " << exception.what();
    }catch(const std::logic_error& exception) {
        std::cout << "Logic error: " << exception.what();
    }
}
void test_school() {
    try {
        School school;
        school.addStudent(&s1);
        school.addStudent(&s2);
        school.addStudent(&s3);
        school.addStudent(&s4);
        school.addStudent(&s5);
        school.addStudent(&s6);
        school.addStudent(&s7);
        school.addStudent(&s8);
        school.addTeacher(&t1);
        school.addTeacher(&t2);
        school.addTeacher(&t3);

        assert(school.getNumOfStudents() == 8);
        assert(school.getNumOfTeachers() == 3);
        school.pairTeacherToStudent(3);

        school.removeTeacher(8);
        assert(school.getNumOfTeachers() == 2);

        school.removeStudent(4);
        assert(school.getNumOfStudents() == 7);

        //Student* stud=NULL;
        //school.addStudent(stud);
        list < Student * > lst = school.getTeacherStudents(9);
        list<Student *>::iterator it = lst.begin();
        while (it != lst.end()) {
            (*it++)->action();
        }
    }catch(const std::runtime_error& exception){
        std::cout<<"Runtime error: "<<exception.what();
    }catch(const std::invalid_argument& exception) {
        std::cout << "Invalid argument: " << exception.what();
    }catch(const std::logic_error& exception) {
        std::cout << "Logic error: " << exception.what();
    }
}