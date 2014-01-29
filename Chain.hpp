#ifndef _CHAIN_HPP_
#define _CHAIN_HPP_

#include "Shape.hpp"

class Chain : public Shape {
public:
    Chain():Shape() {}
    Chain(wxRealPoint a, wxRealPoint b, wxColour color);
    virtual ~Chain() {}
    virtual int getClassId() const { return 3; }
    
private:
};

#endif
