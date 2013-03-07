#include "mainwindow.hpp"
#include "settingsdock.hpp"
#include "resultwidget.hpp"

#include <simulation/profile/profilehandler.hpp>
#include <simulation/simulation.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SettingsDock* settingsdock = new SettingsDock;
    addDockWidget(Qt::LeftDockWidgetArea, settingsdock, Qt::Vertical);
    connect(settingsdock, SIGNAL(launchSimulation()), this, SLOT(launchSimulation()));

    m_resultWidget = new ResultWidget;
    setCentralWidget(m_resultWidget);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::launchSimulation()
{
    Simulation::instance().run(ProfileHandler::current());
    m_resultWidget->display(ProfileHandler::current(), Simulation::instance());
}
