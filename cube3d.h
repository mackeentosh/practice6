#ifndef CUBE3D_H
#define CUBE3D_H
#include "box3d.h"

class Cube3D : public Box3D
{
public:
    Cube3D(Point3D center, double side) :
        Box3D(center, side, side, side), m_side(side), m_rotated(false) {}

    Cube3D(Point3D a, double side, double phi, double theta);

    double get_side() { return m_side; }
    bool is_rotated() { return m_rotated; }
    double get_phi() { return m_phi; }
    double get_theta() { return m_theta; }

private:
    double m_side;
    bool m_rotated;
    double m_phi;
    double m_theta;
};

#endif // CUBE3D_H
