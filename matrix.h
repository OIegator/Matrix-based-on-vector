#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"
#include "math.h"

class Matrix
{
private:
    Vector *v;
    int cols;
    int rows;

public:
    Matrix();
    Matrix(Vector *v,int cols,int rows);
    Matrix(int cols,int rows);
    Matrix(Matrix &m);

    Matrix smallermatr(int cols, int rows);
    Matrix trans();
    int deter();
    int minor(int x,int y);
    void print();
    void setVal(int value, int col, int row);
    Matrix reverse();
    Matrix getMatrixWithoutRowAndCol(int row, int col);
    int det(int size);
    int cofactor(int col, int row);


    Matrix& operator=(const Matrix &m);
    Matrix operator+(const Matrix &m);
    Matrix operator-(const Matrix &m);
    Matrix operator*(int x);
    Matrix operator*(const Matrix &m);
    Vector operator*( Vector &v);
    Matrix operator==(const Matrix &m);
    Matrix operator!=(const Matrix &m);
    int operator[](int x);

signals:

};

#endif // MATRIX_H
