#pragma once

#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����˳��
// < ˳��
// > ����
#define SYM <

void InsertionSort(int* arr, int size);

void ShellSort(int* arr, int size);

void SelectionSort(int* arr, int size);

#endif