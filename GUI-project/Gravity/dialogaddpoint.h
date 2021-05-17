#ifndef DIALOGADDPOINT_H
#define DIALOGADDPOINT_H

#include <QDialog>

namespace Ui {
class DialogAddPoint;
}

class DialogAddPoint : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddPoint(QWidget *parent = nullptr);
    ~DialogAddPoint();
    QPointF getPoint();

private:
    Ui::DialogAddPoint *ui;
};

#endif // DIALOGADDPOINT_H
