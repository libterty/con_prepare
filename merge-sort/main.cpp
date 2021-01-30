#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSort(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void merge(int *arr, int low, int mid, int high) {
  int temp[high + 1];
  // maximum of the left side arr
  int i = low;
  // minimum of the right side arr
  int j = mid + 1;
  int k = 0;

  while(i < mid && j <= high) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  while(j <= high) {
    temp[k++] = arr[j++];
  }
  k--;
  while(k >= 0) {
    arr[k + low] = temp[k];
    k--;
  }
}

void mergeSort(int *arr, int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}


int main() {
  int arr[] = {95, 45, 48, 98, 1, 485, 65, 478, 1, 2325};
  int n = sizeof(arr)/sizeof(arr[0]);
  mergeSort(arr, 0, n - 1);

  printSort(arr, n);

  return 0;
}