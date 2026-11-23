#ifndef SORTS_H
#define SORTS_H

void saveIteration(int arr[], int size, FILE* fp);
void bubbleSort(int arr[], int n, int* swap_count, FILE* fp);
void shakerSort(int arr[], int n, int* swap_count, FILE* fp);
void mergeSort(int arr[], int il, int ir, int* swap_count, FILE* fp);
void insertionSort(int arr[], int n, int* swap_count, FILE* fp);
void shellSort(int arr[], int n, int* swap_count, FILE* fp);

#endif
