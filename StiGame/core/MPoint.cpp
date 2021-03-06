#include "MPoint.h"
namespace StiGame
{

MPoint::MPoint() :
    Point()
{
    //ctor
}

MPoint::MPoint(int m_x, int m_y) :
    Point(m_x, m_y)
{

}

MPoint::MPoint(PointStruct *pt) :
    Point(pt)
{

}

MPoint::MPoint(Point *pt) :
   Point(pt)
{

}

void MPoint::setPoint(Point *pt)
{
    x = pt->getX();
    y = pt->getY();
}

void MPoint::setPoint(int m_x, int m_y)
{
    x = m_x;
    y = m_y;
}

void MPoint::setX(int m_x)
{
    x = m_x;
}

void MPoint::setY(int m_y)
{
    y = m_y;
}

MPoint::~MPoint()
{
    //dtor
}

}
