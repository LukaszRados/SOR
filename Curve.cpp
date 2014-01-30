#include "Curve.hpp"

Curve::Curve(wxRealPoint a, wxRealPoint b, wxColour color):Shape() {
    _points.push_back(a);
    _points.push_back(b);
    _color = color;
    
    _initStart = a;
    _initEnd = b;
     
    double x, y;
    x = (a.x + b.x) / 2.f;
    y = (a.y + b.y) / 2.f;
    _bend = wxRealPoint(x, y);
}

void Curve::changeBend(wxRealPoint bend) {
    _bend = bend;
    
    wxRealPoint p0 = _initStart,
                p1 = _initEnd,
                os = circleCenter(p0, p1, _bend),
                middle;
                
    double R = sqrt(pow(p0.x - os.x, 2) + pow(p0.y - os.y, 2)),
           D = sqrt(pow(p0.x - p1.x, 2) + pow(p0.y - p1.y, 2)),
           d;
    
    // Ograniczamy promien okregu do 1/2 odleglosci miedzy puntami poczatkowymi
    middle.x = (p1.x + p0.x) / 2.f;
    middle.y = (p1.y + p0.y) / 2.f;
    d = sqrt(pow(middle.x - bend.x, 2) + pow(middle.y - bend.y, 2));
    if(d > D / 2.f) return;
    
    // Wyznaczamy prosta przechodzaca przez dwa punkty. 
    // Nalezy uwzglednic sytuacje, w ktorej wybrane punkty tworza prosta pionowa
    double a, b;
    
    //if(abs(p1.x - p0.x) < 0.001) a = 999999;
    a = (p1.y - p0.y) / (p1.x - p0.x);
    b = p0.y - p0.x * a;    

    _points.clear();
    
    int N = (int)(R / 0.01);
    
    for(int i = 0; i < N + 1; ++i) {
        double x, y, fi;
        fi = i * M_PI / ((double)N / 2.f);
        x = R * cos(fi) + os.x;
        y = R * sin(fi) + os.y;
        
        if(_bend.y < a * _bend.x + b) {
            // Interesuja nas tylko punkty POD prosta y = ax + b
            if(y < a * x + b) {
                _points.push_back(wxRealPoint(x, y));
            }    
        }
        else {
            // Interesuja nas punkty NAD prosta y = ax + b  
            if(y > a * x + b) {
                _points.push_back(wxRealPoint(x, y));    
            }  
        } 
    }
}

wxRealPoint Curve::circleCenter(wxRealPoint p1, wxRealPoint p2, wxRealPoint p3) {
    wxRealPoint os;
    os.x = 0.5 * ((p2.x * p2.x * p3.y + p2.y * p2.y * p3.y - p1.x * p1.x * p3.y + p1.x * p1.x * p2.y - p1.y * p1.y * p3.y + p1.y * p1.y * p2.y + p1.y * p3.x * p3.x + p1.y * p3.y * p3.y - p1.y * p2.x * p2.x - p1.y * p2.y * p2.y - p2.y * p3.x * p3.x - p2.y * p3.y * p3.y) / (p1.y * p3.x - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x + p3.y * p2.x + p2.y * p1.x));
    os.y = 0.5 * ((-p1.x * p3.x * p3.x - p1.x * p3.y * p3.y + p1.x * p2.x * p2.x + p1.x * p2.y * p2.y + p2.x * p3.x * p3.x + p2.x * p3.y * p3.y - p2.x * p2.x * p3.x - p2.y * p2.y * p3.x + p1.x * p1.x * p3.x - p1.x * p1.x * p2.x + p1.y * p1.y * p3.x - p1.y * p1.y * p2.x) / (p1.y * p3.x - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x + p3.y * p2.x + p2.y * p1.x));
    return os;
}
