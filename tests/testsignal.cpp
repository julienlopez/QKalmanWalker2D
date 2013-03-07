#include "testsignal.hpp"

#include <utils/signal.hpp>

#include <QTest>

TestSignal::TestSignal(QObject *parent) :
    QObject(parent)
{
}

void TestSignal::testMean1()
{
    Signal s(1, 5);
    s[0] = 1;
    s[1] = 0;
    s[2] = -1;
    s[3] = -1;
    s[4] = 1;
    QCOMPARE(s.mean(), 0.);
}

void TestSignal::testMean2()
{
    Signal s(1, 10);
    s[0] = 1;
    s[1] = 1;
    s[2] = 1;
    s[3] = 1;
    s[4] = 1;
    s[5] = 1;
    s[6] = 1;
    s[7] = 1;
    s[8] = 1;
    s[9] = 1;
    QCOMPARE(s.mean(), 1.);
}

void TestSignal::testVariance1()
{
    Signal s(1, 5);
    s[0] = 1;
    s[1] = 1;
    s[2] = 1;
    s[3] = 1;
    s[4] = 1;
    QCOMPARE(s.variance(), 0.);
}

void TestSignal::testVariance2()
{
    Signal s(1, 4);
    s[0] = 1;
    s[1] = -1;
    s[2] = 1;
    s[3] = -1;
    QCOMPARE(s.variance(), 1.);
}

void TestSignal::testNoise1()
{
    Signal s = Signal::noise(1, 10, 0, 1);
    QVERIFY(fuzzyCompare(s.mean(), 0., 1E-15));
    QCOMPARE(s.variance(), 1.);
}

void TestSignal::testNoise2()
{
    Signal s = Signal::noise(1, 10, 1, 5);
    QVERIFY(fuzzyCompare(s.mean(), 1., 1E-15));
    QCOMPARE(s.variance(), 5.);
}
