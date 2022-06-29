#include <iostream>
#include <fstream>
#include "Matrix.h"

int main() {
    std::ifstream fin("C:\\project13\\input.txt");
    Matrix matrix;
    matrix.fill(fin);
    matrix.print();

    return 0;
}
