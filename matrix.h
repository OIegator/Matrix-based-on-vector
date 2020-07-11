#ifndef MATRIX_H
#define MATRIX_H

#include <QTextStream>
#include <QString>
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
    Matrix(int cols,int rows, bool type);
    Matrix(Matrix &m);

    Matrix smallermatr(int cols, int rows);
    Matrix trans();

    double deter();
    int minor(int x,int y);
    void print();
    void setVal(double value, int col, int row);
    Matrix reverse();
    Matrix getMatrixWithoutRowAndCol(int row, int col);
    double det(int size);
    double cofactor(int col, int row);
    double getValue(int x,int y);
    int getRows(){return rows;}
    int getCols(){return cols;}


    Matrix& operator=(const Matrix &m);
    Matrix operator+(const Matrix &m);
    Matrix operator-(const Matrix &m);
    Matrix operator*(double x);
    Matrix operator*(const Matrix &m);
    Matrix operator*( Vector &v);
    bool operator==(const Matrix &m);
    bool operator!=(const Matrix &m);
    double operator()(int x, int y);

    friend QTextStream& operator>> (QTextStream &is, Matrix &m);

};

#endif // MATRIX_H
