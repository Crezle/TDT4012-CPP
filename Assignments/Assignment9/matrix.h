#pragma once
#include <iostream>
#include <array>

using namespace std;

// 2a)

class Matrix {
private:
    int rows;
    int columns;
    double **matrix;
public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    Matrix(Matrix &rhs);
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    double* operator[](int i);
    int getRows() const;
    int getColumns() const;
    friend ostream& operator<<(ostream& o, Matrix& m);
    Matrix operator=(Matrix rhs);
    Matrix operator+=(Matrix rhs);
    Matrix operator+(Matrix rhs);
    Matrix operator-(Matrix rhs);
    Matrix operator-=(Matrix rhs);
    Matrix operator*(Matrix rhs);
    Matrix operator*=(Matrix rhs);
    Matrix Matrix::operator-();
};