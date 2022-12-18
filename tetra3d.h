#ifndef TETRA3D_H
#define TETRA3D_H
#include "box3d.h"

class Tetra3D : public Box3D
{
public:
    Tetra3D(Point3D a, Point3D b, Point3D c, Point3D d) :
        Box3D(getBox(a,b,c,d)), m_a(a), m_b(b), m_c(c), m_d(d) {}

    Box3D getBox(Point3D& a, Point3D& b, Point3D& c, Point3D& d);
private:
    Point3D m_a;
    Point3D m_b;
    Point3D m_c;
    Point3D m_d;
};

#endif // TETRA3D_H
