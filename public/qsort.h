#ifndef QSORT_H
#define QSORT_H
#include <stdio.h>

void qsort_helper(int* arr, int start, int end) {
  if (start >= end) {
    return;
  }
  int low = start;
  int high = end;
  int pivot = arr[start+(end-start)/2];
  arr[start+(end-start)/2] = arr[low];
  while (low < high) {
    while (low < high && arr[high] > pivot) {
      high--;
    }
    if (low < high) {
      arr[low] = arr[high];
      low++;
    }
    while (low < high && arr[low] < pivot) {
      low++;
    }
    if (low < high) {
      arr[high] = arr[low];
      high--;
    }
  }
  arr[low] = pivot;
  
  qsort_helper(arr, start, low - 1);
  qsort_helper(arr, low + 1, end);
}

void qsort(int* arr, int size) {
  qsort_helper(arr, 0, size - 1);
}

#ifdef DEBUG
int _qs_tester() {
  int arr[] = {4,2,3,5,6};
  qsort(arr, 5);
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
#endif

#endif