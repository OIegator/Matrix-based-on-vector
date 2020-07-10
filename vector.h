#ifndef VECTOR_H
#define VECTOR_H

#include <QTextStream>

class Vector
{
private:
    double *val;
    int size;
public:
    Vector();
    Vector(double *a, int s);
    Vector(const Vector &v);
    Vector(int s);
    Vector(int s, bool type);
    ~Vector();


    double length();
    void print();
    int getSize();
    void setVal(int index, double x);

    Vector& operator=(const Vector &v1);
    Vector operator+(const Vector &v1);
    Vector operator-(const Vector &v1);
    Vector operator*(double x);
    Vector operator*(const Vector &v1);
    double operator[](int x);

signals:

};

#endif // VECTOR_H
