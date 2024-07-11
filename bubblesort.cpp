#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void display(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Display the sorting process with ASCII art
        std::cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < arr.size(); ++k) {
            std::cout << arr[k] << " ";
            if (k == n - i - 2 && swapped) {
                std::cout << "< "; // Arrow to indicate the swapped elements
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay for visualization
        system("clear"); // Clear console (Linux/macOS)
        //system("cls"); // For Windows

        if (!swapped) break; // If no swapping occurred, the array is already sorted
    }
}

int main() {
    std::vector<int> array = {5, 3, 8, 6, 2, 7, 1, 4};
    std::cout << "Initial Array:" << std::endl;
    display(array);
    std::cout << "Sorting Process:" << std::endl;
    bubbleSort(array);
    std::cout << "Sorted Array:" << std::endl;
    display(array);

    return 0;
}
