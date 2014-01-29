#include "Rectangle.hpp"

Rectangle::Rectangle(wxRealPoint a, wxRealPoint b, wxColour color) {
    _points.push_back(a);
    _points.push_back(wxRealPoint(a.x, b.y));
    _points.push_back(b);    
    _points.push_back(wxRealPoint(b.x, a.y));
    _color = color;
}

