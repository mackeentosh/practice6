#ifndef BOX3D_H
#define BOX3D_H
#include "point3d.h"

class Box3D
{
public:
    bool hasIntersection(Box3D& other);
    double get_side_x() { return m_side_x; };
    double get_side_y() { return m_side_y; };
    double get_side_z() { return m_side_z; };

    Box3D(Point3D a, Point3D b);
    Box3D(Point3D center, double side_x, double side_y, double side_z);

protected:
    Point3D **points;
    double m_side_x;
    double m_side_y;
    double m_side_z;
};

#endif // BOX3D_H
