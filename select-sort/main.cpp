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

void selectSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[index]) {
        index = j;
      }
    }

    if (index != i) {
      swap(&arr[i], &arr[index]);
    }
  }
};

int main() {
  int arr[] = {10, 80, 30, 90, 40, 50, 70};
  int n = sizeof(arr)/sizeof(arr[0]);
  selectSort(arr, n);
  printSort(arr, n);
  return 0;
}