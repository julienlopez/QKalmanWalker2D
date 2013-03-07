#include <QtGui/QApplication>
#include "ui/mainwindow.hpp"

#include <ctime>

#include <simulation/profile/profilehandler.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    ProfileHandler::loadProfiles();

    MainWindow w;
    w.show();
    
    return a.exec();
}
