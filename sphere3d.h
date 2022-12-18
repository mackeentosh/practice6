#ifndef SPHERE3D_H
#define SPHERE3D_H
#include "box3d.h"

class Sphere3D : public Box3D
{
public:

    Sphere3D(Point3D center, double radius) :
        Box3D(center, radius*2, radius*2, radius*2), m_center(center), m_radius(radius) {}

    Point3D& get_center() { return m_center; }
    double get_radius() { return m_radius; }

protected:
    Point3D m_center;
    double m_radius;

};

#endif // SPHERE3D_H
