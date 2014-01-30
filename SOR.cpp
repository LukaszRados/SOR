#include "SOR.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// SOR
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(SOR,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(SOR::OnClose)
	EVT_MENU(ID_MNU_NOWY_1040, SOR::createNewGraph)
	EVT_MENU(ID_MNU_WCZYTAJ_1042, SOR::loadFileClick)
	EVT_MENU(ID_MNU_ZAPISZFIGUR__1043, SOR::saveFileClick)
	EVT_MENU(ID_MNU_WYEKSPORTUJDOPNG_1044, SOR::exportToBMP)
	EVT_MENU(ID_MNU_WYJ_CIE_1046, SOR::closeApp)
	EVT_MENU(ID_MNU_POKAZUJPUNKTY_1037, SOR::togglePoints)
	EVT_MENU(ID_MNU_ZAMYKAJKRZYWE_1038, SOR::toggleClosing)
	EVT_MENU(ID_MNU_PRZYCI_GAJDOPUNKTU_1039, SOR::toggleStitch)
	EVT_MENU(ID_WXTOOLBUTTON5,SOR::changeCurrentColor)
	EVT_MENU(ID_WXTOOLBUTTON3,SOR::changeModeToCurve)
	EVT_MENU(ID_WXTOOLBUTTON2,SOR::changeModeToChain)
	EVT_MENU(ID_WXTOOLBUTTON1,SOR::changeModeToLine)
	EVT_MENU(ID_WXTOOLBUTTON7,SOR::changeModeToNone)
	
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR3,SOR::changeRotateZ)
	
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR2,SOR::changeRotateY)
	
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR1,SOR::changeRotateX)
	EVT_BUTTON(ID_WXBUTTON1,SOR::repaint3d)
END_EVENT_TABLE()
////Event Table End

SOR::SOR(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

SOR::~SOR()
{
}

void SOR::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Figura 2D"));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxVERTICAL);
	WxBoxSizer1->Add(WxStaticBoxSizer1, 0, wxALIGN_RIGHT | wxALIGN_TOP | wxALL, 5);

	Graph2d = new wxPanel(this, ID_GRAPH2D, wxPoint(10, 20), wxSize(400, 400));
	Graph2d->SetBackgroundColour(wxColour(_("WHITE")));
	WxStaticBoxSizer1->Add(Graph2d, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Rysuj"), wxPoint(172, 430), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxStaticBoxSizer1->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("WxStaticText1"), wxPoint(171, 465), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticBoxSizer1->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer2_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Bry�a obrotowa"));
	WxStaticBoxSizer2 = new wxStaticBoxSizer(WxStaticBoxSizer2_StaticBoxObj, wxVERTICAL);
	WxBoxSizer1->Add(WxStaticBoxSizer2, 0, wxALIGN_TOP | wxALL, 5);

	Graph3d = new wxPanel(this, ID_GRAPH3D, wxPoint(10, 20), wxSize(400, 400));
	Graph3d->SetBackgroundColour(wxColour(_("WHITE")));
	WxStaticBoxSizer2->Add(Graph3d, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer2->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(5, 5), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer2->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(136, 5), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer2->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(267, 5), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer2->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStatusBar1 = new wxStatusBar(this, ID_WXSTATUSBAR1);

	WxToolBar1 = new wxToolBar(this, ID_WXTOOLBAR1, wxPoint(0, 0), wxSize(863, 40), wxTB_TEXT | wxTB_NOICONS);

	wxBitmap WxToolButton7_BITMAP (wxNullBitmap);
	wxBitmap WxToolButton7_DISABLE_BITMAP (wxNullBitmap);
	WxToolBar1->AddTool(ID_WXTOOLBUTTON7, _("Gumka"), WxToolButton7_BITMAP, WxToolButton7_DISABLE_BITMAP, wxITEM_NORMAL, _("Kasuj figury"), _(""));

	wxBitmap WxToolButton1_BITMAP (wxNullBitmap);
	wxBitmap WxToolButton1_DISABLE_BITMAP (wxNullBitmap);
	WxToolBar1->AddTool(ID_WXTOOLBUTTON1, _("Linia"), WxToolButton1_BITMAP, WxToolButton1_DISABLE_BITMAP, wxITEM_NORMAL, _("Narysuj odcinek"), _(""));

	wxBitmap WxToolButton2_BITMAP (wxNullBitmap);
	wxBitmap WxToolButton2_DISABLE_BITMAP (wxNullBitmap);
	WxToolBar1->AddTool(ID_WXTOOLBUTTON2, _("Krzywa �amana"), WxToolButton2_BITMAP, WxToolButton2_DISABLE_BITMAP, wxITEM_NORMAL, _("Narysuj krzyw� �aman�"), _(""));

	wxBitmap WxToolButton3_BITMAP (wxNullBitmap);
	wxBitmap WxToolButton3_DISABLE_BITMAP (wxNullBitmap);
	WxToolBar1->AddTool(ID_WXTOOLBUTTON3, _("�uk"), WxToolButton3_BITMAP, WxToolButton3_DISABLE_BITMAP, wxITEM_NORMAL, _("Narysuj �uk"), _(""));

	wxBitmap WxToolButton5_BITMAP (wxNullBitmap);
	wxBitmap WxToolButton5_DISABLE_BITMAP (wxNullBitmap);
	WxToolBar1->AddTool(ID_WXTOOLBUTTON5, _("Kolor"), WxToolButton5_BITMAP, WxToolButton5_DISABLE_BITMAP, wxITEM_NORMAL, _("Zmie� kolor"), _(""));

	WxColourDialog1 =  new wxColourDialog(this);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_PLIK_1027_Mnu_Obj = new wxMenu();
	ID_MNU_PLIK_1027_Mnu_Obj->Append(ID_MNU_NOWY_1040, _("Nowy"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1027_Mnu_Obj->AppendSeparator();
	ID_MNU_PLIK_1027_Mnu_Obj->Append(ID_MNU_WCZYTAJ_1042, _("Wczytaj"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1027_Mnu_Obj->Append(ID_MNU_ZAPISZFIGUR__1043, _("Zapisz figur�"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1027_Mnu_Obj->Append(ID_MNU_WYEKSPORTUJDOPNG_1044, _("Wyeksportuj do BMP"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1027_Mnu_Obj->AppendSeparator();
	ID_MNU_PLIK_1027_Mnu_Obj->Append(ID_MNU_WYJ_CIE_1046, _("Zamknij"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_PLIK_1027_Mnu_Obj, _("Plik"));
	
	wxMenu *ID_MNU_EDYCJA_1034_Mnu_Obj = new wxMenu();
	ID_MNU_EDYCJA_1034_Mnu_Obj->Append(ID_MNU_POKAZUJPUNKTY_1037, _("Pokazuj punkty"), _(""), wxITEM_CHECK);
	ID_MNU_EDYCJA_1034_Mnu_Obj->Check(ID_MNU_POKAZUJPUNKTY_1037,true);
	ID_MNU_EDYCJA_1034_Mnu_Obj->Append(ID_MNU_ZAMYKAJKRZYWE_1038, _("Zamykaj krzywe"), _(""), wxITEM_CHECK);
	ID_MNU_EDYCJA_1034_Mnu_Obj->Check(ID_MNU_ZAMYKAJKRZYWE_1038,false);
	ID_MNU_EDYCJA_1034_Mnu_Obj->Append(ID_MNU_PRZYCI_GAJDOPUNKTU_1039, _("Przyci�gaj do punktu"), _(""), wxITEM_CHECK);
	ID_MNU_EDYCJA_1034_Mnu_Obj->Check(ID_MNU_PRZYCI_GAJDOPUNKTU_1039,true);
	ID_MNU_EDYCJA_1034_Mnu_Obj->AppendSeparator();
	ID_MNU_EDYCJA_1034_Mnu_Obj->Append(ID_MNU_PERSPEKTYWA_1053, _("Perspektywa"), _(""), wxITEM_CHECK);
	ID_MNU_EDYCJA_1034_Mnu_Obj->Check(ID_MNU_PERSPEKTYWA_1053,false);
	WxMenuBar1->Append(ID_MNU_EDYCJA_1034_Mnu_Obj, _("Edycja"));
	
	wxMenu *ID_MNU_ANIMACJA_1035_Mnu_Obj = new wxMenu();
	WxMenuBar1->Append(ID_MNU_ANIMACJA_1035_Mnu_Obj, _("Animacja"));
	wxMenu *ID_MNU_POMOC_1036_Mnu_Obj = new wxMenu();
	WxMenuBar1->Append(ID_MNU_POMOC_1036_Mnu_Obj, _("Pomoc"));
	SetMenuBar(WxMenuBar1);

	ExportToBMPDialog =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.bmp"), wxFD_SAVE);

	WxOpenFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.txt"), wxFD_OPEN);

	WxSaveFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.txt"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	SetStatusBar(WxStatusBar1);
	WxToolBar1->Realize();
	SetToolBar(WxToolBar1);
	SetTitle(_("Solid of Revolution"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	
	WxScrollBar1->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar1->Enable(true);
	WxScrollBar2->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar2->Enable(true);
	WxScrollBar3->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar3->Enable(true);
	
	_lastAddedPoint = wxRealPoint(-2, -2);
	_currentColor = RGB(0, 0, 0);
	_mode = NONE;
	
	Graph2d->Connect(wxID_ANY,
                     wxEVT_LEFT_DOWN,
                     wxMouseEventHandler(SOR::MouseLeftDown),
                     NULL, 
                     this);
                     
    Graph2d->Connect(wxID_ANY,
                     wxEVT_MOTION,
                     wxMouseEventHandler(SOR::MouseMove),
                     NULL, 
                     this);
                     
    Graph2d->Connect(wxID_ANY,
                     wxEVT_LEFT_DCLICK,
                     wxMouseEventHandler(SOR::MouseDoubleClick),
                     NULL, 
                     this);
    
    _config = {
        true,               ///\ Czy pokazywac punkty  
        false,              ///\ Czy dorysowywac linie miedzy ostatnim a pierwszym punktem
        true                ///\ Czy przyciagac kursor w poblizu punktu
    };
    
    draw2dGraph();
}

void SOR::OnClose(wxCloseEvent& event) {
    resetShapes();
	Destroy();
}

/******************************************************************************/

wxRealPoint SOR::pointToReal(wxPoint point) {
    wxSize size = Graph2d->GetSize();
    return wxRealPoint(point.x / (double)(2 * size.GetWidth()), point.y / (double)(2 * size.GetHeight()));
}

/******************************************************************************/

wxPoint SOR::pointToInt(wxRealPoint point) {
    wxSize size = Graph2d->GetSize();
    return wxPoint(point.x * size.GetWidth() / 2, point.y * size.GetHeight() / 2);
}

/******************************************************************************/

void SOR::draw2dGraph() {
    wxSize size = Graph2d->GetSize();
    
    wxClientDC one(Graph2d);
    wxBufferedDC *dc = new wxBufferedDC(&one);

    dc->SetBackground(wxBrush(RGB(255, 255, 255)));
    dc->Clear();

    dc->SetDeviceOrigin(size.x / 2, size.y / 2);
    
    dc->SetPen(*wxBLACK_PEN);
    dc->DrawLine(0, -size.GetHeight() / 2, 0, size.GetHeight() / 2);
    dc->DrawLine(-size.GetWidth() / 2, 0, size.GetWidth() / 2, 0); 
    
    int shapes = _shapes.size();
    for(int i = 0; i < shapes; ++i) {
        std::vector<wxRealPoint> points = _shapes[i]->getPoints();
        dc->SetPen(_shapes[i]->getColor());
        
        for(int j = 0; j < points.size() - 1; ++j) {
            wxPoint tmp = pointToInt(points[j]),
                    tmp2 = pointToInt(points[j + 1]);
            
            if(_config.showPoints) {
                dc->DrawCircle(tmp.x, tmp.y, 3);
            }
            
            dc->DrawLine(tmp, tmp2);
        }
        
        if(_config.showPoints) {
            wxPoint tmp = pointToInt(points[points.size() - 1]);
            dc->DrawCircle(tmp.x, tmp.y, 3);
        }
    }
    
    if(_lastAddedPoint.x >= -1 && _config.showPoints) {
        wxPoint tmp = pointToInt(_lastAddedPoint);
        dc->SetPen(_currentColor);
        dc->DrawCircle(tmp.x, tmp.y, 3);
    }

    delete dc; 
}

/******************************************************************************/

void SOR::prepare3dGraph() {
    Matrix M;
    Vector v1, v2, v3, v4;
    
    _lines3d.clear();
    
    for(int i = 0; i < _shapes.size(); ++i) {
        std::vector<wxRealPoint> points = _shapes[i]->getPoints();
        for(int j = 0; j < points.size() - 1; ++j) {
            v1.set(points[j].x, points[j].y, 0);
            v2.set(points[j + 1].x, points[j + 1].y, 0);
            
            M = rotateY(5);
            
            for(int k = 0; k < 72; ++k) {
                v3 = M * v1;
                v4 = M * v2;
                
                Line3d line1 = {
                    v1.getX(),
                    v1.getY(),
                    v1.getZ(),
                    v3.getX(),
                    v3.getY(),
                    v3.getZ(),
                    _shapes[i]->getColor()    
                };
                
                _lines3d.push_back(line1);
                
                Line3d line2 = {
                    v4.getX(),
                    v4.getY(),
                    v4.getZ(),
                    v2.getX(),
                    v2.getY(),
                    v2.getZ(),
                    _shapes[i]->getColor()    
                };
                
                _lines3d.push_back(line2);
                
                Line3d line3 = {
                    v3.getX(),
                    v3.getY(),
                    v3.getZ(),
                    v4.getX(),
                    v4.getY(),
                    v4.getZ(),
                    _shapes[i]->getColor()    
                };
                
                _lines3d.push_back(line3);
                
                v1 = v3;
                v2 = v4;
            }    
        }
    }
}

/******************************************************************************/

void SOR::draw3dGraph() {
    wxClientDC dc1(Graph3d);
    wxBufferedDC dc(&dc1); 

    int w, h;
    Vector v1, v2;
    
    Graph3d->GetSize(&w, &h);
    dc.Clear();
    dc.SetDeviceOrigin(w / 2, h / 2);

    double rX = WxScrollBar1->GetThumbPosition();
    double rY = WxScrollBar2->GetThumbPosition();
    double rZ = WxScrollBar3->GetThumbPosition(); 
    
    prepare3dGraph();
    
    Matrix M = translation(0, 0, 0) * rotateX(rX) * rotateY(rY) * rotateZ(rZ);
    for(int i = 0; i < _lines3d.size(); ++i) {
        v1.set(_lines3d[i].x0, _lines3d[i].y0, _lines3d[i].z0);    
        v2.set(_lines3d[i].x1, _lines3d[i].y1, _lines3d[i].z1);
        
        v1 = M * v1;
        v2 = M * v2;
        
        dc.SetPen(_lines3d[i].color);
        dc.DrawLine(v1.getX() * w/2, -v1.getY() * h/2, v2.getX() * w/2, -v2.getY() * h/2);
    }   
}

/******************************************************************************/

void SOR::resetShapes() {
    _currentShape = 0;
    
    int size = _shapes.size();
	for(int i = 0; i < size; ++i) {
        delete _shapes[i];    
    }
    
    _shapes.clear();
    _lines3d.clear();
}

/******************************************************************************/

void SOR::MouseLeftDown(wxMouseEvent& event) {
    wxClientDC one(Graph2d);
    wxPoint point = event.GetLogicalPosition(one);
    
    point.x = (point.x * 2 - Graph2d->GetSize().x) * 2;
    point.y = (point.y * 2 - Graph2d->GetSize().y) * 2;
    
    wxRealPoint p = pointToReal(point);
    
    if(p.x < -1 || p.x > 1 || p.y < -1 || p.y > 1) return;
 
	if((_lastAddedPoint.x < -1 || _lastAddedPoint == p) && _mode != NONE) {
        _lastAddedPoint = p;
    }
    else {
        switch(_mode) {
        case NONE:
        {
            int index = isPartOfAnyShape(p);
            if(index == -1) {
                WxStaticText1->SetLabel("Nie jest");    
            }
            else {
                WxStaticText1->SetLabel("Jest");
                delete _shapes[index];
                _shapes.erase(_shapes.begin() + index);
                draw2dGraph();
            }
        }
            break;
        
        case LINE:
            _shapes.push_back(new Line(_lastAddedPoint, p, _currentColor));
            _lastAddedPoint.x = -2;
            break;
            
        case CURVE:
            if(_currentShape == 0) {
                _currentShape = new Curve(_lastAddedPoint, p, _currentColor);
                _shapes.push_back(_currentShape);
            }
            else {
                Curve* currentCurve = dynamic_cast<Curve*>(_currentShape);

                if(currentCurve != 0) {
                    currentCurve->changeBend(p);
                }
                
                _currentShape = 0;
                _lastAddedPoint.x = -2;
            }
            break;
            
        case CHAIN:
            if(_currentShape == 0) {
                _currentShape = new Chain(_lastAddedPoint, p, _currentColor);
                _shapes.push_back(_currentShape);
                _lastAddedPoint = p;
            }
            else {
                wxRealPoint a = isPartOfCurrentShape(p);
                
                if(a.x > -1.5 && a.y > -1.5 && _config.stitchPoint) {
                    _currentShape->addPoint(a);
                    _currentShape = 0;
                    _lastAddedPoint.x = -2;
                }
                else {
                    _currentShape->addPoint(p);
                    _lastAddedPoint = p;
                }
            }
            
            break;
        }

        if(_currentShape != 0 && _mode != CHAIN && _mode != CURVE) {
            _currentShape = 0;    
        }
    }
    
    draw2dGraph();
}

/******************************************************************************/

int SOR::isPartOfAnyShape(wxRealPoint p) {
    int shapes = _shapes.size();
    
    for(int i = 0; i < shapes; ++i) {
        std::vector<wxRealPoint> points = _shapes[i]->getPoints();
        int pi = points.size();
        
        for(int j = 0; j < pi; ++j) {
            if(Shape::distance(p, points[j]) < 0.05) {
                return i; 
            }
        }    
    }
    
    return -1;
}

/******************************************************************************/

wxRealPoint SOR::isPartOfCurrentShape(wxRealPoint p) {
    if(_currentShape == 0) {
        return wxRealPoint(-2, -2);
    }

    wxRealPoint first = _currentShape->getPoints()[0];
    
    if(Shape::distance(p, first) <= 0.05) {
        return first;
    }

    return wxRealPoint(-2, -2);
}

/******************************************************************************/

void SOR::MouseMove(wxMouseEvent& event) {
    wxSize size = Graph2d->GetSize();
    
    draw2dGraph();
    
	wxClientDC one(Graph2d);
    wxPoint point = event.GetLogicalPosition(one);
    wxBufferedDC *dc = new wxBufferedDC(&one);
    dc->SetPen(_currentColor);
      
    point.x = (point.x * 2 - size.x) * 2;
    point.y = (point.y * 2 - size.y) * 2;
    wxRealPoint p = pointToReal(point);
    
    if((p.x < -.999 || p.x > 1 || p.y < -1 || p.y > 1 || _lastAddedPoint.x < -.999) && _mode != NONE) {}
    else {
        dc->SetDeviceOrigin(size.x / 2, size.y / 2);
        
        wxRealPoint tmp = isPartOfCurrentShape(p);
        wxPoint a = pointToInt(tmp);
        wxPoint last = pointToInt(_lastAddedPoint);
        int shape = isPartOfAnyShape(p);
        
        switch(_mode) {
        case CURVE:
            if(_currentShape == 0) {
                dc->DrawLine(last, pointToInt(p));
            }
            else {
                Curve* curve = dynamic_cast<Curve*>(_currentShape);
                curve->changeBend(p);
            }
            break;
            
        case NONE:
            if(shape > -1) {
                std::vector<wxRealPoint> points = _shapes[shape]->getPoints();
                dc->SetPen(*wxRED_PEN);
                
                for(int i = 0; i < points.size() - 1; ++i) {
                    wxPoint point = pointToInt(points[i]),
                            point2 = pointToInt(points[i + 1]);
                       
                    dc->DrawLine(point, point2);     
                    dc->DrawCircle(point.x, point.y, 6);
                }
                
                wxPoint point = pointToInt(points[points.size() - 1]);
                dc->DrawCircle(point.x, point.y, 6);
            }
            break;

        default:
            if(tmp.x > -1.5 && tmp.y > -1.5 && _config.stitchPoint) {
                dc->DrawLine(last, a);
                dc->DrawCircle(a.x, a.y, 6);
            }
            else {
                dc->DrawLine(last, pointToInt(p));
            }
            break;    
        }
    }

    delete dc;
    
    event.StopPropagation();
}

/******************************************************************************/

void SOR::MouseDoubleClick(wxMouseEvent& event) {
	MouseLeftDown(event);
	
	if(_config.closeChain && _mode == CHAIN && _currentShape->getPoints().size() > 2) {
        _currentShape->addPoint(_currentShape->getPoints()[0]);    
    }
	
	_currentShape = 0;
	_lastAddedPoint.x = -2;
	
	draw2dGraph();
}

/******************************************************************************/

void SOR::changeModeToNone(wxCommandEvent& event) {
    _mode = NONE;
}

/******************************************************************************/

void SOR::changeModeToLine(wxCommandEvent& event) {
	_mode = LINE;
}

/******************************************************************************/

void SOR::changeModeToChain(wxCommandEvent& event) {
	_mode = CHAIN;
}

/******************************************************************************/

void SOR::changeModeToCurve(wxCommandEvent& event) {
	_mode = CURVE;
}

/******************************************************************************/

void SOR::changeCurrentColor(wxCommandEvent& event) {
    if(WxColourDialog1->ShowModal() == wxID_OK) {
	   _currentColor = WxColourDialog1->GetColourData().GetColour();
	   
	   if(_currentShape != 0) {
          _currentShape->setColor(_currentColor);    
       }
    }
    
    draw2dGraph();
}

/******************************************************************************/

void SOR::toggleStitch(wxCommandEvent& event) {
    _config.stitchPoint = event.IsChecked();
    draw2dGraph();
}

/******************************************************************************/

void SOR::togglePoints(wxCommandEvent& event) {
    _config.showPoints = event.IsChecked();
    draw2dGraph();
}

/******************************************************************************/

void SOR::toggleClosing(wxCommandEvent& event) {
    _config.closeChain = event.IsChecked();
    draw2dGraph();
}

/******************************************************************************/

void SOR::repaint3d(wxCommandEvent& event){
	draw3dGraph();
}

/******************************************************************************/

void SOR::changeRotateX(wxScrollEvent& event) {
    draw3dGraph();
}

/******************************************************************************/

void SOR::changeRotateY(wxScrollEvent& event) {
    draw3dGraph();
}

/******************************************************************************/

void SOR::changeRotateZ(wxScrollEvent& event) {
    draw3dGraph();
}

/******************************************************************************/

void SOR::createNewGraph(wxCommandEvent& event) {
    resetShapes();
    
    draw2dGraph();
    draw3dGraph();
}

/******************************************************************************/

void SOR::closeApp(wxCommandEvent& event) {
	resetShapes();
	Destroy();
}

/******************************************************************************/

void SOR::exportToBMP(wxCommandEvent& event) {
    if(ExportToBMPDialog->ShowModal() == wxID_OK) {
        wxClientDC dc(Graph3d);
        wxBitmap image = dc.GetAsBitmap();
        wxString filename = ExportToBMPDialog->GetPath();
        
        image.SaveFile(filename, wxBITMAP_TYPE_BMP);
    }
    else {
        WxStatusBar1->SetStatusText("Nie uda�o sie zapisa� pliku.");
    }
}

/******************************************************************************/

void SOR::saveFileClick(wxCommandEvent& event) {
	if(WxSaveFileDialog1->ShowModal() == wxID_OK) {
        std::ofstream file(WxSaveFileDialog1->GetPath().ToAscii());
        if(file.is_open()) {
            file << _shapes.size() << std::endl;
            for(int i = 0; i < _shapes.size(); ++i) {
                std::vector<wxRealPoint> points = _shapes[i]->getPoints();
                wxColour color = _shapes[i]->getColor();
                
                file << 999999 << std::endl;
                file << _shapes[i]->getPoints().size() << std::endl;
                file << _shapes[i]->getClassId() << std::endl;
                file << _shapes[i]->getColor().GetRGB() << "\n";

                for(int j = 0; j < points.size(); ++j) {
                    file << points[j].x * 10000 << " ";
                    file << points[j].y * 10000 << "\n"; 
                }    
                
                file << 999999 << "\n";
            }
            WxStatusBar1->SetStatusText("Plik zosta� zapisany.");
            file.close();
        }
        else {
            WxStatusBar1->SetStatusText("Nie uda�o sie zapisa� pliku.");
        }
    }
}

/******************************************************************************/

void SOR::loadFileClick(wxCommandEvent& event) {
    if(WxOpenFileDialog1->ShowModal() == wxID_OK) {
        std::ifstream file(WxOpenFileDialog1->GetPath().ToAscii());
        if(file.is_open()) {
            
            int shapesSize,
                tmp;
            file >> shapesSize;
            for(int i = 0; i < shapesSize; ++i) {
                file >> tmp;
                int pointsSize,
                    figureType,
                    color;
                Shape* current;
                    
                file >> pointsSize;
                file >> figureType;
                file >> color;
                
                switch(figureType) {
                case 1:
                    current = new Line();
                    break;
                    
                case 2:
                    current = new Curve();
                    break;
                    
                case 3:
                    current = new Chain();
                    break;
                    
                default:
                    // Obsluga bledow
                    break;    
                }
                
                wxColour c;
                c.SetRGB(color);
                current->setColor(c);
                
                for(int j = 0; j < pointsSize; ++j) {
                    int x, y;
                    file >> x >> y;
                    current->addPoint(wxRealPoint((double)x / 10000.f, (double)y / 10000.f)); 
                }
                
                _shapes.push_back(current);
                current = 0;
                
                file >> tmp;    
            }
        }
        else {
            WxStatusBar1->SetStatusText("Nie uda�o sie wczyta� pliku.");
        }   
    }    
}