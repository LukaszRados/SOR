#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

#include <vector>
#include <utility>
#include <cmath>

class Shape {
public:
    Shape():_color(wxColour(0, 0, 0)) { }
    virtual ~Shape() {}
    virtual void setColor(wxColour c) { _color = c; }
    virtual wxColour getColor() const { return _color; }
    virtual std::vector<wxRealPoint> getPoints() const { return _points; }
    virtual bool contains(wxRealPoint p) const;
    virtual void addPoint(wxRealPoint);
    virtual int getClassId() const = 0;
    static double distance(wxRealPoint a, wxRealPoint b);

protected:
    std::vector<wxRealPoint> _points;
    wxColour _color;

private:
    
};

#endif
