#ifndef TEST_H
#define TEST_H

#include <QTest>
#include <QObject>

class Test: public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
private slots:

    void test_smaller();
    void test_det();
    void test_trans();
    void test_rev();
    void test_cofactor();

    void test_operators();
};

#endif // TEST_H
