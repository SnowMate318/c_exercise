#ifndef __ARRAY_POINTER_H__
#define __ARRAY_POINTER_H__
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "array_pointer.h"

void f07_extra1(void);
void f07_extra2(void);
void f07_extra_3(void);
void f_arr_point_exercise(void);

#define size(a) (sizeof(a)/sizeof((a)[0]))
#endif