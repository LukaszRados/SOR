///-----------------------------------------------------------------
///
/// @file      SettingsFrm.h
/// @author    Lukasz
/// Created:   2014-01-31 14:14:59
/// @section   DESCRIPTION
///            SettingsFrame class declaration
///
///------------------------------------------------------------------

#ifndef __SETTINGSFRAME_H__
#define __SETTINGSFRAME_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/scrolbar.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
////Header Include End

#include "Line3d.hpp"

////Dialog Style Start
#undef SettingsFrame_STYLE
#define SettingsFrame_STYLE wxCAPTION | wxSYSTEM_MENU | wxSTAY_ON_TOP | wxCLOSE_BOX
////Dialog Style End

class SettingsFrame : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		SettingsFrame(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Ustawienia animacji"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = SettingsFrame_STYLE);
		virtual ~SettingsFrame();
		void WxButton1Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxScrollBar *WxScrollBar6;
		wxScrollBar *WxScrollBar5;
		wxScrollBar *WxScrollBar4;
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxScrollBar *WxScrollBar3;
		wxScrollBar *WxScrollBar2;
		wxScrollBar *WxScrollBar1;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxButton *WxButton1;
		wxBoxSizer *WxBoxSizer6;
		wxBoxSizer *WxBoxSizer5;
		wxBoxSizer *WxBoxSizer4;
		wxBoxSizer *WxBoxSizer3;
		wxBoxSizer *WxBoxSizer2;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSCROLLBAR6 = 1048,
			ID_WXSCROLLBAR5 = 1047,
			ID_WXSCROLLBAR4 = 1046,
			ID_WXSTATICTEXT9 = 1045,
			ID_WXSTATICTEXT8 = 1044,
			ID_WXSTATICTEXT7 = 1043,
			ID_WXSCROLLBAR3 = 1042,
			ID_WXSCROLLBAR2 = 1040,
			ID_WXSCROLLBAR1 = 1039,
			ID_WXSTATICTEXT6 = 1038,
			ID_WXSTATICTEXT5 = 1037,
			ID_WXSTATICTEXT4 = 1036,
			ID_WXSTATICTEXT3 = 1035,
			ID_WXSTATICTEXT2 = 1034,
			ID_WXSTATICTEXT1 = 1033,
			ID_WXBUTTON1 = 1031,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();

        Line3d *_org;
		Line3d _values;
		void updateValues(wxScrollEvent& event);
		
	public:
        void setValues(Line3d *org);
};

#endif
