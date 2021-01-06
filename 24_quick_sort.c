#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quick sort
// Lomuto partition scheme
// Hoare partition scheme

void SwapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Shuffle(int *array, int length) {
    srand(time(NULL));
    for (int i = length-1; i > 0; ++i) {
        int random_number = rand() % i;
        SwapInt(array + i, array + random_number);
    }
}

int *Partition(int *low, int *high) {
    int pivot = *(low + (high - low) / 2);  // 防止地址溢出
    int *p = low;
    int *q = high;

    while (1) {
        while (*p < pivot) p++;
        while (*q > pivot) q--;

        if (p >=q) break;
        SwapInt(p, q);
    }

    return q;
}

void QuickSort(int *low, int *high) {
    if (low >= high) return;
    int *partition = Partition(low, high);
    QuickSort(low, partition-1);
    QuickSort(partition+1, high);
}
