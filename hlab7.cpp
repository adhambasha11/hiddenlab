using namespace std;
#include <iostream>
int main() {
    int size = 0;
    cout << "Enter the number of values you want to be sorted: ";
    cin >> size;

    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << " value ";
        cin >> array[i];
    }

    cout << "Before Quick Sort: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    quickSort(array, 0, size - 1);
    cout << endl;

    cout << "After Quick Sort: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
int partition(int arr[], int low, int high) {
    int middle = low + (high - low) / 2;
    int pi;
    if ((high > middle) && (high > low))
        pi = high;
    else if ((middle < high) && (middle < low))
        pi = middle;
    else
        pi = low;



    int pivot = arr[pi];    //sets pivot to the element at the pivotIndex
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  //checks if current element is smaller than the pivot element

            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pi]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {    //Quicksort function 
    if (low < high) {
        int piIndex = partition(arr, low, high);
        quickSort(arr, low, piIndex - 1);  //before pivot
        quickSort(arr, piIndex + 1, high);  //after pivot
    }
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}


