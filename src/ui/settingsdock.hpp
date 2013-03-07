#ifndef SETTINGSDOCK_HPP
#define SETTINGSDOCK_HPP

#include <QDockWidget>

class QGroupBox;

class SettingsDock : public QDockWidget
{
    Q_OBJECT
public:
    explicit SettingsDock(QWidget *parent = 0);

private:
    QGroupBox* createGroupBoxProfile();
    QGroupBox* createGroupBoxOptions();

signals:
    void launchSimulation();

private slots:
    void onProfileSelected(const QString& str);
    void onCheckBoxNoisyGPSclicked(bool b);
};

#endif // SETTINGSDOCK_HPP
