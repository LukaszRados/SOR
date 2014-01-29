#ifndef _VECMAT_H_
#define _VECMAT_H_

#include <cstdio>
#include <cmath>
#include <vector>

class Vector {
public:
    Vector();
    void print();
    void set(double d1, double d2, double d3);
    void norm();
    void focus(double d);
    double getX();
    double getY();
    double getZ();
 
    double data[4];
};

class Matrix {
public:
    Matrix();
    void print();
    Matrix operator*(const Matrix);
    friend Vector operator*(const Matrix, const Vector);
    
    double data[4][4];
};

Matrix scale(double sx, double sy = 1.0, double sz = 1.0);
Matrix rotateX(double a);
Matrix rotateY(double a);
Matrix rotateZ(double a);
Matrix translation(double x, double y = 0.0, double z = 0.0);
Matrix depth(double d);
 
#endif
