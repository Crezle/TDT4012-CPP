#include "matrix.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <iomanip>

using namespace std;

// 2a)

Matrix::Matrix(int nRows, int nColumns):  
rows{nRows}, 
columns{nColumns} 
{
    assert(nRows > 0 && nColumns > 0);
    matrix = new double*[nRows];
    for (int i = 0; i < nRows; i++) {
        matrix[i] = new double[nColumns];
        for (int j = 0; j < nColumns; j++) {
            matrix[i][j] = 0;
        }
    }
}

// 2b)

Matrix::~Matrix() {
    for (int r = 0; r < rows; r++) {
        delete[] matrix[r];
        matrix[r] = nullptr;
        }
    delete[] matrix;
    rows = 0;
    columns = 0;
    matrix = nullptr;
}

Matrix::Matrix(int nRows): Matrix(nRows, nRows) {
    for (int i = 0; i < nRows; i++) {
        matrix[i][i] = 1;
    }
}

// 2c)

double Matrix::get(int row, int col) const{
    assert(row < rows && col < columns);
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}

// 2d)

double* Matrix::operator[](int i) {
    return matrix[i];
}

// 2e)

int Matrix::getRows() const{
    return rows;
}

int Matrix::getColumns() const{
    return columns;
}

// 2f)

ostream& operator<<(ostream& o, Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            o << setw(4) << m[i][j] << " ";
        }
        
        o << '\n';
    }
    return o;
}

// 4a og b)

Matrix::Matrix(Matrix &rhs) {
    rows = rhs.rows;
    columns = rhs.columns;
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

Matrix Matrix::operator=(Matrix rhs) {
    swap(rows, rhs.rows);
    swap(columns, rhs.columns);
    swap(matrix, rhs.matrix);
    return *this;
}

// 5a)

Matrix Matrix::operator+=(Matrix rhs) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] += rhs[i][j];
        }
    }
    return *this;
}

// 5b)

Matrix Matrix::operator+(Matrix rhs) {
    Matrix sum(rhs.rows,rhs.columns);
    sum = rhs;
    sum += *this;
    return sum;
}

// 5d)

Matrix Matrix::operator-=(Matrix rhs) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] -= rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(Matrix rhs) {
    Matrix diff(rhs.rows,rhs.columns);
    diff = *this;
    diff -= rhs;
    return diff;
}
// HVORDAN LAGER MAN "NEGATIV" OPERATOR?

Matrix Matrix::operator-() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] *= -1;
        }
    }
    return *this;
}

Matrix Matrix::operator*=(Matrix rhs) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] *= rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(Matrix rhs) {
    Matrix prod(rhs.rows,rhs.columns);
    prod = rhs;
    prod *= *this;
    return prod;
}