#include "dialogaddpoint.h"
#include "ui_dialogaddpoint.h"

DialogAddPoint::DialogAddPoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddPoint)
{
    ui->setupUi(this);
}

DialogAddPoint::~DialogAddPoint()
{
    delete ui;
}

QPointF DialogAddPoint::getPoint()
{
    double x = ui->abscissa->value();
    double y = ui->ordinate->value();
    return QPointF(x,y);
}
