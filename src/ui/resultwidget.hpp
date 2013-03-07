#ifndef RESULTWIDGET_HPP
#define RESULTWIDGET_HPP

#include <QWidget>

#include <boost/weak_ptr.hpp>

class Profile;
class Simulation;

class QwtPlot;
class QwtPlotCurve;

class ResultWidget : public QWidget
{
    Q_OBJECT
public:
    typedef boost::shared_ptr<QwtPlotCurve> plotcurve_sp;

    explicit ResultWidget(QWidget *parent = 0);

    void display(boost::weak_ptr<Profile> profile_wk, const Simulation& simul);
private:
    QwtPlot* m_plotDataAccX;
    QwtPlot* m_plotDataAccY;
    QwtPlot* m_plotDataSpeedX;
    QwtPlot* m_plotDataSpeedY;
    QwtPlot* m_plotDataPosX;
    QwtPlot* m_plotDataPosY;

    std::list<plotcurve_sp> m_curves;
    
signals:
    
public slots:
    
};

#endif // RESULTWIDGET_HPP
