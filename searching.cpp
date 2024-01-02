#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Element not found
}

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int jumpSearch(int arr[], int size, int key) {
    int jump = sqrt(size);
    int left = 0;
    while (left < size && arr[left] <= key) {
        int right = min(left + jump, size) - 1;
        if (arr[right] >= key) {
            for (int i = left; i <= right; ++i) {
                if (arr[i] == key) {
                    return i;
                }
            }
        }
        left += jump;
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Sample sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice, key, result;
    char cont;

    do {
        cout << "Choose the search algorithm:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Jump Search\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << "Enter the element to search: ";
        cin >> key;

        switch (choice) {
            case 1:
                result = linearSearch(arr, size, key);
                break;
            case 2:
                result = binarySearch(arr, size, key);
                break;
            case 3:
                result = jumpSearch(arr, size, key);
                break;
            default:
                cout << "Invalid choice!";
                return 1;
        }

        if (result != -1) {
            cout << "Element found at index: " << result << endl;
        } else {
            cout << "Element not found!" << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}