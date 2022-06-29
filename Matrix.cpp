//
// Created by Iluha on 28.06.2022.
//

#include "Matrix.h"

Matrix::Matrix() {
    this->array = nullptr;
    this->n = 0;
    this->m = 0;
}

Matrix::Matrix(const Matrix &other) {
    for (int i = 0; i < this->n; i++)
        delete[] this->array[i];

    delete[] this->array;

    this->n = other.n;
    this->m = other.m;

    this->array = new int*[this->n];

    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->m; j++)
            this->array[i][j] = other.array[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < this->n; i++)
        delete[] this->array[i];

    delete[] this->array;
}

void Matrix::readMatrix(std::ifstream &fin, int n) {
    if (!fin) {
        std::cout << "Failed!\n";
    } else {
        this->n = n;
        this->m = n;

        this->array = new int*[this->n];

        for (int i = 0; i < this->n; i++)
            this->array[i] = new int[this->m];

        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                fin >> this->array[i][j];
    }
}

void Matrix::fill(std::ifstream &fin) {
    if (!fin) {
        std::cout << "Failed!\n";
    } else {
        int countMat, size;

        fin >> countMat >> size;

        this->n = size;
        this->m = countMat;

        this->array = new int*[this->n];

        for (int i = 0; i < this->n; i++)
            this->array[i] = new int[this->m]{};

        int count = 0;

        for (int i = 0; i < countMat; i++) {
            Matrix matrix;
            matrix.readMatrix(fin, size);

            for (int j = 0; j < size; j++) {
                int summa = 0;

                for (int h = 0; h < size; h++)
                    summa += matrix.array[j][h];

                summa /= size;

                this->array[j][count] = summa;
            }

            count++;
        }
    }
}

void Matrix::print() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->m; j++)
            std::cout << this->array[i][j] << " ";

        std::cout << std::endl;
    }
}