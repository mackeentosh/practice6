#include "box3d.h"
#include <cmath>
using namespace std;

Box3D::Box3D(Point3D a, Point3D b) {

    points =  new Point3D*[8];
    double side_x = a.get_x() - b.get_x();
    double side_y = a.get_y() - b.get_y();
    double side_z = a.get_z() - b.get_z();

    m_side_x = abs(side_x);
    m_side_y = abs(side_y);
    m_side_z = abs(side_z);

    int i = 0;
    for (int ix = 0; ix < 2; ix++)
    {
        double x = b.get_x() + (ix * side_x);
        for (int iy = 0; iy < 2; iy++)
        {
            double y = b.get_y() + (iy * side_y);
            for(int iz = 0; iz < 2; iz++, i++)
            {
                double z = b.get_z() + (iz * side_z);
                points[i] = new Point3D(x,y,z);
            }
        }
    }
}



Box3D::Box3D(Point3D a, double side_x, double side_y, double side_z)
{
    points = new Point3D*[8];
    int i = 0;
    for (int ix = 1; ix >= -1; ix -= 2)
    {
        double x = a.get_x() + (ix * side_x/2);
        for (int iy = 1; iy >= -1; iy -= 2)
        {
            double y = a.get_y() + (iy * side_y/2);
            for(int iz = 1; iz >= -1; iz -= 2, i++)
            {
                double z = a.get_z() + (iz * side_z/2);
                points[i] = new Point3D(x,y,z);
            }
        }
    }
    m_side_x = side_x;
    m_side_y = side_y;
    m_side_z = side_z;
}

bool hasIntersectionLine(double min1, double max1, double min2, double max2){
    return (max1 <= max2 && max1 > min2) ||
            (max1 > max2 && max2 > min1);
}



bool Box3D::hasIntersection(Box3D& other) {

    bool hasIntersectionX = false;
    bool hasIntersectionY = false;
    bool hasIntersectionZ = false;
    auto th_max = points[0];
    auto ot_max = other.points[0];

    //проверка пересечения по X
    auto th_min = points[1];
    auto ot_min = other.points[1];
    for(int i = 1; i < 8; i++){
        auto p = points[i];
        if (p->get_y() == th_max->get_y() && p->get_z() == th_max->get_z()){
            if (p->get_x() > th_max->get_x())
            {
                th_min = th_max;
                th_max = p;
            }
            else
                th_min = p;
            break;
        }
    }
    for(int i = 1; i < 8; i++){
        auto p = other.points[i];
        if (p->get_y() == ot_max->get_y() && p->get_z() == ot_max->get_z()){
            if (p->get_x() > ot_max->get_x())
            {
                ot_min = ot_max;
                ot_max = p;
            }
            else
                ot_min = p;
            break;
        }
    }
    hasIntersectionX = hasIntersectionLine(th_min->get_x(), th_max->get_x(), ot_min->get_x(), ot_max->get_x());

    //проверка пересечения по Y
    th_max = points[0];
    ot_max = other.points[0];
    for(int i = 1; i < 8; i++){
        auto p = points[i];
        if (p->get_x() == th_max->get_x() && p->get_z() == th_max->get_z()){
            if (p->get_y() > th_max->get_y())
            {
                th_min = th_max;
                th_max = p;
            }
            else
                th_min = p;
            break;
        }
    }
    for(int i = 1; i < 8; i++){
        auto p = other.points[i];
        if (p->get_x() == ot_max->get_x() && p->get_z() == ot_max->get_z()){
            if (p->get_y() > ot_max->get_y())
            {
                ot_min = ot_max;
                ot_max = p;
            }
            else
                ot_min = p;
            break;
        }
    }
    hasIntersectionY = hasIntersectionLine(th_min->get_y(), th_max->get_y(), ot_min->get_y(), ot_max->get_y());


    //проверка пересечения по Z
    th_max = points[0];
    ot_max = other.points[0];
    for(int i = 1; i < 8; i++){
        auto p = points[i];
        if (p->get_x() == th_max->get_x() && p->get_y() == th_max->get_y()){
            if (p->get_z() > th_max->get_z())
            {
                th_min = th_max;
                th_max = p;
            }
            else
                th_min = p;
            break;
        }
    }

    for(int i = 1; i < 8; i++){
        auto p = other.points[i];
        if (p->get_x() == ot_max->get_x() && p->get_y() == ot_max->get_y()){
            if (p->get_z() > ot_max->get_z())
            {
                ot_min = ot_max;
                ot_max = p;
            }
            else
                ot_min = p;
            break;
        }
    }
    hasIntersectionZ = hasIntersectionLine(th_min->get_z(), th_max->get_z(), ot_min->get_z(), ot_max->get_z());
    return hasIntersectionX && hasIntersectionY && hasIntersectionZ;
}
