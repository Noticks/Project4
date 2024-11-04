#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// ����������� ����������
void bubbleSort(vector<int>& arr) {
	// �����������: ����������� ����������
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

// ���������� ��������
void insertionSort(vector<int>& arr) {
    // �����������: ���������� ��������
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

// ���������� ��������
void mergeSort(vector<int>& arr, int left, int right) {
    // �����������: ���������� ��������
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr.begin() + left, arr.begin() + mid + 1, arr.begin() + mid + 1, arr.begin() + right + 1, arr.begin() + left);
    }
}

// ������� ��� ������ �������
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// �������� �������
int main() {
    vector<int> arr1 = { 5, 2, 4, 6, 1, 3 };
    vector<int> arr2 = { 10, 7, 8, 9, 1, 5 };
    vector<int> arr3 = { 3, 7, 8, 5, 2, 1, 9, 4, 6 };

    // ���������� ������� ����������� �����������
    cout << "������ 1 (����������� ����������):" << endl;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "����� ����������: " << duration.count() << " �����������" << endl;
    printArray(arr1);

    // ���������� ������� ����������� ��������
    cout << "������ 2 (���������� ��������):" << endl;
    start = chrono::high_resolution_clock::now();
    insertionSort(arr2);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "����� ����������: " << duration.count() << " �����������" << endl;
    printArray(arr2);

    // ���������� ������� ����������� ��������
    cout << "������ 3 (���������� ��������):" << endl;
    start = chrono::high_resolution_clock::now();
    mergeSort(arr3, 0, arr3.size() - 1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "����� ����������: " << duration.count() << " �����������" << endl;
    printArray(arr3);

    return 0;
}
