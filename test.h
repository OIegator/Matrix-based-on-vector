#ifndef TEST_H
#define TEST_H

#include <QTest>
#include <QObject>

class Test: public QObject
{
    Q_OBJECT
public:
    Test();
};

#endif // TEST_H
