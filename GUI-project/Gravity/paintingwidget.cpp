#include "paintingwidget.h"
#include "ui_paintingwidget.h"
#include <QtDebug>

PaintingWidget::PaintingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaintingWidget)
{
    ui->setupUi(this);
    //pen for normal point, color is black, style is roundCap
    _PenForPoint = QPen(Qt::black, 10);
    _PenForPoint.setCapStyle(Qt::RoundCap);
    //pen for gravity point, color is red, style is roundCap
    _PenForGravity = QPen(Qt::red, 10);
    _PenForGravity.setCapStyle(Qt::RoundCap);
    //pen for line between the normal points, color is gray
    _PenForLine = QPen(Qt::gray,2);
    //pen for background, color is green
    _PenForBackground = QPen(Qt::darkGreen);

    //set the default size of canvas to 500*500, format as 32bit RGB (0xffRRGGBB)
    _Image = QImage(500,500,QImage::Format_RGB32);
    //fill with green
    _Image.fill(Qt::darkGreen);

    //set the default border
    xMin = -1;
    yMin = -1;
    xMax = 1;
    yMax = 1;
}

PaintingWidget::~PaintingWidget()
{
    delete ui;
}

// paint event
void PaintingWidget::paintEvent(QPaintEvent *)
{
    //creat a paintor, then point out where to paint
    //because it's in the "painteingwidget", so "this" is this wedget
    QPainter painter(this);
    //paint the canvas to the "painteingwidget"
    painter.drawImage(this->rect(), _Image, _Image.rect());
}

void PaintingWidget::addPointToImage(QPointF point)
{
    //Decide the pen width according to the current window size
    int minSide = (this->width() < this->height() ? this->width() : this->height());
    _PenForPoint.setWidth(minSide/40);
    //Get the abscissa and ordinate relative to the canvas
    const double posX = _Image.width() * (point.x() - xMin) / (xMax-xMin);
    const double posY = _Image.height() * (yMax - point.y()) / (yMax-yMin);
    //Create a point
    const QPointF painterPosition(posX, posY);
    //Create a painter, then assign the "Image" as his canvas
    QPainter painter(&_Image);
    //assign the pen (which is black and 10 width)
    painter.setPen(_PenForPoint);
    //paint the point
    painter.drawPoint(painterPosition);
}

void PaintingWidget::addPoint(QPointF point)
{
    this->addPointToImage(point);
    //refresh the canvas
    update();
}

void PaintingWidget::addLineToImage(QPointF point1, QPointF point2)
{
    _PenForLine.setWidth(_PenForPoint.width()/3);
    const double p1X = _Image.width() * (point1.x() - xMin) / (xMax-xMin);
    const double p1Y = _Image.height() * (yMax - point1.y()) / (yMax-yMin);
    const double p2X = _Image.width() * (point2.x() - xMin) / (xMax-xMin);
    const double p2Y = _Image.height() * (yMax - point2.y()) / (yMax-yMin);
    QPainter painter(&_Image);
    painter.setPen(_PenForLine);
    painter.drawLine(p1X,p1Y,p2X,p2Y);
}

void PaintingWidget::addLine(QPointF point1, QPointF point2)
{
    this->addLineToImage(point1, point2);
    update();
}

void PaintingWidget::resetSize(Polygon& polygon)
{
    //reset the size of canvas, format like 32bit of RGB image (0xffRRGGBB)
    _Image = QImage(this->width(),this->height(),QImage::Format_RGB32);
    repaint(polygon);
}

void PaintingWidget::repaint(Polygon& polygon)
{
    this->clear();
    qApp->processEvents();
    polygon.assignBorder(&xMin, &xMax, &yMin, &yMax);
    double marginX = (xMax-xMin)/20.0;
    double marginY = (yMax-yMin)/20.0;
    double margin = marginX>marginY ? marginX : marginY;
    xMin -= margin;
    xMax += margin;
    yMin -= margin;
    yMax += margin;
    int length = polygon.countPoints();
    //set the width of the pen according to the windows size
    int minSide = (this->width() < this->height() ? this->width() : this->height());
    _PenForPoint.setWidth(minSide/40);
    //re-add all the point and line
    //the line first
    if(_PenForPoint.width() > 6 && length >1)
    {//if the points are large enough, and more than 2 points, we add the line
        _PenForLine.setWidth(_PenForPoint.width()/3);
        for(int i=0; i<length-1; i++)
        {
            addLineToImage(polygon.pointAt(i),polygon.pointAt(i+1));
        }
    }
    //the the points, they cover the end of lines
    for(int i=0; i<length; i++)
    {
        addPointToImage(polygon.pointAt(i));
    }
    update();
}

void PaintingWidget::clear()
{
    //fill with green
    _Image.fill(Qt::darkGreen);
    //refresh the process
    qApp->processEvents();
    update();
}

void PaintingWidget::paintGravity(QPointF point)
{
    //Decide the pen width according to the current window size
    int minSide = (this->width() < this->height() ? this->width() : this->height());
    _PenForGravity.setWidth(minSide/40);
    //Get the abscissa and ordinate relative to the canvas
    const double posX = _Image.width() * (point.x() - xMin) / (xMax-xMin);
    const double posY = _Image.height() * (yMax - point.y()) / (yMax-yMin);
    //Create a point
    const QPointF painterPosition(posX, posY);
    //Create a painter, then assign the "Image" as his canvas
    QPainter painter(&_Image);
    //assign the pen (which is black and 10 width)
    painter.setPen(_PenForGravity);
    //paint the point
    painter.drawPoint(painterPosition);
    update();
}
