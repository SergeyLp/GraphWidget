#pragma once
#ifndef NOP_PRECOMPILE
//#include "Precompile.h"
#else
#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QWidget>
#endif

#ifndef DISABLE_ZOOM_BUTTONS
QT_BEGIN_NAMESPACE
class QToolButton;
QT_END_NAMESPACE
#endif // !DISABLE_ZOOM_BUTTONS

class PlotSettingsIntXAxis;

class GraphWidget : public QWidget{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = 0);
    void setPlotSettings(/*const PlotSettingsIntXAxis &settings*/);

private:
#ifndef DISABLE_ZOOM_BUTTONS
    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
#endif    
    bool rubberBandIsShown;

protected:
    int curZoom;


#if 0
    void setCurveData(int id, const QVector<QPointF> &data);
    void clearCurve(int id);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    void updateRubberBandRegion();
    void refreshPixmap();
    void drawGrid(QPainter *painter);
    void drawCurves(QPainter *painter);

    enum { Margin = 20 };

    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QMap<int, QVector<QPointF> > curveMap;
    QVector<PlotSettings> zoomStack;
    int curZoom;
    QRect rubberBandRect;
    QPixmap pixmap;
#endif //0
};

//#if 0
class PlotSettingsIntXAxis{
public:
    PlotSettingsIntXAxis(){};

    void scroll(int dx, int dy);
    void adjust();
    double spanX() const { return maxX - minX; }
    //double spanY() const { return maxY - minY; }

    int minX;
    int maxX;
    int numXTicks;
    //double minY;
    //double maxY;
    int numYTicks;

private:
    static void adjustAxisX(int &min, int &max, int &numTicks);
};

//#endif //0