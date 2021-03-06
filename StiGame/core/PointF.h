#ifndef POINTF_H
#define POINTF_H

#include "MPoint.h"
#include "Matrix.h"

namespace StiGame
{

class PointF
{
public:
    PointF();
    PointF(float m_x, float m_y);
    PointF(PointF *pt);
    virtual ~PointF();

    float getX(void);
    float getY(void);

    virtual bool equals(float m_x, float m_y);
    virtual bool equals(PointF *pt);

    virtual Point toPoint(void);
    virtual MPoint toMPoint(void);

    PointF operator+(PointF& pt);
    PointF operator-(PointF& pt);
    PointF operator*(double scalar);

    Math::Matrix homogenousMatrix(void);

protected:
    float x;
    float y;

};


}
#endif // POINTF_H
