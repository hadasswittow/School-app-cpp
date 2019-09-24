//
// Created by hadasswittow on 9/15/19.
//

#ifndef STRINGEXE_MYSTRING_H
#define STRINGEXE_MYSTRING_H

#include <iostream>
#include <cstddef>
#include "stringFunctions.h"
using std::ostream;
class MyString {

public:
    // constructor.
    MyString(const char *s = NULL);
    MyString(const MyString &s);
    ~MyString();

    // view function.
    char *getString() const;

    // operators
    MyString &operator=(const MyString &);
    void operator+=(const MyString & s);
    friend ostream& operator<<(ostream& os, const MyString& string);
    size_t length()const;
    // print
    void print() const;
private:
    char *str;
    void setString(const char *s);
};

//----------------------- constructor and destructor---------------------
inline MyString::MyString(const char *s) {
    setString(s);
}

inline MyString::MyString(const MyString &s) {
    setString(s.getString());
}

inline MyString::~MyString() {
    delete[] str;
    str = NULL;
}

//------------------------- get and set----------------------
inline char *MyString::getString() const {
    return str;
}

inline void MyString::setString(const char *s) {
    if (s) {
        size_t len = strlen(s) + 1;
        str = new char[len];
        strncopy(str, s, len);
    } else str = NULL;
}

///-------------------------------- operators---------------------------------------

inline ostream& operator<<(ostream& os, const MyString& string){
    os << string.str;
    return os;
}
inline MyString &MyString::operator=(const MyString &s) {
    if(this!=&s) {
        delete[] str;
        setString(s.getString());
    }
    return *this;
}


inline MyString operator+(const MyString &first,const MyString &second) {
    size_t mySize = strlen(first.getString());
    size_t otherSize = strlen(second.getString());
    char *temp = new char[mySize + otherSize + 1];
    strcopy(temp, first.getString());
    strCat(temp, second.getString());
    MyString x(temp);
    delete [] temp;
    return x;
}
inline void MyString::operator+=(const MyString &s) {
    MyString temp = *this + s;
    *this = temp;
}



inline MyString operator*(const MyString &s,const int num) {
    size_t len = strlen(s.getString());
    char *temp = new char[len * num + 1];
    for (int i = 0; i < num; i++)
        strncopy(temp + i * len, s.getString(), len + 1);
    MyString ans(temp);
    delete [] temp;
    return ans;
}

inline bool operator==(const MyString &first,const MyString &second) {
    return !strcompare(first.getString(), second.getString());
}

inline bool operator>(const MyString &first,const MyString &second) {
    return strcompare(first.getString(), second.getString()) > 0;
}

inline bool operator<(const MyString &first,const MyString &second) {
    return strcompare(first.getString(), second.getString()) < 0;
}

inline bool operator!=(const MyString &first,const MyString &second) {
    return (strcompare(first.getString(), second.getString()));
}

inline bool operator>=(const MyString &first,const MyString &second)  {
    return (strcompare(first.getString(), second.getString())) >= 0;
}

inline bool operator<=(const MyString &first,const MyString &second)  {
    return (strcompare(first.getString(), second.getString()) <= 0);
}

//-------------------- a few more functions----------------
inline void MyString::print() const {
    if (str) std::cout << str << std::endl;
}


inline size_t MyString::length() const {
    return strlen(str);
}
#endif //STRINGEXE_MYSTRING_H
