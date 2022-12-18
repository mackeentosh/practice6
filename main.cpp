#include "cube3d.h"
#include <QCoreApplication>
#include <iostream>
using namespace std;

bool test1(){
    Cube3D cube1(Point3D(0.5,0.5,0.5), 0.5);
    Cube3D cube2(Point3D(0.5,0.5,0.5), 0.5);
    return cube1.hasIntersection(cube2);
}

void check_tests(){
    if (test1())
        cout << "Test 1 ACCEPTED!" << '\n';
    else
        cout << "Test 1 NOT ACCEPTED!" << '\n';
}

int main(int argc, char *argv[])
{
    check_tests();
    QCoreApplication a(argc, argv);
    return a.exec();
}
