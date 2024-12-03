#include <iostream>
using namespace std;
int partition(int *arr, int low, int high) {
    int i = low;
    int pivot = arr[low];
    int j = high;  // high is inclusive here
    
    while (i < j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    
    return j;
}
void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        QuickSort(arr, low, j - 1);  // Left side of pivot
        QuickSort(arr, j + 1, high); // Right side of pivot
    }
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 7;
    int *arr = new int[n]{10, 5, 9, 6, 24, 15, 8};
    print(arr, n);
    QuickSort(arr, 0, n - 1);  // n - 1 because high is inclusive
    print(arr, n);
    return 0;
}
