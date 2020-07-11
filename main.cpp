
#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QTextStream>

QTextStream out(stdout);
QTextStream in(stdin);

void printMenu() {
    system("cls");
    out << "  What do you want to do?" << Qt::endl;
    out << "    - 1. Enter new matrix." << Qt::endl;
    out << "    - 2. Print current matrix." << Qt::endl;
    out << "    - 4. Initialize zeros matrix." << Qt::endl;
    out << "    - 5. Initialize ones matrix." << Qt::endl;
    out << "    - 6. Get a sub-matrix." << Qt::endl;
    out << "    - 7. Get trunsposed matrix." << Qt::endl;
    out << "    - 8. Get matrix determinant." << Qt::endl;
    out << "    - 9. Get cofactor of matrix element." << Qt::endl;
    out << "    - 10. Get reversed matrix." << Qt::endl;
    out << "    - 11. Multiply the current matrix by a number." << Qt::endl;
    out << "    - 12. Multiply the current matrix by a vector." << Qt::endl;
    out << "    - 0. EXIT.\n" << Qt::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int option;
    int n=4;
    int c=4;
    double *b=new double[n];
    double *d=new double[c];
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

    Matrix currentMatrix(arr2, 3, 3);
    currentMatrix.setVal(2,0,0);
    currentMatrix.setVal(6,0,1);
    currentMatrix.setVal(5,0,2);
    currentMatrix.setVal(5,1,0);
    currentMatrix.setVal(3,1,1);
    currentMatrix.setVal(-2,1,2);
    currentMatrix.setVal(7,2,0);
    currentMatrix.setVal(4,2,1);
    currentMatrix.setVal(-3,2,2);
    Matrix newMM(arr3, 3, 3);

    currentMatrix.print();
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


    out << currentMatrix.cofactor(0,0) << Qt::endl;
    Matrix zer(3,3,1);
    zer.print();
    currentMatrix.smallermatr(2,1).print();

    do {

        printMenu();
        out << "-------Current matrix-------" << Qt::endl;
        currentMatrix.print();

        int n = 0;
        int m = 0;
        in >> option;

        switch (option) {
        case 1:
            out << Qt::endl;
            out << "Item 1" << Qt::endl;
            break;

        case 2:
            out << Qt::endl;
            currentMatrix.print();
            break;

        case 4: {
            out << Qt::endl;
            out << "Enter martrix dimensions: " << Qt::endl;
            in >> n >> m;
            Matrix zeros(n, m, 0);
            out << Qt::endl;
            zeros.print();
        }
            break;

        case 5: {
            out << Qt::endl;
            out << "Enter martrix dimensions: " << Qt::endl;
            in >> n >> m;
            Matrix ones(n, m, 1);
            out << Qt::endl;
            ones.print();
        }
            break;
        case 6: {
            out << Qt::endl;
            out << "Enter sub-matrix martrix dimensions: " << Qt::endl;
            in >> n >> m;
            out << Qt::endl;
            currentMatrix.smallermatr(n,m).print();
        }
            break;
        case 7:
            out << Qt::endl;
            currentMatrix.trans().print();
            break;
        case 8:
            out << Qt::endl;
            out << currentMatrix.det(currentMatrix.getCol()) << Qt::endl;
            break;
        case 9: {
            out << Qt::endl;
            out << "Enter coordinates martrix element: " << Qt::endl;
            in >> n >> m;
            out << currentMatrix.cofactor(n, m) << Qt::endl;
        }
            break;
        case 10:
            out << Qt::endl;
            currentMatrix.reverse().print();
            break;
        case 11: {
            out << Qt::endl;
            out << "Enter the number to multiply the matrix by: " << Qt::endl;
            in >> n;
            Matrix temp(1, 1, 0);
            temp = currentMatrix * n;
            temp.print();
        }
        case 12: {
            out << Qt::endl;
            out << "Enter " << Qt::endl;
            in >> n;
            Matrix temp(1, 1, 0);
            temp = currentMatrix * n;
            temp.print();
        }
        }

        if(option != 0)
            system("pause");
    } while (option != 0);

    return 0;
}
