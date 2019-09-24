//
// Created by hadasswittow on 9/15/19.
//

#include "stringFunctions.h"

size_t strlen(const char *str) {
    const char *ptr = str;
    while (*ptr++);
    return ptr - str - 1;
}

void strcopy(char *dst, const char *src) {
    while ((*dst++ = *src++));
}

void strncopy(char *dst, const char *src, size_t size){
    while (size) {
        *dst++ = *src++;
        --size;
    }
}

int strcompare(const char s1[], const char s2[]) {
    while (*s1 && *s1++ == *s2++);
    return *--s1 - *--s2;
}
void strCat(char *str1, char const *str2) {
    while (*str1++);
    --str1;
    strcopy(str1, str2);
}
