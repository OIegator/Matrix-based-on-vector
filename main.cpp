#include <QCoreApplication>
#include "vector.h"
#include "matrix.h"
#include <QTextStream>
#include <QTest>
#include "test.h"

QTextStream out(stdout);
QTextStream in(stdin);



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTest::qExec(new Test, argc, argv);


    return 0;
}
