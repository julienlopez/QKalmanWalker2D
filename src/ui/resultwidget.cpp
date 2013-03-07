#include "resultwidget.hpp"
#include <simulation/profile/profile.hpp>
#include <simulation/simulation.hpp>

#include <QVBoxLayout>
#include <QPen>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

ResultWidget::ResultWidget(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(800, 600);

    QVBoxLayout* layout = new QVBoxLayout;

    m_plotDataAccX = new QwtPlot(QwtText(tr("Acceleration Datas on X")));
    layout->addWidget(m_plotDataAccX);
    m_plotDataSpeedX = new QwtPlot(QwtText(tr("Speed Datas on X")));
    layout->addWidget(m_plotDataSpeedX);
    m_plotDataPosX = new QwtPlot(QwtText(tr("Position Datas on X")));
    layout->addWidget(m_plotDataPosX);

    setLayout(layout);
}

#include <QDebug>

void ResultWidget::display(boost::weak_ptr<Profile> profile_wk, const Simulation& simul)
{
    boost::shared_ptr<Profile> profile = profile_wk.lock();
    if(!profile)
    {
        qDebug() << "no profile to display!";
        return;
    }

    m_curves.clear();

    //acc x
    plotcurve_sp c(new QwtPlotCurve(QwtText(tr(""))));
    m_curves.push_back(c);
    c->setData(QVector<double>::fromStdVector(profile->sampleTime()), QVector<double>::fromStdVector(simul.realAccelerationX()));
    c->attach(m_plotDataAccX);
    c->setPen(QPen(Qt::green));

    c.reset(new QwtPlotCurve(QwtText(tr(""))));
    m_curves.push_back(c);
    c->setData(QVector<double>::fromStdVector(profile->sampleTime()), QVector<double>::fromStdVector(profile->accelerationX()));
    c->attach(m_plotDataAccX);
    c->setPen(QPen(Qt::red));

    m_plotDataAccX->replot();


    //speed x
    c.reset(new QwtPlotCurve(QwtText(tr(""))));
    m_curves.push_back(c);
    c->setData(QVector<double>::fromStdVector(profile->sampleTime()), QVector<double>::fromStdVector(simul.basicSpeedX()));
    c->setPen(QPen(Qt::green));
    c->attach(m_plotDataSpeedX);

    c.reset(new QwtPlotCurve(QwtText(tr(""))));
    m_curves.push_back(c);
    c->setData(QVector<double>::fromStdVector(profile->sampleTime()), QVector<double>::fromStdVector(profile->speedX()));
    c->setPen(QPen(Qt::red));
    c->attach(m_plotDataSpeedX);

    m_plotDataSpeedX->replot();


    //acc x
    c.reset(new QwtPlotCurve(QwtText(tr(""))));
    m_curves.push_back(c);
    c->setData(QVector<double>::fromStdVector(profile->sampleTime()), QVector<double>::fromStdVector(simul.basicPositionX()));
    c->setPen(QPen(Qt::green));
    c->attach(m_plotDataPosX);

    c.reset(new QwtPlotCurve(QwtText(tr(""))));
    m_curves.push_back(c);
    c->setData(QVector<double>::fromStdVector(profile->sampleTime()), QVector<double>::fromStdVector(profile->positionX()));
    c->setPen(QPen(Qt::red));
    c->attach(m_plotDataPosX);

    c.reset(new QwtPlotCurve(QwtText(tr(""))));
    m_curves.push_back(c);
    c->setData(QVector<double>::fromStdVector(profile->gpsSampleTime()), QVector<double>::fromStdVector(simul.gpsPositionX()));
    c->setPen(QPen(Qt::blue));
    c->setStyle(QwtPlotCurve::Sticks);
    QwtSymbol symbol;
    symbol.setPen(QPen(Qt::black));
    symbol.setBrush(QBrush(Qt::white));
    symbol.setSize(5);
    symbol.setStyle(QwtSymbol::Ellipse);
    c->setSymbol(symbol);
    c->attach(m_plotDataPosX);

    m_plotDataPosX->replot();
}
