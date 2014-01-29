#ifndef _CURVE_HPP_
#define _CURVE_HPP_

#include "Shape.hpp"

class Curve : public Shape {
public:
    Curve():Shape(),_N(50) {}
    Curve(wxRealPoint a, wxRealPoint b, wxColour color);
    virtual ~Curve() {}
    
    /**
     *  Metoda zmienia wygiecie paraboli, poprzez zmiane polozenia wierzcholka.
     *  
     *  @todo Funkcja rysuje poki co parabole o wierzcholku w (0,0) i a = 2 - wymaga poprawy
     *  @param wxRealPoint Punkt, ktorego odleglosc od prostej determinuje wygiecie.
     */
    void changeBend(wxRealPoint);
    
    virtual int getClassId() const { return 2; }
        
private:
    wxRealPoint _bend;   
    const int _N; 
};

#endif
