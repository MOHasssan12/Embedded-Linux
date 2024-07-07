#include<iostream>
using namespace std;

int func(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int* callbackfunc(int** arr_2d, int size, int* row_size, int (*func)(int*, int)) {
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = func(arr_2d[i], row_size[i]);
    }
    return result;
}

int main() {
    int arr_2d[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };


    int row_sizes[3] = {4, 4, 4};

    
    int* ptr_2d[3];
    for (int i = 0; i < 3; i++) {
        ptr_2d[i] = arr_2d[i];  
    }


    int* result = callbackfunc(ptr_2d, 3, row_sizes, func);

  
    for (int i = 0; i < 3; i++) {
        cout << "Sum of array " << i + 1 << ": " << result[i] << endl;
    }

    
    delete[] result;

    return 0;
}
