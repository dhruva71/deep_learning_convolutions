#include <iostream>
#include <vector>
#include "printVector.h"
#include "convolutions.h"


int main() {
    std::cout << "Performing convolution 2D" << std::endl;

    std::vector<std::vector<int>> matrix = {{1,  2,  3,  4,  5},
                                            {6,  7,  8,  9,  10},
                                            {11, 12, 13, 14, 15},
                                            {16, 17, 18, 19, 20},
                                            {21, 22, 23, 24, 25}};
    std::vector<std::vector<int>> kernel = {{1, 0},
                                            {0, 1}};
    repeated_convolution_2d(matrix, kernel);

    // conv3d
    std::cout << "Performing convolution 3D" << std::endl;
    std::vector<std::vector<std::vector<int>>> matrix3d = {{{1, 2, 3, 4, 5, 6},
                                                                   {7, 8, 9, 10, 11, 12},
                                                                   {13, 14, 15, 16, 17, 18},
                                                                   {19, 20, 21, 22, 23, 24},
                                                                   {25, 26, 27, 28, 29, 30},
                                                                   {31, 32, 33, 34, 35, 36}},
                                                           {{1, 2, 3, 4, 5, 6},
                                                                   {7, 8, 9, 10, 11, 12},
                                                                   {13, 14, 15, 16, 17, 18},
                                                                   {19, 20, 21, 22, 23, 24},
                                                                   {25, 26, 27, 28, 29, 30},
                                                                   {31, 32, 33, 34, 35, 36}},
                                                           {{1, 2, 3, 4, 5, 6},
                                                                   {7, 8, 9, 10, 11, 12},
                                                                   {13, 14, 15, 16, 17, 18},
                                                                   {19, 20, 21, 22, 23, 24},
                                                                   {25, 26, 27, 28, 29, 30},
                                                                   {31, 32, 33, 34, 35, 36}}};

    std::vector<std::vector<std::vector<int>>> kernel3d = {{{1, 0, 1},
                                                                   {0, 1, 0},
                                                                   {1, 0, 1}},
                                                           {{1, 0, 1},
                                                                   {0, 1, 0},
                                                                   {1, 0, 1}},
                                                           {{1, 0, 1},
                                                                   {0, 1, 0},
                                                                   {1, 0, 1}}};


    auto conv3d_result = conv3d(matrix3d, kernel3d);

    std::cout << "Shape of matrix3d: " << matrix3d.size() << "x" << matrix3d[0].size() << "x" << matrix3d[0][0].size()
              << std::endl;
    std::cout << "Shape of kernel3d: " << kernel3d.size() << "x" << kernel3d[0].size() << "x" << kernel3d[0][0].size()
              << std::endl;
    std::cout << "New matrix size: " << conv3d_result.size() << "x" << conv3d_result.size() << std::endl;

    printVector(conv3d_result);

    return 0;
}

