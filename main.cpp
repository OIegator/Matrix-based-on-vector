#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);
    int n=4;
    int c=4;
    int *b=new int[n];
    int *d=new int[c];
    for (int i=0;i<n;i++){
        b[i]=i+1;
    }
    for (int i=0;i<c;i++){
        d[i]=1;
    }

    Vector v(b,n);
    Vector v2(d,c);
    Vector v3(4, 1);
    Vector v4(4, 0);
    out<<v.length()<<Qt::endl;
    out<<v[1]<<Qt::endl;
    v.print();
    v=v+v2;
    v.print();
    v=v-v2;
    v.print();
    v=v*3;
    v.print();
    v3.print();
    v4.print();

    out << "//////////" << Qt::endl;

    Vector *arr = new Vector[4];
    arr[0] = v;
    arr[1] = v2;
    arr[2] = v;
    arr[3] = v2;
    for(int i=0;i<4;i++) {
        arr[i].print();
    }

    out << "//////////" << Qt::endl;

    Matrix m(arr, 4, 4);
    m.print();

    out << "//////////" << Qt::endl;

    Vector *arr2 = new Vector[3];
    Vector vec(3, 1);
    Vector vec2(3, 1);
    Vector vecz(3, 0);
    arr2[0] = vec;
    arr2[1] = vec;
    arr2[2] = vec;

//    for(int i=0;i<4;i++) {
//        arr2[i].print();
//    }

    Vector *arr3 = new Vector[3];
    arr3[0] = vecz;
    arr3[1] = vecz;
    arr3[2] = vecz;
    vec = vecz;

    Matrix newM(arr2, 3, 3);
    newM.setVal(2,0,0);
    newM.setVal(6,0,1);
    newM.setVal(5,0,2);
    newM.setVal(5,1,0);
    newM.setVal(3,1,1);
    newM.setVal(-2,1,2);
    newM.setVal(7,2,0);
    newM.setVal(4,2,1);
    newM.setVal(-3,2,2);
    Matrix newMM(arr3, 3, 3);

    newM.print();
    newMM.print();


//    newMM = newM.getMatrixWithoutRowAndCol(0,0);
//       newMM.print();
//       out << "//////////" << Qt::endl;

//    newMM = newM.getMatrixWithoutRowAndCol(1,0);
//       newMM.print();
//       out << "//////////" << Qt::endl;

//    newMM = newM.getMatrixWithoutRowAndCol(2,0);
//       newMM.print();
//       out << "//////////" << Qt::endl;


    out << newM.cofactor(0,0) << Qt::endl;
    newM.reverse().print();

    return 0;
}
