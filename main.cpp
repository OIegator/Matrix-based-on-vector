#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QTextStream>
#include <QString>

QTextStream out(stdout);
QTextStream in(stdin);
QTextStream err(stderr);

void printMenu() {
    system("cls");
    out << "  What do you want to do?" << Qt::endl;
    out << "    - 1. Enter new matrix." << Qt::endl;
    out << "    - 2. Initialize zeros matrix." << Qt::endl;
    out << "    - 3. Initialize ones matrix." << Qt::endl;
    out << "    - 4. Get a sub-matrix." << Qt::endl;
    out << "    - 5. Get trunsposed matrix." << Qt::endl;
    out << "    - 6. Get matrix determinant." << Qt::endl;
    out << "    - 7. Get cofactor of matrix element." << Qt::endl;
    out << "    - 8. Get reversed matrix." << Qt::endl;
    out << "    - 9. Sum another matrix with the current one." << Qt::endl;
    out << "    - 10. Subtract another matrix from the current one." << Qt::endl;
    out << "    - 11. Multiply the current matrix by a number." << Qt::endl;
    out << "    - 12. Multiply the current matrix by a vector." << Qt::endl;
    out << "    - 13. Multiply the current matrix by a another matrix." << Qt::endl;
    out << "    - 14. Run task." << Qt::endl;
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
        out << currentMatrix;

        int n = 0;
        int m = 0;
        in >> option;

        switch (option) {
        case 1:
            out << Qt::endl;
            in >> currentMatrix;
            break;

        case 2: {
            out << Qt::endl;
            out << "Enter martrix dimensions: " << Qt::endl;
            in >> n >> m;
            Matrix zeros(n, m, 0);
            out << "  ------------Result------------" << Qt::endl;
            out << zeros;
        }
            break;

        case 3: {
            out << Qt::endl;
            out << "Enter martrix dimensions: " << Qt::endl;
            in >> n >> m;
            Matrix ones(n, m, 1);
            out << "  ------------Result------------" << Qt::endl;
            out << ones;
        }
            break;
        case 4: {
            out << Qt::endl;
            out << "Enter sub-matrix martrix dimensions: " << Qt::endl;
            in >> n >> m;
            out << "  ------------Result------------" << Qt::endl;
            currentMatrix.smallermatr(n,m).print();
        }
            break;
        case 5:
            out << "  ------------Result------------" << Qt::endl;
            currentMatrix.trans().print();
            break;
        case 6:
            out << Qt::endl;
            try {
                out << "Determimant: " << currentMatrix.det(currentMatrix.getCols()) << Qt::endl;
            } catch (MatrixException &exception) {
                err << "An matrix exception occurred (" << exception.getError() << ")" << Qt::endl;
                out << "Change current matrix and try again." << Qt::endl;
            }
            break;
        case 7: {
            out << Qt::endl;
            out << "Enter coordinates martrix element: " << Qt::endl;
            in >> n >> m;
            out << "Cofactor: " << currentMatrix.cofactor(n, m) << Qt::endl;
        }
            break;
        case 8:
            out << Qt::endl;
            try {
                currentMatrix.reverse().print();
            } catch (MatrixException &exception) {
                err << "An matrix exception occurred (" << exception.getError() << ")" << Qt::endl;
                out << "Change current matrix and try again." << Qt::endl;
            }
            break;
        case 9: {
            out << Qt::endl;
            out << "Enter the matrix you want to sum with the current one: " << Qt::endl;
            Matrix temp(currentMatrix.getCols(), currentMatrix.getRows(), 1);
            in >> temp;
            try {
                temp = currentMatrix + temp;
                out << "  ------------Result------------" << Qt::endl;
                temp.print();
            } catch (MatrixException &exception) {
                err << "An matrix exception occurred (" << exception.getError() << ")" << Qt::endl;
                out << "Change matrix you want to sum with the current one and try again." << Qt::endl;
            }
        }
            break;
        case 10: {
            out << Qt::endl;
            out << "Enter the matrix you want to subtract from the current one: " << Qt::endl;
            Matrix temp(currentMatrix.getCols(), currentMatrix.getRows(), 1);
            in >> temp;
            try {
                temp = currentMatrix - temp;
                out << "  ------------Result------------" << Qt::endl;
                temp.print();
            } catch (MatrixException &exception) {
                err << "An matrix exception occurred (" << exception.getError() << ")" << Qt::endl;
                out << "Change matrix you want to subtract from with the current one and try again." << Qt::endl;
            }
        }
            break;
        case 11: {
            out << Qt::endl;
            out << "Enter the number to multiply the matrix by: " << Qt::endl;
            in >> n;
            Matrix temp(1, 1, 0);
            temp = currentMatrix * n;
            out << "  ------------Result------------" << Qt::endl;
            out << temp;
        }
            break;
        case 12: {
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
                try {
                    temp = currentMatrix * v1;
                    out << "  ------------Result------------" << Qt::endl;
                    out << temp;
                } catch (MatrixException &exception) {
                    err << "An matrix exception occurred (" << exception.getError() << ")" << Qt::endl;
                    out << "Change vector dimension you want to multiplie and try again." << Qt::endl;
                }
            } else {
                out << "Enter " << currentMatrix.getRows() << " elements of vector: " << Qt::endl;
                Vector v1(currentMatrix.getRows(),0);
                QString s;
                for(int i=0; i <currentMatrix.getRows(); i++) {
                    in >> s;
                    v1.setVal(i, s.toDouble());
                }
                Matrix temp(1, 1, 0);
                try {
                    temp = currentMatrix * v1;
                    out << "  ------------Result------------" << Qt::endl;
                    out << temp;
                } catch (MatrixException &exception) {
                    err << "An matrix exception occurred (" << exception.getError() << ")" << Qt::endl;
                    out << "Change vector dimension you want to multiplie and try again." << Qt::endl;
                }
            }
            break;
        }
        case 13: {
            out << Qt::endl;
            out << "Enter the matrix to multiply the matrix by: " << Qt::endl;
            Matrix temp(1, 1, 0);
            in >> temp;
            try {
                temp = currentMatrix * temp;
                out << "  ------------Result------------" << Qt::endl;
                out << temp;
            } catch (MatrixException &exception) {
                err << "An matrix exception occurred (" << exception.getError() << ")" << Qt::endl;
                out << "Change matrix dimension you want to multiplie and try again." << Qt::endl;
            }
        }
            break;
        case 14: {
            out << Qt::endl;
            out << "We need to get the inverse to the next matrix: " << Qt::endl;
            Matrix temp(3, 3, 0);
            temp.setVal(1.1,0,0);
            temp.setVal(1.4,0,1);
            temp.setVal(1.5,0,2);
            temp.setVal(2.1,1,0);
            temp.setVal(3.2,1,1);
            temp.setVal(2.3,1,2);
            temp.setVal(3.1,2,0);
            temp.setVal(3.2,2,1);
            temp.setVal(3.3,2,2);
            out << temp;
            out << "Get the inverse of a matrix:" << Qt::endl;
            Matrix tempInv(3, 3, 0);
            tempInv = temp.reverse();
            out << tempInv;
            out << "Make a check:" << Qt::endl;
            out << "Multiply the original by the reverse:" << Qt::endl;
            Matrix resultM(3, 3, 0);
            resultM = temp * tempInv;
            out << "  ------------Result------------" << Qt::endl;
            out << resultM;
            out << "And vice versa:" << Qt::endl;
            resultM = tempInv * temp;
            out << "  ------------Result------------" << Qt::endl;
            out << resultM;
        }
            break;
        }

        if(option != 0)
            system("pause");
    } while (option != 0);

    return 0;
}
