#include "Point.h"
#include "MathTK.h"
#include "PointF.h"
namespace StiGame
{

Point::Point(void)
{
	x = 0;
	y = 0;
}

Point::Point(PointStruct *pt)
{
    x = pt->x;
    y = pt->y;
}

Point::Point(int m_x, int m_y)
{
	x = m_x;
	y = m_y;
}

Point::Point(Point *pt)
{
    x = pt->getX();
    y = pt->getY();
}


Point::~Point(void)
{
}

int Point::getX(void)
{
	return x;
}


int Point::getY(void)
{
	return y;
}


PointStruct* Point::getPointStruct(void)
{
    PointStruct *pt = new PointStruct();
    pt->x = x;
    pt->y = y;

    return pt;
}

SDL_Point* Point::getSDLPoint(void)
{
    SDL_Point *pt = new SDL_Point();
    updateSDLPoint(pt);
    return pt;
}
void Point::updateSDLPoint(SDL_Point *sdlPt)
{
    sdlPt->x = x;
    sdlPt->y = y;
}

bool Point::equals(int m_x, int m_y)
{
    return (m_x == x && m_y == y);
}

bool Point::equals(Point *pt)
{
    return equals(pt->getX(), pt->getY());
}

bool Point::equals(SDL_Point *pt)
{
	return (
		x == pt->x &&
		y == pt->y
	);
}

Point Point::operator+(Point& pt)
{
    Point _pt(this->x + pt.getX(),
             this->y + pt.getY());

    return _pt;
}

Point Point::operator-(Point& pt)
{
    Point _pt(this->x - pt.getX(),
             this->y - pt.getY());

    return _pt;
}

Point Point::operator*(double scalar)
{
    Point pt(this->x * scalar, this->y * scalar);
    return pt;
}

Point Point::diffPoint(Point *pt)
{
    Point diffPt (pt->getX() - x, pt->getY() - y);
    return diffPt;
}

double Point::distanceWith(Point *pt)
{
    return Math::TK::DistanceBetween(this, pt);
}

PointF Point::toPointF()
{
    return PointF(x, y);
}

Math::Matrix Point::homogenousMatrix(void)
{
    Math::Matrix matrix (1, 3, 1.0f);
    matrix.set(0, 0, x);
    matrix.set(0, 1, y);
    return matrix;
}

}
