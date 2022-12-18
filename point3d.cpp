#include "point3d.h"
#include <cmath>

Point3D::Point3D(double x, double y, double z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

Point3D& Point3D::rotate(double phi, double theta){

    double rho_ = sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
    double theta_ = atan2(sqrt(m_x*m_x + m_y*m_y), m_z) + theta;
    double phi_ = atan2(m_y, m_x) + phi;

    double x = rho_*sin(theta_)*cos(phi_);
    double y = rho_*sin(theta_)*sin(phi_);
    double z = rho_*cos(theta_);
    Point3D p(x, y, z);
    return p;
}
