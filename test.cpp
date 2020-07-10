#include "test.h"
#include "matrix.h"

Test::Test()
{

}

void Test::constr(){

}

void Test::test_det(){
    double *a,*b,*c;
    a[0]=1;a[1]=2;a[2]=3;
    b[0]=4;b[1]=5;b[2]=6;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v;
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    QCOMPARE(m.det(3),0);
}

void Test::test_trans(){
    double *a,*b,*c;
    a[0]=1;a[1]=2;a[2]=3;
    b[0]=4;b[1]=5;b[2]=6;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v;
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    Matrix n;
    n=m.reverse();
    double *d,*e,*f;
    d[0]=1;d[1]=4;d[2]=7;
    e[0]=2;e[1]=5;e[2]=8;
    f[0]=3;f[1]=6;f[2]=9;
    Vector v4(d,3),v5(e,3),v6(f,3);
    Vector *V;
    V[0]=v4;V[1]=v5;V[2]=v6;
    Matrix t(V,3,3);
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            QCOMPARE(n(i,j),t(i,j));
}

void Test::test_cofactor(){
    double *a,*b,*c;
    a[0]=4;a[1]=5;a[2]=6;
    b[0]=1;b[1]=2;b[2]=3;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v;
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    QCOMPARE(m.minor(1,1),-6);
}

void Test::test_smaller(){
    double *a,*b,*c;
    a[0]=1;a[1]=2;a[2]=3;
    b[0]=4;b[1]=5;b[2]=6;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v;
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    Matrix n;
    n=m.smallermatr(2,2);
    QCOMPARE(n.getCols(),2);
    QCOMPARE(n.getRows(),2);
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
              QCOMPARE(n(i,j),m(i,j));
}


