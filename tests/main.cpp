#include <QTest>

#include "testsignal.hpp"

int main(int argc, char *argv[])
{
    TestSignal test1;
    QTest::qExec(&test1, argc, argv);
    
    return EXIT_SUCCESS;
}
