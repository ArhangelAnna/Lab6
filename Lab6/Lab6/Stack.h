#include <type_traits> // For std::is_integral
#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm> // For std::max_element
#include <cmath>     // For std::pow


template<typename T>
class Stack {
public:
    void push(T value) {
        data.push_back(value);
    }

    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T value = data.back();
        data.pop_back();
        return value;
    }

    T top() const {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    void insertionSort() {
        for (size_t i = 1; i < data.size(); i++) {
            T key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }


    void countingSort(int exp) {
        int n = data.size();
        std::vector<T> output(n);
        std::vector<int> count(10, 0);

        for (int i = 0; i < n; i++) {
            count[(data[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(data[i] / exp) % 10] - 1] = data[i];
            count[(data[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            data[i] = output[i];
        }
    }

    void bubbleSort() {
        if (data.empty())
            return;

        int n = data.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }


    void cocktailShakerSort() {
        if (data.empty())
            return;

        int left = 0;
        int right = data.size() - 1;

        while (left <= right) {
            for (int i = left; i < right; i++) {
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                }
            }
            right--;

            for (int i = right; i > left; i--) {
                if (data[i] < data[i - 1]) {
                    std::swap(data[i], data[i - 1]);
                }
            }
            left++;
        }
    }


    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    int partition(int low, int high) {
        T pivot = data[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return (i + 1);
    }


private:
    std::vector<T> data;
};
