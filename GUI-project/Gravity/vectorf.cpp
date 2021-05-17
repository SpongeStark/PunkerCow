#include "vectorf.h"

VectorF::VectorF(QPointF point1, QPointF point2)
{
    QPointF tempVector = point2 - point1;
    this->setX(tempVector.x());
    this->setY(tempVector.y());
}

double VectorF::operator*(const VectorF & vector)
{// result = x_u * x_v + y_u * y_v
    double result = 0;
    result += this->x() * vector.x();
    result += this->y() * vector.y();
    return result;
}

double VectorF::norm()
{
    double temp = this->x() * this->x() + this->y() * this->y();
    return sqrt(temp);
}

double VectorF::getAngle(VectorF v1, VectorF v2)
{
    return acos(v1 * v2 / (v1.norm() * v2.norm()));
}
