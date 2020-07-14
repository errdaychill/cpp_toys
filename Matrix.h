#pragma once

#include <iostream>
#include <random>
#include <cmath>

class Matrix
{
private:
        int row_;
        int col_;
        double **mat;
public:
        Matrix(const int& row, const int& column);
        Matrix(const int& row, const int& col, int* array);
        ~Matrix();
        void print();
        Matrix randMat(const int& row, const int& column);
        Matrix operator+(Matrix& m1);
        Matrix operator-(Matrix& m1);
        Matrix operator*(Matrix& m1);
        double deterministic(Matrix m1, const int n);
        Matrix minorMat(Matrix& m1, const int& out_rowidx, const int& out_colidx);
        Matrix inverse(Matrix& m1);
        Matrix transpose(Matrix& m1);
        void eye();
        void getRow(const int& row_idx);
        void getCol(const int& col_idx);
        void getIndex(const int& row_idx, const int& col_idx);
};
