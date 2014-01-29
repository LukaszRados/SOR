#include "Chain.hpp"

Chain::Chain(wxRealPoint a, wxRealPoint b, wxColour color) {
    _points.push_back(a);
    _points.push_back(b);
    _color = color;
}
