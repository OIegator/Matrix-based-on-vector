#include "test.h"
#include "matrix.h"

Test::Test(QObject *parent) : QObject(parent) { }

void Test::test_det(){
    double *a=new double[3],*b=new double[3],*c=new double[3];
    a[0]=1;a[1]=2;a[2]=3;
    b[0]=4;b[1]=5;b[2]=6;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v=new Vector[3];
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    QCOMPARE(m.det(3),0);
}

void Test::test_trans(){
    double *a=new double[3],*b=new double[3],*c=new double[3];
    a[0]=1;a[1]=2;a[2]=3;
    b[0]=4;b[1]=5;b[2]=6;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v=new Vector[3];
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    Matrix n;
    n=m.trans();
    double *d=new double[3],*e=new double[3],*f=new double[3];
    d[0]=1;d[1]=4;d[2]=7;
    e[0]=2;e[1]=5;e[2]=8;
    f[0]=3;f[1]=6;f[2]=9;
    Vector v4(d,3),v5(e,3),v6(f,3);
    Vector *V=new Vector[3];
    V[0]=v4;V[1]=v5;V[2]=v6;
    Matrix t(V,3,3);
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            QCOMPARE(n(i,j),t(i,j));
}

void Test::test_cofactor(){
    double *a=new double[3],*b=new double[3],*c=new double[3];
    a[0]=4;a[1]=5;a[2]=6;
    b[0]=1;b[1]=2;b[2]=3;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v=new Vector[3];
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    QCOMPARE(m.cofactor(1,1),-6);
}

void Test::test_smaller(){
    double *a=new double[3],*b=new double[3],*c=new double[3];
    a[0]=1;a[1]=2;a[2]=3;
    b[0]=4;b[1]=5;b[2]=6;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v=new Vector[3];
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

void Test::test_rev(){

}

void Test::test_operators(){
    double *a=new double[3],*b=new double[3],*c=new double[3];
    a[0]=1;a[1]=2;a[2]=3;
    b[0]=4;b[1]=5;b[2]=6;
    c[0]=7;c[1]=8;c[2]=9;
    Vector v1(a,3),v2(b,3),v3(c,3);
    Vector *v=new Vector[3];
    v[0]=v1;v[1]=v2;v[2]=v3;
    Matrix m(v,3,3);
    double *d=new double[3],*e=new double[3],*f=new double[3];
    d[0]=1;d[1]=1;d[2]=1;
    e[0]=1;e[1]=1;e[2]=1;
    f[0]=1;f[1]=1;f[2]=1;
    Vector v4(d,3),v5(e,3),v6(f,3);
    Vector *V=new Vector[3];
    V[0]=v4;V[1]=v5;V[2]=v6;
    Matrix t(V,3,3);
    Matrix n;
    n=m+t;

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
              QCOMPARE(n(i,j),m(i,j)+1);
    n=n-t;

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
              QCOMPARE(n(i,j),m(i,j));
    n=m*2;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
              QCOMPARE(n(i,j),2*m(i,j));
    d[0]=1;d[1]=0;d[2]=1;
    e[0]=0;e[1]=1;e[2]=0;
    f[0]=1;f[1]=1;f[2]=1;
    Vector v7(d,3),v8(e,3),v9(f,3);
    Vector *V1=new Vector[3];
    V1[0]=v7;V1[1]=v8;V1[2]=v9;
    Matrix t1(V1,3,3);
    n=m*t1;
    v7.setVal(0,4); v7.setVal(1,5); v7.setVal(2,4);
    v8.setVal(0,10); v8.setVal(1,11); v8.setVal(2,10);
    v9.setVal(0,16); v9.setVal(1,17); v9.setVal(2,16);
    Vector *V2=new Vector[3];
    V2[0]=v7;V2[1]=v8;V2[2]=v9;
    Matrix t2(V2,3,3);
     n.print();
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
              QCOMPARE(n(i,j),t2(i,j));
    QCOMPARE(m==n,false);
    QCOMPARE(m!=n,true);
    QCOMPARE(m(0,0),1);
}


