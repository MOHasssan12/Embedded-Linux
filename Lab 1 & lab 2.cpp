#include <iostream>
#include <cstring>
using namespace std;

typedef struct arr_strings {
    char** strings;
    int size;
    int capacity;
} arr_strings;

char** init(int num) {
    char** strings = new char*[num];
    for (int i = 0; i < num; i++) {
        strings[i] = new char[100];
        cout << "Please enter name " << (i + 1) << ": " << endl;
        cin >> strings[i];
    }
    return strings;
}

char** insert(int index, const char* name, arr_strings& arr) {
    if (arr.size >= arr.capacity) {
        int size = arr.capacity * 2;
        char** newstrings = new char*[size];
        for (int i = 0; i < size; i++) {
            newstrings[i] = new char[100];
        }
        for (int i = 0, j = 0; i < arr.size + 1; i++) {
            if (i == index) {
                strcpy(newstrings[i], name);
            } else {
                strcpy(newstrings[i], arr.strings[j]);
                j++;
            }
        }

        for (int i = 0; i < arr.capacity; i++) {
            delete[] arr.strings[i];
        }
        delete[] arr.strings;

        arr.strings = newstrings;
        arr.capacity = size;
    } else {
        for (int i = arr.size; i > index; i--) {
            strcpy(arr.strings[i], arr.strings[i - 1]);
        }
        strcpy(arr.strings[index], name);
    }

    arr.size++;
    return arr.strings;
}

void PrintNames(const arr_strings& arr) {
    cout << "Entered names are:" << endl;
    for (int i = 0; i < arr.size; i++) {
        cout << arr.strings[i] << endl;
    }
}

void check_bound(int index, const arr_strings& arr) {
    if (index < arr.size) {
        cout << "Within boundaries" << endl;
    } else {
        cout << "Out of boundaries" << endl;
    }
}

void delet(int index, arr_strings& arr) {
    if (index < arr.size) {
        for (int i = index; i < arr.size - 1; i++) {
            strcpy(arr.strings[i], arr.strings[i + 1]);
        }
        arr.size--;
    } else {
        cout << "Index out of range" << endl;
    }
}

int main() {
    arr_strings names;
    cout << "Please enter number of names" << endl;
    cin >> names.size;
    names.capacity = names.size;
    names.strings = init(names.size);

    PrintNames(names);

    int index;
    char name[100];
    cout << "Please enter index of the name " << endl;
    cin >> index;
    cout << "Please enter the name " << endl;
    cin >> name;
    names.strings = insert(index, name, names);
    PrintNames(names);

    cout << "Please enter index to delete " << endl;
    cin >> index;
    delet(index, names);
    PrintNames(names);

   
    for (int i = 0; i < names.capacity; i++) {
        delete[] names.strings[i];
    }
    delete[] names.strings;

    return 0;
}

