#include "Shape.hpp"

bool Shape::contains(wxRealPoint p) const {
    int parts = _points.size();
    double e = 0.001;
    
    for(int i = 0; i < parts - 1; ++i) {
        wxRealPoint p1 = _points[i], 
                    p2 = _points[i + 1];
                    
        if(abs(p1.x - p.x) < e && abs(p1.y - p.y) < e) return true;
        if(abs(p2.x - p.x) < e && abs(p2.y - p.y) < e) return true;
                    
        if(abs(p2.x - p1.x) < e) {
            if(abs(p2.x - p.x) < e && (( p2.y > p1.y && p2.y > p.y && p.y > p1.y ) || (p2.y < p1.y && p2.y < p.y && p.y < p1.y))) {
                return true;    
            }
        }
        else {  
            if(abs(p.y - p1.y - (p.x - p1.x) * (p2.y - p1.y) / (p2.x - p1.x)) < e) {
                return true;    
            }
        }    
    }
    
    return false;
}

/******************************************************************************/

void Shape::addPoint(wxRealPoint p) {
    _points.push_back(p);   
}

/******************************************************************************/

double Shape::distance(wxRealPoint a, wxRealPoint b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));    
}
