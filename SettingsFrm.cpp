///-----------------------------------------------------------------
///
/// @file      SettingsFrm.cpp
/// @section   DESCRIPTION
///            SettingsFrame class implementation
///
///------------------------------------------------------------------

#include "SettingsFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// SettingsFrame
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(SettingsFrame,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(SettingsFrame::OnClose)
	EVT_BUTTON(ID_WXBUTTON1,SettingsFrame::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

SettingsFrame::SettingsFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

SettingsFrame::~SettingsFrame()
{
}

void SettingsFrame::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Zapisz zmiany"), wxPoint(5, 5), wxSize(120, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxBoxSizer3->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Oœ X"), wxPoint(51, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false));
	WxBoxSizer4->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Oœ Y"), wxPoint(51, 5), wxDefaultSize, 0, _("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false));
	WxBoxSizer5->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Oœ Z"), wxPoint(51, 5), wxDefaultSize, 0, _("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false));
	WxBoxSizer6->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("K¹t pocz¹tkowy"), wxPoint(22, 34), wxDefaultSize, 0, _("WxStaticText4"));
	WxBoxSizer4->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("K¹t pocz¹tkowy"), wxPoint(22, 34), wxDefaultSize, 0, _("WxStaticText5"));
	WxBoxSizer5->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("K¹t pocz¹tkowy"), wxPoint(22, 34), wxDefaultSize, 0, _("WxStaticText6"));
	WxBoxSizer6->Add(WxStaticText6, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(5, 63), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer4->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(5, 63), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer5->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(5, 63), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer6->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, _("K¹t koñcowy"), wxPoint(29, 90), wxDefaultSize, 0, _("WxStaticText7"));
	WxBoxSizer4->Add(WxStaticText7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, _("K¹t koñcowy"), wxPoint(29, 90), wxDefaultSize, 0, _("WxStaticText8"));
	WxBoxSizer5->Add(WxStaticText8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, _("K¹t koñcowy"), wxPoint(29, 90), wxDefaultSize, 0, _("WxStaticText9"));
	WxBoxSizer6->Add(WxStaticText9, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar4 = new wxScrollBar(this, ID_WXSCROLLBAR4, wxPoint(3, 120), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar4"));
	WxScrollBar4->Enable(false);
	WxBoxSizer4->Add(WxScrollBar4, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar5 = new wxScrollBar(this, ID_WXSCROLLBAR5, wxPoint(5, 119), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar5"));
	WxScrollBar5->Enable(false);
	WxBoxSizer5->Add(WxScrollBar5, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar6 = new wxScrollBar(this, ID_WXSCROLLBAR6, wxPoint(5, 119), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar6"));
	WxScrollBar6->Enable(false);
	WxBoxSizer6->Add(WxScrollBar6, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Ustawienia animacji"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	Center();
	
	////GUI Items Creation End
	
	WxScrollBar1->Enable(true);
	WxScrollBar1->SetScrollbar(0, 1, 361, 1, true);
	WxScrollBar2->Enable(true);
	WxScrollBar2->SetScrollbar(0, 1, 361, 1, true);
	WxScrollBar3->Enable(true);
	WxScrollBar3->SetScrollbar(0, 1, 361, 1, true);
	WxScrollBar4->Enable(true);
	WxScrollBar4->SetScrollbar(0, 1, 361, 1, true);
	WxScrollBar5->Enable(true);
	WxScrollBar5->SetScrollbar(0, 1, 361, 1, true);
	WxScrollBar6->Enable(true);
	WxScrollBar6->SetScrollbar(0, 1, 361, 1, true);
	
	SetBackgroundColour(*wxWHITE);
}

/******************************************************************************/

void SettingsFrame::OnClose(wxCloseEvent& event) {
	Destroy();
}

/******************************************************************************/

void SettingsFrame::setValues(Line3d *org) {
    _org = org;
    if(_org != 0) {
        WxScrollBar1->SetThumbPosition((int)_org->x0); 
        WxScrollBar4->SetThumbPosition((int)_org->x1);
        WxScrollBar2->SetThumbPosition((int)_org->y0); 
        WxScrollBar5->SetThumbPosition((int)_org->y1);
        WxScrollBar3->SetThumbPosition((int)_org->z0); 
        WxScrollBar6->SetThumbPosition((int)_org->z1);
    }    
}

/******************************************************************************/

void SettingsFrame::WxButton1Click(wxCommandEvent& event) {
    if(_org != 0) {
        _org->x0 = WxScrollBar1->GetThumbPosition();
        _org->x1 = WxScrollBar4->GetThumbPosition();
        _org->y0 = WxScrollBar2->GetThumbPosition();    
        _org->y1 = WxScrollBar5->GetThumbPosition();
        _org->z0 = WxScrollBar3->GetThumbPosition();    
        _org->z1 = WxScrollBar6->GetThumbPosition();
    }
	Destroy();
}
