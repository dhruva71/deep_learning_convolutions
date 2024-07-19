#ifndef CONVOLUTION_PRINTVECTOR_H
#define CONVOLUTION_PRINTVECTOR_H

#include <iostream>
#include <vector>

// Function to print a 1D vector
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Function to print a 2D vector
template <typename T>
void printVector(const std::vector<std::vector<T>>& vec) {
    for (const auto& row : vec) {
        printVector(row); // Use the 1D vector printing function
    }
    std::cout << "\n";
}

// Function to print a 3D vector
template <typename T>
void printVector(const std::vector<std::vector<std::vector<T>>>& vec) {
    for (const auto& matrix : vec) {
        printVector(matrix); // Use the 2D vector printing function
    }
    std::cout << "\n";
}

// Function to print a 4D vector
template <typename T>
void printVector(const std::vector<std::vector<std::vector<std::vector<T>>>>& vec) {
    for (const auto& cube : vec) {
        printVector(cube); // Use the 3D vector printing function
    }
    std::cout << "\n";
}

#endif //CONVOLUTION_PRINTVECTOR_H
