//
// Created by hadasswittow on 9/15/19.
//

#ifndef STRINGEXE_STRINGFUNCTIONS_H
#define STRINGEXE_STRINGFUNCTIONS_H
#include <cstddef>

size_t strlen(const char *str) ;
void strcopy(char *dst, const char *src) ;
void strncopy(char *dst, const char *src, size_t size);
int strcompare(const char s1[], const char s2[]) ;
void strCat(char *str1, char const *str2) ;
#endif //STRINGEXE_STRINGFUNCTIONS_H
