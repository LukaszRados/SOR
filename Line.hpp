#ifndef _LINE_HPP_
#define _LINE_HPP_

#include "Shape.hpp"

class Line : public Shape {
public:
    Line():Shape() {}
    Line(wxRealPoint a, wxRealPoint b, wxColour color);
    virtual ~Line() {};
    virtual int getClassId() const { return 1; }
private:
        
};

#endif
