#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void display(const std::vector<int>& arr, int left, int right, int pivot) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i == pivot) {
            std::cout << " P ";
        } else if (i >= left && i <= right) {
            std::cout << " | ";
        } else {
            std::cout << "   ";
        }
    }
    std::cout << std::endl;

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        system("clear"); // Clear console (Linux/macOS)
        //system("cls"); // For Windows

        std::cout << "Partitioning: (Pivot: " << arr[pivotIndex] << ")" << std::endl;
        display(arr, low, high, pivotIndex);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay for visualization

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> array = {5, 3, 8, 6, 2, 7, 1, 4};
    std::cout << "Initial Array:" << std::endl;
    display(array, 0, array.size() - 1, -1); // Display with no partition initially
    std::cout << "Sorting Process:" << std::endl;
    quickSort(array, 0, array.size() - 1);
    std::cout << "Sorted Array:" << std::endl;
    display(array, 0, array.size() - 1, -1); // Display the sorted array
    return 0;
}
