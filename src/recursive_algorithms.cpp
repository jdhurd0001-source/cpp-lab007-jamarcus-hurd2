#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// Base case: n is 0 or 1.
// Recursive case: n multiplied by factorial(n - 1).
int factorial(int n) {
    if (n < 0) {
        throw std::logic_error("factorial: n must be non-negative");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int factorialIterative(int n) {
    if (n < 0) {
        throw std::logic_error("factorialIterative: n must be non-negative");
    }

    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Base case: fib(0) = 0 and fib(1) = 1.
// Recursive case: fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if (n < 0) {
        throw std::logic_error("fibonacci: n must be non-negative");
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciIterative(int n) {
    if (n < 0) {
        throw std::logic_error("fibonacciIterative: n must be non-negative");
    }
    if (n == 0) {
        return 0;
    }

    int previous = 0;
    int current = 1;
    for (int i = 2; i <= n; ++i) {
        int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

namespace {
int binarySearchRecursive(const std::vector<int>& array, int target,
                          std::size_t left, std::size_t right) {
    // Base case: the remaining search interval is empty.
    if (left > right) {
        return -1;
    }

    std::size_t middle = left + (right - left) / 2;
    // Recursive cases: search the left or right half, or stop when found.
    if (array[middle] == target) {
        return static_cast<int>(middle);
    }
    if (array[middle] > target) {
        if (middle == 0) {
            return -1;
        }
        return binarySearchRecursive(array, target, left, middle - 1);
    }
    return binarySearchRecursive(array, target, middle + 1, right);
}

int arraySumRecursive(const std::vector<int>& array, std::size_t index) {
    // Base case: there are no remaining elements.
    if (index == array.size()) {
        return 0;
    }
    // Recursive case: add the current element to the sum of the remainder.
    return array[index] + arraySumRecursive(array, index + 1);
}

void reverseArrayRecursive(std::vector<int>& array,
                           std::size_t left, std::size_t right) {
    // Base case: the remaining portion has zero or one element.
    if (left >= right) {
        return;
    }

    // Recursive case: swap the ends and reverse the remaining middle.
    std::swap(array[left], array[right]);
    reverseArrayRecursive(array, left + 1, right - 1);
}
}

// Base case: target not found or left > right.
// Recursive case: compare the middle element and search the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    if (array.empty()) {
        return -1;
    }
    return binarySearchRecursive(array, target, 0, array.size() - 1);
}

int binarySearchIterative(const std::vector<int>& array, int target) {
    if (array.empty()) {
        return -1;
    }

    std::size_t left = 0;
    std::size_t right = array.size() - 1;
    while (left <= right) {
        std::size_t middle = left + (right - left) / 2;
        if (array[middle] == target) {
            return static_cast<int>(middle);
        }
        if (array[middle] > target) {
            if (middle == 0) {
                break;
            }
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

// Base case: the array is empty.
// Recursive case: first element plus the sum of the remainder.
int arraySum(const std::vector<int>& array) {
    return arraySumRecursive(array, 0);
}

int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (int value : array) {
        sum += value;
    }
    return sum;
}

// Base case: the remaining portion has size zero or one.
// Recursive case: swap the first and last elements, then reverse the middle.
void reverseArray(std::vector<int>& array) {
    if (!array.empty()) {
        reverseArrayRecursive(array, 0, array.size() - 1);
    }
}

void reverseArrayIterative(std::vector<int>& array) {
    if (array.empty()) {
        return;
    }

    std::size_t left = 0;
    std::size_t right = array.size() - 1;
    while (left < right) {
        std::swap(array[left], array[right]);
        ++left;
        --right;
    }
}
