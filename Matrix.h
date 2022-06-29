//
// Created by Iluha on 28.06.2022.
//

#pragma once
#ifndef PROJECT13_MATRIX_H
#define PROJECT13_MATRIX_H

#include <iostream>
#include <fstream>

class Matrix {
    int** array;
    int n;
    int m;
public:
    Matrix();
    Matrix(const Matrix &other);
    ~Matrix();

    void readMatrix(std::ifstream &fin, int n);
    void fill(std::ifstream &fin);
    void print();
};


#endif //PROJECT13_MATRIX_H
