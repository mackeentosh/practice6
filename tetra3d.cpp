#include "tetra3d.h"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

double getMin(double *vals, size_t size) {
    double min = vals[0];
    for (int i = 1; i < size; i++)
        if (vals[i] < min)
            min = vals[i];
    return min;
}

double getMax(double *vals, size_t size) {
    double max = vals[0];
    for (int i = 1; i < size; i++)
        if (vals[i] > max)
            max = vals[i];
    return max;
}

Box3D Tetra3D::getBox(Point3D &a, Point3D &b, Point3D &c, Point3D &d){
    double *vals = new double[4] { a.get_x(), b.get_x(), c.get_x(), d.get_x() };
    double min_x = getMin(vals, 4);
    double max_x = getMax(vals, 4);
    delete[] vals;

    vals = new double[4] { a.get_y(), b.get_y(), c.get_y(), d.get_y() };
    double min_y = getMin(vals, 4);
    double max_y = getMax(vals, 4);
    delete[] vals;

    vals = new double[4] { a.get_z(), b.get_z(), c.get_z(), d.get_z() };
    double min_z = getMin(vals, 4);
    double max_z = getMax(vals, 4);
    delete[] vals;

    Point3D min(min_x, min_y, min_z);
    Point3D max(max_x, max_y, max_z);
    return Box3D(min, max);
}
