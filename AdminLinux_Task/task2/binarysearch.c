#include <stdio.h>

int binary_search(int *arr, int size, int number) {

int left = 0;
int right = size - 1;

  while (left <= right) {

    int mid = left + (right - left) / 2;

    if (arr[mid] == number) {

      return mid;
    }

    if (arr[mid] < number) {

      left = mid + 1;

    } else {
      right = mid - 1;
    }
  }

return -1;
}

int main() {
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

int size = sizeof(arr) / sizeof(arr[0]);

int number = 7;
int index = binary_search(arr, size, number);
printf("%d\n", index);
return 0;
}
