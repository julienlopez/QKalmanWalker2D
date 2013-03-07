#ifndef TESTSIGNAL_HPP
#define TESTSIGNAL_HPP

#include <QObject>

class TestSignal : public QObject
{
    Q_OBJECT
public:
    explicit TestSignal(QObject *parent = 0);
    
private slots:
    void testMean1();
    void testMean2();

    void testVariance1();
    void testVariance2();

    void testNoise1();
    void testNoise2();

    static inline bool fuzzyCompare(double p1, double p2, double delta)
    {
        return qAbs(p1 - p2) <= delta;
    }
};

#endif // TESTSIGNAL_HPP
