
#ifndef CONVOLUTION_CONVOLUTIONS_H
#define CONVOLUTION_CONVOLUTIONS_H

#include "printVector.h"
#include <vector>
#include <iostream>

std::vector<std::vector<int>> conv2d(std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &kernel);

void repeated_convolution_2d(std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &kernel);

std::vector<std::vector<int>> conv3d(std::vector<std::vector<std::vector<int>>> &matrix,
                                     std::vector<std::vector<std::vector<int>>> &kernel);

std::vector<std::vector<int>> conv2d(std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &kernel) {
    unsigned int long matrix_size = matrix.size();
    unsigned int long kernel_size = kernel.size();
    auto new_matrix_size = matrix_size - kernel_size + 1;
    std::vector<std::vector<int>> new_matrix(new_matrix_size, std::vector<int>(new_matrix_size, 0));

    for (int i = 0; i < new_matrix_size; i++) {
        for (int j = 0; j < new_matrix_size; j++) {
            // Convolution operation
            for (int kernel_height = 0; kernel_height < kernel_size; kernel_height++) {
                for (int kernel_width = 0; kernel_width < kernel_size; kernel_width++) {
                    new_matrix[i][j] +=
                            matrix[i + kernel_height][j + kernel_width] * kernel[kernel_height][kernel_width];
                }
            }
        }
    }
    return new_matrix;
}

void repeated_convolution_2d(std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &kernel) {
    std::vector<std::vector<int>> new_matrix, old_matrix;
    old_matrix = matrix;
    do {
        new_matrix = conv2d(old_matrix, kernel);
        std::cout << "New matrix size: " << new_matrix.size() << "x" << new_matrix.size() << std::endl;

        for (int i = 0; i < new_matrix.size(); i++) {
            for (int j = 0; j < new_matrix.size(); j++) {
                std::cout << new_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        old_matrix = new_matrix;
    } while (new_matrix.size() > 1);
}

std::vector<std::vector<int>> conv3d(std::vector<std::vector<std::vector<int>>> &matrix,
                                     std::vector<std::vector<std::vector<int>>> &kernel) {
    unsigned int long matrix_size = matrix[1].size();
    std::cout << "Matrix size: " << matrix_size << std::endl;

    unsigned int long kernel_size = kernel[1].size();
    std::cout << "Matrix size: " << matrix_size << std::endl;


    auto new_matrix_size = matrix_size - kernel_size + 1;

    std::vector<std::vector<int>> new_matrix(new_matrix_size, std::vector<int>(new_matrix_size, 0));

    // color channel
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < new_matrix_size; i++) {
            for (int j = 0; j < new_matrix_size; j++) {
                for (int kernel_height = 0; kernel_height < kernel_size; kernel_height++) {
                    for (int kernel_width = 0; kernel_width < kernel_size; kernel_width++) {

                        std::cout << "c=" << c << " i=" << i << " j=" << j << " kernel_height=" << kernel_height
                                  << " kernel_width=" << kernel_width << "\n";

                        std::cout << "Performing convolution on channel: " << c << "\n";
                        std::cout << "Matrix value: " << matrix[c][i + kernel_height][j + kernel_width] << "\n";
                        std::cout << "Kernel value: " << kernel[c][kernel_height][kernel_width] << "\n";

                        new_matrix[i][j] +=
                                matrix[c][i + kernel_height][j + kernel_width] * kernel[c][kernel_height][kernel_width];
                    }
                }
            }
        }
    }
    return new_matrix;
}

#endif //CONVOLUTION_CONVOLUTIONS_H
