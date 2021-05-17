#ifndef PAINTINGWIDGET_H
#define PAINTINGWIDGET_H

#include <QPen>
#include <QPoint>
#include <QImage>
#include <QWidget>
#include <QPainter>
#include "polygon.h"

namespace Ui {
class PaintingWidget;
}

class PaintingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PaintingWidget(QWidget *parent = nullptr);
    ~PaintingWidget();
    void addPointToImage(QPointF);
    void addPoint(QPointF);
    void addLineToImage(QPointF,QPointF);
    void addLine(QPointF,QPointF);
    void resetSize(Polygon&);
    void repaint(Polygon&);
    void clear();
    void paintGravity(QPointF);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::PaintingWidget *ui;
    QImage _Image;
    QPen _PenForPoint;
    QPen _PenForLine;
    QPen _PenForBackground;
    QPen _PenForGravity;
    double xMin, xMax;
    double yMin, yMax;
};

#endif // PAINTINGWIDGET_H
