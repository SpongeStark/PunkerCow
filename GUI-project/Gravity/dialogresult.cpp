#include "dialogresult.h"
#include "ui_dialogresult.h"

DialogResult::DialogResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResult)
{
    ui->setupUi(this);
}

DialogResult::~DialogResult()
{
    delete ui;
}

void DialogResult::initializeWindow(QPointF gravity, double area, bool isGravityInPolygon)
{
    ui->lbl_Gravity->setText(QString::asprintf("( %.2f , %.2f )",gravity.x(),gravity.y()) );
    ui->lbl_Area->setText(QString::asprintf("%.2f", area));
    ui->lbl_InPolygon->setText(QString::asprintf("%s",isGravityInPolygon?"YES":"NO"));
}
