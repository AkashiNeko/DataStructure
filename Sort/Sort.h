#pragma once

#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����
#define Swap(a, b) (void)(a = (a) ^ (b), b = (a) ^ (b), a = (a) ^ (b))

//����˳��
#define SYM <

//��������
//#define Compare(a, b) ((a) SYM (b)) && 

void InsertionSort(int* arr, int size);

#endif