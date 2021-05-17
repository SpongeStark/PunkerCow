#include "dialogaddpoint.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogresult.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _Polygon = Polygon();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint()
{
    //create a dialog "add point"
    DialogAddPoint dialogAddPoint;
    //execute the dialog and get the return number
    int returnNumber = dialogAddPoint.exec();
    if(QDialog::Accepted == returnNumber)
    {//if it was "Accepted" (the "valid" was clicked)
        //get the coordinate
        QPointF newPoint = dialogAddPoint.getPoint();
        if(_Polygon.addPoint(newPoint))
        {//if we add the point successly
            //add the point to the UI-List
            QString stringBuffer = QString::asprintf("%d|: (%.2f , %.2f)",\
                                   _Polygon.countPoints(),newPoint.x(),newPoint.y());
            ui->list_points->addItem(stringBuffer);
            ui->widget_field->repaint(_Polygon);
            /*
            //add the lines on the canvas
            if(_Polygon.countPoints() > 1)
            {//there are more than two points, so we add the line
                QPointF lastPoint = _Polygon.pointAt(_Polygon.countPoints()-2);
                ui->widget_field->addLine(lastPoint, newPoint);
                //add the point which is on the end line
                ui->widget_field->addPoint(lastPoint);
            }
            //add the point, and cover the two end of the line
            ui->widget_field->addPoint(newPoint);
            */
        }
        else
        {//if we can't add the point, that's to say we have had the same point
            QMessageBox::warning(this,"Error","The point has existed!");
        }
    }
}

void MainWindow::removeLastPoint()
{
    if(_Polygon.removeLastPoint())
    {
        ui->list_points->removeItemWidget(ui->list_points->takeItem(_Polygon.countPoints()));
    }
    ui->widget_field->repaint(_Polygon);
}

void MainWindow::clear()
{
    _Polygon.clearAllPoints();
    ui->list_points->clear();
    ui->widget_field->clear();
}

void MainWindow::showResult()
{
    if(_Polygon.countPoints() >= 3)
    {
        //prepare for the result dialog
        QPointF gravity = _Polygon.getGravity();
        double area = _Polygon.getArea();
        bool isGravityInPolygon = _Polygon.isPointInPolygon(gravity);
        DialogResult result;
        result.initializeWindow(gravity, area, isGravityInPolygon);
        //connect the first and the last point
        ui->widget_field->addLine(_Polygon.pointAt(0), _Polygon.pointAt(_Polygon.countPoints()-1));
        ui->widget_field->addPoint(_Polygon.pointAt(0));
        ui->widget_field->addPoint(_Polygon.pointAt(_Polygon.countPoints()-1));
        //paint the gravity
        ui->widget_field->paintGravity(gravity);
        qApp->processEvents();
        //show the result dialog
        result.exec();
    }
    else
    {
        QMessageBox::warning(this,"Error","The points are NOT enough!");
    }

}

/*
void MainWindow::addPoint()
{
    // 新建一个“添加点”对话框
    DialogAddPoint dialogAddPoint;
    // 执行并获得返回值
    int returnNumber = dialogAddPoint.exec();
    if (QDialog::Accepted == returnNumber)
    { // 如果返回值为Accepted（点击了确定）
        // 获得点坐标
        QPoint pointBuffer = dialogAddPoint.getPoint();
        if (!_Points.contains(pointBuffer))
        {
            QPoint newPoint = pointBuffer;
            // 在List上添加一个项目
            QString stringBuffer = QString::asprintf("%d|: (%d , %d)",\
                                   _Points.length()+1,newPoint.x(),newPoint.y());
            ui->list_points->addItem(stringBuffer);
            // 添加至_Points存储
            _Points.append(pointBuffer);
            //给图添加线
            if(_Points.length() > 1)
            {//有两个以上，所以开始连线
                QPoint lastPoint = _Points[_Points.length()-2];
                ui->widget_field->addLine(lastPoint, newPoint);
                if(_Points.length() > 2)
                {//有三个以上的点，所以开始组成封闭图形
                    //首先去掉p[0]和p[N-2]之间的线
                    //然后画p[0]和p[N-1]之间的线
                    //最后重新绘制p[0]点，覆盖线的端点
                }
                ui->widget_field->addPoint(lastPoint);
            }
            //然后添加点，覆盖线的两端
            ui->widget_field->addPoint(newPoint);
        }
        else
        { // 如果点已经存在，就发送错误报告
            QMessageBox::warning(this,"Error","The point has existed!");
        }

    }
}
*/

void MainWindow::resizeEvent(QResizeEvent *)
{
    ui->widget_field->resetSize(_Polygon);
}

