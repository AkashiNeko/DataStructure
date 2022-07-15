#pragma once

#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//交换
#define Swap(a, b) (void)(a = (a) ^ (b), b = (a) ^ (b), a = (a) ^ (b))

//排序顺序
#define SYM <

//交换条件
//#define Compare(a, b) ((a) SYM (b)) && 

void InsertionSort(int* arr, int size);

#endif