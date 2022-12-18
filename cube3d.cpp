#include "cube3d.h"

Cube3D::Cube3D(Point3D center, double side, double phi, double theta)
    : Box3D(center, side, side, side)
{
    for(int i = 0; i < 8; i++){
        points[i] = &(points[i]->rotate(phi, theta));
    }
    m_side = side;
    m_rotated = true;
    m_phi = phi;
    m_theta = theta;
}
