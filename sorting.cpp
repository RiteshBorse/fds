/*
 All Sorting algorithms in one code
 */

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void bucketSort(int arr[], int n) {
    const int maxVal = *max_element(arr, arr + n);
    const int minVal = *min_element(arr, arr + n);

    const int bucketRange = 10;
    const int numBuckets = (maxVal - minVal) / bucketRange + 1;

    int buckets[numBuckets][n];
    int bucketCounts[numBuckets];
    for (int i = 0; i < numBuckets; ++i) {
        bucketCounts[i] = 0;
    }


    for (int i = 0; i < n; ++i) {
        int bucketIndex = (arr[i] - minVal) / bucketRange;
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        insertionSort(buckets[i], bucketCounts[i]);
        for (int j = 0; j < bucketCounts[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

void countingSort(int arr[], int n, int exp) {
    int output[n], count[10] = {0};

    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;
    cout << "Enter the sorting algorithm choice:\n";
    cout << "1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Quick Sort\n";
    cout << "5. Shell Sort\n6. Bucket Sort\n7. Radix Sort\n8. Merge Sort\n";

    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            break;
        case 5:
            shellSort(arr, n);
            break;
        case 6:
            bucketSort(arr, n);
            break;
        case 7:
            radixSort(arr, n);
            break;
        case 8:
            mergeSort(arr, 0, n - 1);
            break;
        default:
            cout << "Invalid choice!";
            break;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}