#ifndef POINT3D_H
#define POINT3D_H

class Point3D
{
public:
    Point3D(double x, double y, double z);

    double get_x() { return m_x; };
    double get_y() { return m_y; };
    double get_z() { return m_z; };
    Point3D& rotate(double phi, double theta);

private:
    double m_x;
    double m_y;
    double m_z;
};

#endif // POINT3D_H
