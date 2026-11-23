#define _CRT_SECURE_NO_WARNINGS
#define N_MAX 10000

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "array.h"
#include "sorts.h"

int main() {

    // Установка кодировки UTF-8 для консоли
    //SetConsoleOutputCP(65001);
    //SetConsoleCP(65001);

    int size = 100;
    int min = 1;
    int max = 1000;
    int arr[N_MAX], arrSort[N_MAX]; //размер был size
    int swap_count;
    clock_t time1, time2;
    float t_sec;
    FILE* fp;

    char sort1[] = "sort1.txt";
    char sort2[] = "sort2.txt";
    char sort3[] = "sort3.txt";
    char sort4[] = "sort4.txt";
    char sort5[] = "sort5.txt";

    fp = fopen(sort1, "w");

    if (fp == NULL) {
        printf("File not open! %s", sort1);
        return 1;
    }

    //fillArray(arr, size, min, max);
    fillRandomArray(arr, size);
    copyArray(arr, arrSort, size);

    if (size < 30) {
        printf("Исходный массив: \n");
        printArray(arr, size);
    }

    //////////////////////////////////////////////////
    // сортировка пузырьком
    
    copyArray(arr, arrSort, size);

    time1 = clock();

    // swap_count - исходящий параметр (то есть получим его назад из функции)
    bubbleSort(arrSort, size, &swap_count, fp);
    fclose(fp);

    time2 = clock();
    t_sec = ((float)(time2 - time1)) / CLOCKS_PER_SEC;
    //float t_sec = ((float) (time2-time1))/1000;

    printf("Отсортированный массив (bubbleSort, количество перестановок = %d, время = %f сек): \n", swap_count, t_sec);
    if (size < 30) {
        printArray(arrSort, size);
    }

    //////////////////////////////////////////////////
    // шейкерная сортировка 
    
    fp = fopen(sort2, "w");

    if (fp == NULL) {
        printf("File not open! %s", sort2);
        return 1;
    }
    
    copyArray(arr, arrSort, size);
    

    time1 = clock();

    swap_count = 0;
    // swap_count - исходящий параметр (то есть получим его назад из функции)
    shakerSort(arrSort, size, &swap_count, fp);
    fclose(fp);

    time2 = clock();
    t_sec = ((float)(time2 - time1)) / CLOCKS_PER_SEC;

    printf("Отсортированный массив (shakerSort, количество перестановок = %d, время = %f сек): \n", swap_count, t_sec);
    if (size < 30) {
        printArray(arrSort, size);
    }

    //////////////////////////////////////////////////
    // сортировка слиянием 

    fp = fopen(sort3, "w");

    if (fp == NULL) {
        printf("File not open! %s", sort3);
        return 1;
    }

    copyArray(arr, arrSort, size);

    time1 = clock();

    swap_count = 0;
    // swap_count - исходящий параметр (то есть получим его назад из функции)
    mergeSort(arrSort, 0, size - 1, &swap_count, fp);
    //mergeSort(arrSort, 0, size-1);
    fclose(fp);

    time2 = clock();
    t_sec = ((float)(time2 - time1)) / CLOCKS_PER_SEC;

    printf("Отсортированный массив (mergeSort, количество перестановок = %d, время = %f сек): \n", swap_count, t_sec);
    if (size < 30) {
        printArray(arrSort, size);
    }

    //////////////////////////////////////////////////
    // сортировка простыми вставками
    fp = fopen(sort4, "w");

    if (fp == NULL) {
        printf("File not open! %s", sort4);
        return 1;
    }

    copyArray(arr, arrSort, size);

    time1 = clock();

    swap_count = 0;
    // swap_count - исходящий параметр (то есть получим его назад из функции)
    insertionSort(arrSort, size, &swap_count, fp);
    fclose(fp);

    time2 = clock();
    t_sec = ((float)(time2 - time1)) / CLOCKS_PER_SEC;
    //float t_sec = ((float) (time2-time1))/1000;

    printf("Отсортированный массив (insertionSort, количество перестановок = %d, время = %f сек): \n", swap_count, t_sec);
    if (size < 30) {
        printArray(arrSort, size);
    }

    //////////////////////////////////////////////////
    // сортировка Шелла
    fp = fopen(sort5, "w");

    if (fp == NULL) {
        printf("File not open! %s", sort5);
        return 1;
    }

    copyArray(arr, arrSort, size);

    time1 = clock();

    swap_count = 0;
    // swap_count - исходящий параметр (то есть получим его назад из функции)
    shellSort(arrSort, size, &swap_count, fp);
    fclose(fp);

    time2 = clock();
    t_sec = ((float)(time2 - time1)) / CLOCKS_PER_SEC;
    //float t_sec = ((float) (time2-time1))/1000;

    printf("Отсортированный массив (shellSort, количество перестановок = %d, время = %f сек): \n", swap_count, t_sec);
    if (size < 30) {
        printArray(arrSort, size);
    }

    return 0;
}
