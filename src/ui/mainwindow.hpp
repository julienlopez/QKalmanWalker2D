#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtGui/QMainWindow>

class ResultWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    ResultWidget* m_resultWidget;

private slots:
    void launchSimulation();
};

#endif // MAINWINDOW_HPP
