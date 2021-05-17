#ifndef VECTORF_H
#define VECTORF_H

#include <QPointF>

class VectorF : public QPointF
{
public:
    VectorF(double x, double y):QPointF(x,y){};
    VectorF(QPointF,QPointF);
    ~VectorF(){}
    //overload the operator
    double operator*(const VectorF&);
    //member function
    double norm(); //get the norm of this vector
    //static function
    static double getAngle(VectorF,VectorF);
};

#endif // VECTORF_H
