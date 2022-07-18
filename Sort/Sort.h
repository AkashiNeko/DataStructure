#pragma once

#ifndef __SORT_H__
#define __SORT_H__

#include <stdlib.h>
#include <assert.h>

//ÅÅĞòË³Ğò
// < Ë³Ğò
// > ÄæĞò
#define SYM <

void InsertionSort(int* arr, int size);

void ShellSort(int* arr, int size);

void SelectionSort(int* arr, int size);

void BubbleSort(int* arr, int size);

void QuickSort(int* arr, int size);

#endif