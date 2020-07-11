#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QTextStream>
#include <QString>

QTextStream out(stdout);
QTextStream in(stdin);

void printMenu() {
    system("cls");
    out << "  What do you want to do?" << Qt::endl;
    out << "    - 1. Enter new matrix." << Qt::endl;
    out << "    - 2. Print current matrix." << Qt::endl;
    out << "    - 3. Initialize zeros matrix." << Qt::endl;
    out << "    - 4. Initialize ones matrix." << Qt::endl;
    out << "    - 5. Get a sub-matrix." << Qt::endl;
    out << "    - 6. Get trunsposed matrix." << Qt::endl;
    out << "    - 7. Get matrix determinant." << Qt::endl;
    out << "    - 8. Get cofactor of matrix element." << Qt::endl;
    out << "    - 9. Get reversed matrix." << Qt::endl;
    out << "    - 10. Multiply the current matrix by a number." << Qt::endl;
    out << "    - 11. Multiply the current matrix by a vector." << Qt::endl;
    out << "    - 12. Sum another matrix with the current one." << Qt::endl;
    out << "    - 0. EXIT.\n" << Qt::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int option;

    Matrix currentMatrix(3, 3, 0);
    currentMatrix.setVal(2,0,0);
    currentMatrix.setVal(6,0,1);
    currentMatrix.setVal(5,0,2);
    currentMatrix.setVal(5,1,0);
    currentMatrix.setVal(3,1,1);
    currentMatrix.setVal(-2,1,2);
    currentMatrix.setVal(7,2,0);
    currentMatrix.setVal(4,2,1);
    currentMatrix.setVal(-3,2,2);

    do {

        printMenu();
        out << "  --------Current matrix--------" << Qt::endl;
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

        case 3: {
            out << Qt::endl;
            out << "Enter martrix dimensions: " << Qt::endl;
            in >> n >> m;
            Matrix zeros(n, m, 0);
            out << Qt::endl;
            zeros.print();
        }
            break;

        case 4: {
            out << Qt::endl;
            out << "Enter martrix dimensions: " << Qt::endl;
            in >> n >> m;
            Matrix ones(n, m, 1);
            out << Qt::endl;
            ones.print();
        }
            break;
        case 5: {
            out << Qt::endl;
            out << "Enter sub-matrix martrix dimensions: " << Qt::endl;
            in >> n >> m;
            out << Qt::endl;
            currentMatrix.smallermatr(n,m).print();
        }
            break;
        case 6:
            out << Qt::endl;
            currentMatrix.trans().print();
            break;
        case 7:
            out << Qt::endl;
            out << currentMatrix.det(currentMatrix.getCols()) << Qt::endl;
            break;
        case 8: {
            out << Qt::endl;
            out << "Enter coordinates martrix element: " << Qt::endl;
            in >> n >> m;
            out << currentMatrix.cofactor(n, m) << Qt::endl;
        }
            break;
        case 9:
            out << Qt::endl;
            currentMatrix.reverse().print();
            break;
        case 10: {
            out << Qt::endl;
            out << "Enter the number to multiply the matrix by: " << Qt::endl;
            in >> n;
            Matrix temp(1, 1, 0);
            temp = currentMatrix * n;
            temp.print();
        }
        case 11: {
            out << Qt::endl;
            if(currentMatrix.getCols() > 1) {
                out << "Enter " << currentMatrix.getCols() << " elements of vector: " << Qt::endl;
                Vector v1(currentMatrix.getCols(),0);
                QString s;
                for(int i=0; i <currentMatrix.getCols(); i++) {
                    in >> s;
                    v1.setVal(i, s.toDouble());
                }
                Matrix temp(1, 1, 0);
                temp = currentMatrix * v1;
                temp.print();
            } else {
                out << "Enter " << currentMatrix.getRows() << " elements of vector: " << Qt::endl;
                Vector v1(currentMatrix.getRows(),0);
                QString s;
                for(int i=0; i <currentMatrix.getRows(); i++) {
                    in >> s;
                    v1.setVal(i, s.toDouble());
                }
                Matrix temp(1, 1, 0);
                temp = currentMatrix * v1;
                temp.print();
            }
        }
        case 12: {
            out << Qt::endl;
            out << "Enter the matrix you want to sum with the current one: " << Qt::endl;
            Matrix temp(currentMatrix.getCols(), currentMatrix.getRows(), 1);
            in >> temp;
            temp = currentMatrix + temp;
            out << "  ------------Result------------" << Qt::endl;
            temp.print();
        }
        }

        if(option != 0)
            system("pause");
    } while (option != 0);

    return 0;
}
