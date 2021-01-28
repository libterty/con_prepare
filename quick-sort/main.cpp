#include <iostream>

// 10 80 30 90 40 50 70 -> i = -1, j = 0, pivot = 70 這時候arr[j](10) < pivot，i++，但arr[i] = arr[j]沒意義，j++ -> i = 0, j = 1
// 10 80 30 90 40 50 70 -> i = 0, j = 1, pivot = 70 這時候arr[j](80) > pivot，j++ -> i = 0, j = 2
// 10 80 30 90 40 50 70 -> i = 0, j = 2, pivot = 70 這時候arr[j](30) < pivot，i++，並swap後，j++ -> i = 1, j = 3
// 10 30 80 90 40 50 70 -> i = 1, j = 3, pivot = 70 這時候arr[j](90) > pivot，j++ -> i = 1, j = 4
// 10 30 80 90 40 50 70 -> i = 1, j = 4, pivot = 70 這時候arr[j](40) < pivot，i++，並swap後，j++ -> i = 2, j = 4
// 10 30 40 90 80 50 70 -> i = 2, j = 4, pivot = 70 這時候arr[j](80) > pivot，j++
// 10 30 40 90 80 50 70 -> i = 2, j = 5, pivot = 70 這時候arr[j](50) < pivot，j++，並swap後，j++ -> i = 3, j = 5
// 10 30 40 50 80 90 70 -> i = 3, j = 6, 跳出迴圈換高位
// 10 30 40 50 70 90 80 -> return i + 1


using namespace std;

void swap(int *low, int *high) {
  int temp = *low;
  *low = *high;
  *high = temp;
};

void printSort(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
      printSort(arr, 7);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  printSort(arr, 7);
  return (i + 1);
};

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
};

int main() {
  int arr[] = {10, 80, 30, 90, 40, 50, 70};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  return 0;
}