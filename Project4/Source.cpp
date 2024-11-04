#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// Пузырьковая сортировка
void bubbleSort(vector<int>& arr) {
	// Комментарий: Пузырьковая сортировка
	int n = arr.size();
	for (int i = 0; i <
        n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Сортировка вставкой
void insertionSort(vector<int>& arr) {
    // Комментарий: Сортировка вставкой
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Сортировка слиянием
void mergeSort(vector<int>& arr, int left, int right) {
    // Комментарий: Сортировка слиянием
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr.begin() + left, arr.begin() + mid + 1, arr.begin() + mid + 1, arr.begin() + right + 1, arr.begin() + left);
    }
}

// Функция для печати массива
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Основная функция
int main() {
    vector<int> arr1 = { 5, 2, 4, 6, 1, 3 };
    vector<int> arr2 = { 10, 7, 8, 9, 1, 5 };
    vector<int> arr3 = { 3, 7, 8, 5, 2, 1, 9, 4, 6 };

    // Сортировка массива пузырьковой сортировкой
    cout << "Массив 1 (Пузырьковая сортировка):" << endl;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Время сортировки: " << duration.count() << " микросекунд" << endl;
    printArray(arr1);

    // Сортировка массива сортировкой вставкой
    cout << "Массив 2 (Сортировка вставкой):" << endl;
    start = chrono::high_resolution_clock::now();
    insertionSort(arr2);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Время сортировки: " << duration.count() << " микросекунд" << endl;
    printArray(arr2);

    // Сортировка массива сортировкой слиянием
    cout << "Массив 3 (Сортировка слиянием):" << endl;
    start = chrono::high_resolution_clock::now();
    mergeSort(arr3, 0, arr3.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Время сортировки: " << duration.count() << " микросекунд" << endl;
    printArray(arr3);

    return 0;
}
