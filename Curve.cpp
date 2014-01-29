#include "Curve.hpp"

Curve::Curve(wxRealPoint a, wxRealPoint b, wxColour color):Shape(), _N(50) {
    _points.push_back(a);
    _points.push_back(b);
    _color = color;
     
    double x, y;
    x = (a.x + b.x) / 2.f;
    y = (a.y + b.y) / 2.f;
    _bend = wxRealPoint(x, y);
}

void Curve::changeBend(wxRealPoint bend) {
    _bend = bend;
    
    wxRealPoint p0 = _points[0],
                p1 = _points[1];
           
    double d = sqrt(pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2)),  // Odleglosc miedzy p0, p1
           // ------------------------------------------------------------------
           A, //  Dane prostej przechodzacej przez p0, p1
           B, //  Ax + By + C = 0
           C, //  
           // ------------------------------------------------------------------
           D, //  Odleglosc punktu _bend od prostej p0,p1
           // ------------------------------------------------------------------
           a, //  Dane paraboli
           b, //  y = ax^2 + bx + c
           c, //
           // ------------------------------------------------------------------
           dx,
           rotate;
           
    A = (p1.y - p0.y) / (p1.x - p0.x);
    B = -1;
    C = p0.y - p0.x * a;
    D = abs(A * bend.x + B * bend.y + C) / sqrt(A * A + B * B);
    
    a = 2;//-4.0 * D / (d * d);
    b = 0;
    c = 0;
    
    dx = d / (double)_N;
    
    rotate = atan(a);
    
    _points.clear();
    
    for(int i = 0; i < _N; ++i) {
        wxRealPoint tmp;
        double x = -d / 2.f + i * dx;
        double y = a * x * x + b * x + c;
        
        tmp.x = x;//x * cos(rotate) + y * sin(rotate);
        tmp.y = y;//-x * sin(rotate) + y * cos(rotate);
        
        _points.push_back(tmp);
    }
}
