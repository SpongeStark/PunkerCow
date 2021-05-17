#ifndef DIALOGRESULT_H
#define DIALOGRESULT_H

#include <QDialog>

namespace Ui {
class DialogResult;
}

class DialogResult : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResult(QWidget *parent = nullptr);
    ~DialogResult();

    void initializeWindow(QPointF gravity, double area, bool isGravityInPolygon);

private:
    Ui::DialogResult *ui;
};

#endif // DIALOGRESULT_H
