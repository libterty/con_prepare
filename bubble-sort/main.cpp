#include <iostream>

using namespace std;

void printSort(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
};

void swap(int *low, int *high) {
  int temp = *low;
  *low = *high;
  *high = temp;
};

void bubbleSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
};

int main() {
  int arr[] = {10, 80, 30, 90, 40, 50, 70};
  int n = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, n - 1);
  printSort(arr, n);
  return 0;
}