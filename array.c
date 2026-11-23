#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "array.h"

int randomInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void fillArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = randomInRange(min, max);
    }
}

// Функция для заполнения массива от 1 до n в случайном порядке
void fillRandomArray(int* arr, int n) {
    // 1. Заполняем массив числами от 1 до n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // 2. Перемешиваем элементы (алгоритм Фишера — Йетса)
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Случайный индекс от 0 до i

        // Меняем местами arr[i] и arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void copyArray(int arr1[], int arr2[], int size) {
    // Поэлементное копирование
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

