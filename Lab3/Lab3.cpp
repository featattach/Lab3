#include <iostream>
#include <conio.h>
#include <algorithm>

// Функция сортировки методом "мини-макс"
void minmaxSort(int arr[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        int minIdx = i;
        int maxIdx = i;
        for (int j = i + 1; j < n - i; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
        if (maxIdx == i) maxIdx = minIdx;
        std::swap(arr[n - i - 1], arr[maxIdx]);
    }
}

// Функция сортировки методом "пузырька"
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Вспомогательная функция для быстрой сортировки
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция сортировки подмассива по возрастанию
void sortSubarrayAscending(int arr[], int N1, int N2) {
    std::sort(arr + N1, arr + N2 + 1);
}

// Функция сортировки подмассива по убыванию
void sortSubarrayDescending(int arr[], int N1, int N2) {
    std::sort(arr + N1, arr + N2 + 1, std::greater<int>());
}

int main() {
    int mas[] = { 12, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int);

    std::cout << "Original array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    // Minmax sort
    minmaxSort(mas, n);
    std::cout << "Sorted array with minmax sort:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    // Reset array to original
    int mas1[] = { 12, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };

    // Bubble sort
    bubbleSort(mas1, n);
    std::cout << "Sorted array with bubble sort:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << mas1[i] << " ";
    }
    std::cout << std::endl;

    // Reset array to original
    int mas2[] = { 12, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };

    // Quick sort
    quickSort(mas2, 0, n - 1);
    std::cout << "Sorted array with quick sort:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << mas2[i] << " ";
    }
    std::cout << std::endl;

    // Sort subarray ascending
    int N1 = 2, N2 = 8; // Example indices for the subarray
    int mas3[] = { 12, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    sortSubarrayAscending(mas3, N1, N2);
    std::cout << "Array after sorting subarray [" << N1 << ", " << N2 << "] in ascending order:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << mas3[i] << " ";
    }
    std::cout << std::endl;

    // Sort subarray descending
    int mas4[] = { 12, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    sortSubarrayDescending(mas4, N1, N2);
    std::cout << "Array after sorting subarray [" << N1 << ", " << N2 << "] in descending order:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << mas4[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
