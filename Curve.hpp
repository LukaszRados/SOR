#ifndef _CURVE_HPP_
#define _CURVE_HPP_

#include "Shape.hpp"

class Curve : public Shape {
public:
    Curve():Shape() {}
    Curve(wxRealPoint a, wxRealPoint b, wxColour color);
    virtual ~Curve() {}
    virtual int getClassId() const { return 2; }
    
    /**
     *  Metoda zmienia wygiecie luku, poprzez zmiane trzeciegu punktu na okregu
     *  Ilosc punktow, na ktore dzielony jest luk zalezy od promienia
     *  Zaleznosc ta przedstawiona jest wzorem: 100 * R
     *  Dzieki temu, niezaleznie od wielkosci promienia, luk dzielony jest na tyle
     *  odcinkow, ze wciaz wyglada gladko.
     *
     *  @todo Powstaje dziwny artefakt (linia laczaca ostatni punkt z pierwszym). Do usuniecia.
     *  @param wxRealPoint Punkt, ktorego odleglosc od prostej determinuje wygiecie.
     */
    void changeBend(wxRealPoint);

private:
    /**
     *  Pierwszy z zaznaczonych punktow na okregu.
     */ 
    wxRealPoint _initStart;
    
    /**
     *  Drugi z zaznaczonych punktow na okregu.
     */
    wxRealPoint _initEnd;  
    
    /**
     *  Trzeci z punktow na okregu (ruchomy).
     */
    wxRealPoint _bend;
    
    /**
     *  Metoda obliczajaca srodek okregu przechodzacego przez 3 podane punkty.
     *  Kolejnosc podawanych punktow jest dowolna.
     *  Przeznaczona tylko do uzytku wewnetrznego.
     *
     *  @param Punkt #1
     *  @param Punkt #2
     *  @param Punkt #3
     *  @return Srodek okregu
     */
    wxRealPoint circleCenter(wxRealPoint p1, wxRealPoint p2, wxRealPoint p3);
};

#endif
