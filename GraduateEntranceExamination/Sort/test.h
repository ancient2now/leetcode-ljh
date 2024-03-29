#ifndef __TEST_H__
#define __TEST_H__

#define max_size 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern void BubbleSort(int arr[], int len);
extern void SelectSort(int arr[], int len);
extern void InsertSort(int arr[], int len);
extern void ShellSort(int arr[], int len);
extern void QuickSort(int arr[], int len);
extern void HeapSort(int arr[], int len);
extern void MergeSort(int arr[], int L, int R);

extern void ArrayPrint(int arr[], int len);

#endif