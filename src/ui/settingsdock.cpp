#include "settingsdock.hpp"
#include <simulation/profile/profilehandler.hpp>
#include <simulation/profile/profile.hpp>

#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>

SettingsDock::SettingsDock(QWidget *parent) :
    QDockWidget(parent)
{
    QWidget* w = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(createGroupBoxProfile());
    layout->addWidget(createGroupBoxOptions());

    QPushButton* b = new QPushButton(tr("Simulate"));
    connect(b, SIGNAL(clicked()), this, SIGNAL(launchSimulation()));
    layout->addWidget(b);

    layout->addStretch();
    w->setLayout(layout);
    setWidget(w);
}

QGroupBox* SettingsDock::createGroupBoxProfile()
{
    QGroupBox* res = new QGroupBox(tr("Simulation Profile"));
    QVBoxLayout* vl = new QVBoxLayout;

    QComboBox* combo = new QComboBox;
    QStringList lst;
    ProfileHandler::type_map::const_iterator i = ProfileHandler::begin();
    ProfileHandler::type_map::const_iterator i_end = ProfileHandler::end();
    for(; i != i_end; ++i)
        lst << QString::fromStdString(i->first);
    combo->addItems(lst);
    vl->addWidget(combo);

    combo->setCurrentIndex(combo->findText(QString::fromStdString(ProfileHandler::current()->id())));
    connect(combo, SIGNAL(currentIndexChanged(QString)), this, SLOT(onProfileSelected(QString)));

    res->setLayout(vl);
    return res;
}

QGroupBox* SettingsDock::createGroupBoxOptions()
{
    QGroupBox* res = new QGroupBox(tr("Simulation Options"));
    QVBoxLayout* vl = new QVBoxLayout;

    QCheckBox* chbNoisyGPS = new QCheckBox(tr("add noise to GPS position"));
    chbNoisyGPS->setChecked(ProfileHandler::current()->noisyGPS());
    connect(chbNoisyGPS, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxNoisyGPSclicked(bool)));
    vl->addWidget(chbNoisyGPS);

    res->setLayout(vl);
    return res;
}

void SettingsDock::onProfileSelected(const QString& str)
{
    ProfileHandler::setCurrent(str.toStdString());
}

void SettingsDock::onCheckBoxNoisyGPSclicked(bool b)
{
    ProfileHandler::current()->setNoisyGPS(b);
}
