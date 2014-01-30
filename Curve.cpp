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

/******************************************************************************/

void Curve::changeBend(wxRealPoint bend) {
    try {
        _bend = bend;
        
        wxRealPoint p0 = _initStart,
                    p1 = _initEnd,
                    os,
                    middle;
                    
        if(abs(_bend.x - p0.x) < 0.0001) _bend.x += 0.0002;
        if(abs(_bend.y - p0.y) < 0.0001) _bend.y -= 0.0002;
        
        os = circleCenter(p0, p1, _bend);           
        
        double R = distance(p0, os),
               D = distance(p0, p1),
               d;
        
        // Ograniczamy promien okregu do 1/2 odleglosci miedzy puntami poczatkowymi
        middle.x = (p1.x + p0.x) / 2.f;
        middle.y = (p1.y + p0.y) / 2.f;
        d = distance(middle, bend);
        if(d > D / 2.f) return;
        if(os.x < -900) return;
        
        // Wyznaczamy prosta przechodzaca przez dwa punkty. 
        // Nalezy uwzglednic sytuacje, w ktorej wybrane punkty tworza prosta pionowa
        double a, b;
        
        if(abs(p1.x - p0.x) < 0.0001) p1.x += 0.001;
        if(abs(p1.y - p0.y) < 0.0001) p0.y += 0.001;
        a = (p1.y - p0.y) / (p1.x - p0.x);
        b = p0.y - p0.x * a;    
    
        _points.clear();
        
        int N = (int)(R / 0.01);
        if(N < 10) N = 10;
        
        for(int i = 0; i < N; ++i) {
            double x, y, fi;
            
            if(_bend.y < a * _bend.x + b) {
                
                wxRealPoint c = (p1.x > p0.x ? p0 : p1);
                double fi0 = abs(c.x - os.x) < 0.001 ? M_PI / 2.f : atan((c.y - os.y) / (c.x - os.x));
                
                fi = i * M_PI / ((double)N / 2.f) + fi0;
                x = R * cos(fi) + os.x;
                y = R * sin(fi) + os.y;
                
                // Interesuja nas tylko punkty POD prosta y = ax + b
                if(y <= a * x + b) {
                    _points.push_back(wxRealPoint(x, y));
                }    
            }
            else {
                
                wxRealPoint c = (p1.x > p0.x ? p1 : p0);
                double fi0 = abs(c.x - os.x) < 0.001 ? M_PI / 2.f : atan((c.y - os.y) / (c.x - os.x));
                
                fi = i * M_PI / ((double)N / 2.f) + fi0 + M_PI;
                x = R * cos(fi) + os.x;
                y = R * sin(fi) + os.y;
                
                // Interesuja nas punkty NAD prosta y = ax + b  
                if(y >= a * x + b) {
                    _points.push_back(wxRealPoint(x, y));    
                }  
            } 
        }
    }
    catch(...) {
    }
}

/******************************************************************************/

wxRealPoint Curve::circleCenter(wxRealPoint p1, wxRealPoint p2, wxRealPoint p3) {
    wxRealPoint os;
    double m = (p1.y * p3.x - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x + p3.y * p2.x + p2.y * p1.x);
    os.x = 0.5 * ((p2.x * p2.x * p3.y + p2.y * p2.y * p3.y - p1.x * p1.x * p3.y + p1.x * p1.x * p2.y - p1.y * p1.y * p3.y + p1.y * p1.y * p2.y + p1.y * p3.x * p3.x + p1.y * p3.y * p3.y - p1.y * p2.x * p2.x - p1.y * p2.y * p2.y - p2.y * p3.x * p3.x - p2.y * p3.y * p3.y) / m);
    os.y = 0.5 * ((-p1.x * p3.x * p3.x - p1.x * p3.y * p3.y + p1.x * p2.x * p2.x + p1.x * p2.y * p2.y + p2.x * p3.x * p3.x + p2.x * p3.y * p3.y - p2.x * p2.x * p3.x - p2.y * p2.y * p3.x + p1.x * p1.x * p3.x - p1.x * p1.x * p2.x + p1.y * p1.y * p3.x - p1.y * p1.y * p2.x) / m);
    return os;
}
