#include "vecmat.h"

Vector::Vector() {
    data[0] = 0.0; 
    data[1] = 0.0; 
    data[2] = 0.0; 
    data[3] = 1.0;
}

/******************************************************************************/

void Vector::print() {
    printf("(%2.3lf,%2.3lf,%2.3lf,%2.3lf)\n", data[0], data[1], data[2], data[3]);
}

/******************************************************************************/

void Vector::set(double d1, double d2, double d3) {
    data[0] = d1; 
    data[1] = d2; 
    data[2] = d3;
}

/******************************************************************************/

void Vector::norm() {
    for(int i = 0; i < 4; ++i) {
        data[i] /= data[3];
    }
}

/******************************************************************************/

void Vector::focus(double d) {
    for(int i = 0; i < 2; ++i) {
        data[i] *= (d / (d + (data[2])));
    }
    data[2] = 0.0;
}

/******************************************************************************/

double Vector::getX() {
    return data[0];
}

/******************************************************************************/

double Vector::getY() {
    return data[1];
}

/******************************************************************************/

double Vector::getZ() {
	return data[2];
}

/******************************************************************************/

Matrix::Matrix() {
    data[0][0] = 0.0; data[0][1] = 0.0; data[0][2] = 0.0; data[0][3] = 0.0;
    data[1][0] = 0.0; data[1][1] = 0.0; data[1][2] = 0.0; data[1][3] = 0.0;
    data[2][0] = 0.0; data[2][1] = 0.0; data[2][2] = 0.0; data[2][3] = 0.0;
    data[3][0] = 0.0; data[3][1] = 0.0; data[3][2] = 0.0; data[3][3] = 1.0;
}

/******************************************************************************/

void Matrix::print() {
    printf("\n|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[0][0], data[0][1], data[0][2], data[0][3]);
    printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[1][0], data[1][1], data[1][2], data[1][3]);
    printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[2][0], data[2][1], data[2][2], data[2][3]);
    printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[3][0], data[3][1], data[3][2], data[2][3]);
}

/******************************************************************************/

Matrix Matrix::operator*(const Matrix gMatrix) {
    Matrix tmp;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            tmp.data[i][j] = 0.0;
            for(int k = 0; k < 4; k++) {
                tmp.data[i][j] = tmp.data[i][j] + (data[i][k] * gMatrix.data[k][j]);
            }
        }
    }
    return tmp;
}

/******************************************************************************/

Vector operator*(const Matrix gMatrix, const Vector gVector) {
    Vector tmp;

    for(int i = 0; i < 4; i++) {
        tmp.data[i] = 0.0;
        for(int j = 0; j < 4; j++) {
            tmp.data[i] = tmp.data[i] + (gMatrix.data[i][j] * gVector.data[j]);
        }
    }
    return tmp;
}

/******************************************************************************/
 
Matrix scale(double sx, double sy, double sz) {
    Matrix ret;
    ret.data[0][0] = sx;
    ret.data[1][1] = sy;
    ret.data[2][2] = sz;
    return ret;
}

/******************************************************************************/

Matrix rotateX(double a) {
    Matrix ret;
    a *= M_PI;
    a /= 180.0;
    ret.data[0][0] = 1.0;
    ret.data[1][1] = cos(a);
    ret.data[1][2] = sin(a);
    ret.data[2][1] = -sin(a);
    ret.data[2][2] = cos(a);
    ret.data[3][3] = 1.0;
    return ret;
}

/******************************************************************************/

Matrix rotateY(double a) {
    Matrix ret;
    a *= M_PI;
    a /= 180.0;
    ret.data[0][0] = cos(a);
    ret.data[2][0] = sin(a);
    ret.data[0][2] = -sin(a);
    ret.data[2][2] = cos(a);
    ret.data[1][1] = 1.0;
    ret.data[3][3] = 1.0;
    return ret;
}

/******************************************************************************/

Matrix rotateZ(double a) {
    Matrix ret;
    a *= M_PI;
    a /= 180.0;;
    ret.data[2][2] = 1.0;
    ret.data[0][0] = cos(a);
    ret.data[0][1] = sin(a);
    ret.data[1][0] = -sin(a);
    ret.data[1][1] = cos(a);
    return ret;
}

/******************************************************************************/
 
Matrix translation(double x, double y, double z) {
    Matrix ret;
    ret.data[0][0] = 1.0;
    ret.data[1][1] = 1.0;
    ret.data[2][2] = 1.0;
    ret.data[3][3] = 1.0;
    ret.data[0][3] = x;
    ret.data[1][3] = y;
    ret.data[2][3] = z;
    return ret;
}

/******************************************************************************/
 
Matrix depth(double d) {
    Matrix ret;
    ret.data[0][0] = 1.0;
    ret.data[1][1] = 1.0;
    ret.data[2][2] = 0.0;
    ret.data[3][2] = 1.0 / d;      
}
