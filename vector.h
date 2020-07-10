#ifndef VECTOR_H
#define VECTOR_H

#include <QTextStream>

class Vector
{
private:
    int *val;
    int size;
public:
    Vector();
    Vector(int *a, int s);
    Vector(const Vector &v);
    Vector(int s);
    Vector(int s, bool type);
    ~Vector();


    double length();
    void print();
    int getSize();
    void setVal(int index, int x);

    Vector& operator=(const Vector &v1);
    Vector operator+(const Vector &v1);
    Vector operator-(const Vector &v1);
    Vector operator*(int x);
    Vector operator*(const Vector &v1);
    int operator[](int x);
};

#endif // VECTOR_H
