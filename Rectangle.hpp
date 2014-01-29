#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle():Shape() {}
    Rectangle(wxRealPoint a, wxRealPoint b, wxColour color);
    ~Rectangle() {}   
    
    virtual int getClassId() const { return 4; }
};

#endif
