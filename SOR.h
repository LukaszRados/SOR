///-----------------------------------------------------------------
///
/// @file      SOR.h
/// @author    Lukasz
/// Created:   2014-01-28 22:23:42
/// @section   DESCRIPTION
///            SOR class declaration
///
///------------------------------------------------------------------

#ifndef __SOR_H__
#define __SOR_H__

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
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/scrolbar.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End

#include <vector>
#include <string>
#include <fstream>
#include <wx/dcbuffer.h>

#include "Shape.hpp"
#include "Line.hpp"
#include "Curve.hpp"
#include "Chain.hpp"
#include "Rectangle.hpp"
#include "Line3d.hpp"
#include "vecmat.h"

////Dialog Style Start
#undef SOR_STYLE
#define SOR_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class SOR : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		SOR(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("SOR"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = SOR_STYLE);
		virtual ~SOR();
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *WxOpenFileDialog1;
		wxColourDialog *WxColourDialog1;
		wxFileDialog *WxSaveFileDialog1;
		wxMenuBar *WxMenuBar1;
		wxToolBar *WxToolBar1;
		wxStatusBar *WxStatusBar1;
		wxScrollBar *WxScrollBar3;
		wxScrollBar *WxScrollBar2;
		wxScrollBar *WxScrollBar1;
		wxBoxSizer *WxBoxSizer2;
		wxPanel *Graph3d;
		wxStaticBoxSizer *WxStaticBoxSizer2;
		wxStaticText *WxStaticText1;
		wxButton *WxButton1;
		wxPanel *Graph2d;
		wxStaticBoxSizer *WxStaticBoxSizer1;
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
			ID_MNU_PLIK_1027 = 1027,
			ID_MNU_NOWY_1040 = 1040,
			ID_MNU_WCZYTAJ_1042 = 1042,
			ID_MNU_ZAPISZFIGUR__1043 = 1043,
			ID_MNU_WYEKSPORTUJDOPNG_1044 = 1044,
			ID_MNU_WYJ_CIE_1046 = 1046,
			ID_MNU_EDYCJA_1034 = 1034,
			ID_MNU_POKAZUJPUNKTY_1037 = 1037,
			ID_MNU_ZAMYKAJKRZYWE_1038 = 1038,
			ID_MNU_PRZYCI_GAJDOPUNKTU_1039 = 1039,
			ID_MNU_ANIMACJA_1035 = 1035,
			ID_MNU_POMOC_1036 = 1036,
			
			ID_WXTOOLBUTTON5 = 1033,
			ID_WXTOOLBUTTON4 = 1032,
			ID_WXTOOLBUTTON3 = 1031,
			ID_WXTOOLBUTTON2 = 1030,
			ID_WXTOOLBUTTON1 = 1029,
			ID_WXTOOLBAR1 = 1026,
			ID_WXSTATUSBAR1 = 1024,
			ID_WXSCROLLBAR3 = 1023,
			ID_WXSCROLLBAR2 = 1022,
			ID_WXSCROLLBAR1 = 1021,
			ID_GRAPH3D = 1018,
			ID_WXSTATICTEXT1 = 1048,
			ID_WXBUTTON1 = 1019,
			ID_GRAPH2D = 1017,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		
		/**
		 *  Typ wyliczeniowy, przechowujacy mozliwe stany rysowania.
		 */
		enum DrawingMode {
            NONE,               ///\ Nie rysujemy figury (np. zaznaczamy punkty)
            LINE,               ///\ Rysujemy pojedyncza linie
            CURVE,              ///\ Rysujemy krzywa (luk)
            CHAIN,              ///\ Rysujemy krzywa lamana
            RECTANGLE           ///\ Rysujemy prostokat
        };
        
        /**
         *  Struktura przechowujaca opcje wykresu.
         *  Zastosowana w celu unikniecia rozrzucenia zmiennych odpowiedzialnych
         *  za wyglad wykresu po calej klasie.
         */
        typedef struct Config {
            bool showPoints;    ///\ Czy punkty powinny byc widoczne na wykresie 2d
            bool closeChain;    ///\ Czy domykac krzywe lamane
            bool stitchPoint;   ///\ Czy dociagac aktualnie rysowana linie do punktu poczatkowego
        } Config;
		
		/**
		 *  Metoda odpowiedzialna za rysowanie wykresu 2d.
		 *  (czyli tej czesci wykresu, na ktora nanosimy figury).
		 */
		void draw2dGraph();
		
		/**
		 *  Metoda odpowiedzialna za narysowanie bryly obrotowej.
		 *  Metoda wywolywana jest tylko w momencie klikniecia 'Rysuj' 
		 *  lub po zmienieniu wartosci katow obrotu bryly.
		 */
		void draw3dGraph();
		
		/**
		 *  Metoda zamienia wspolrzedne [x, y] wszystkich punktow
		 *  na odpowiednie wspolrzedne [x, y, z], z uwzglednieniem macierzy
		 *  przeksztalcen.
		 */
		void prepare3dGraph();
		
		/**
		 *  Funkcja konwertujaca wspolrzedne punktu z pikseli na zakres [-1; 1].
		 *
         *  @param wxPoint Punkt o wspolrzednych w px. 
         *  @return wxRealPoint Punkt o wspolrzednych w zakresie [-1; 1].
         */
		wxRealPoint pointToReal(wxPoint);
		
		/**
		 *  Funkcja konwertujaca wspolrzedne punktu z zakresu [-1; 1] na piksele.
		 *
		 *  @param wxRealPoint Punkt o wspolrzednych z zakresu [-1; 1].
		 *  @return wxPoint Punkt o wspolrzednych w px.
		 */
		wxPoint pointToInt(wxRealPoint);
		
		/**
		 *  Funkcja sprawdza, czy na zadanych wspolrzednych jest jakikolwiek wezel figur.
		 *
		 *  @param wxRealPoint Punkt, ktory chcemy sprawdzic.
		 *  @return wxRealPoint Punkt, ktory pasuje do miejsca.
		 */
		wxRealPoint isPartOfAnyShape(wxRealPoint);
		
		/**
		 *  Funkcja sprawdza, czy na zadanych wspolrzednych jest poczatek aktualnie rysowanej krzywej.
		 *
		 *  @param wxRealPoint Punkt, ktory chcemy sprawdzic.
		 *  @return wxRealPoint Punkt, ktory pasuje do miejsca.
		 */
		wxRealPoint isPartOfCurrentShape(wxRealPoint);
		
		/**
		 *  Funkcja usuwajaca wszystkie ksztalty z wektora.
		 */
		void resetShapes();
		
		/**
		 *  Aktualny stan rysowania. Domyslnie - LINE.
		 */
		DrawingMode _mode;
		
		/**
		 *  Wektor wskaznikow do narysowanych juz ksztaltow (na wykresie 2d).
		 */
		std::vector<Shape*> _shapes;
		
		/**
		 *  Lista odcinkow 3d.
		 */
		std::vector<Line3d> _lines3d;
		
		/**
		 *  Ostatnio dodany do wykresu 2d punkt.
		 */
		wxRealPoint _lastAddedPoint;
		
		/**
		 *  Kolor uzywany aktualnie do rysowania.
		 */
		wxColour _currentColor;
		
		/**
		 *  Aktualnie rysowana krzywa lamana.
		 */
		Shape* _currentShape;
		
		/**
		 *  Parametry i opcje wykresu.
		 */
		Config _config;
		
		/**
		 *  Ponizej znajduja sie metody, ktore wyzwalane sa w momencie wystapienia odpowiednich zdarzen.
		 */
		
		void CloseChainClick(wxCommandEvent& event);
		void StitchPointClick(wxCommandEvent& event);
		void MouseLeftDown(wxMouseEvent& event);
		void MouseDoubleClick(wxMouseEvent& event);
		void MouseMove(wxMouseEvent& event);
        void changeModeToLine(wxCommandEvent& event);
        void changeModeToCurve(wxCommandEvent& event);
        void changeModeToChain(wxCommandEvent& event);
		void changeModeToRectangle(wxCommandEvent& event);
		void changeCurrentColor(wxCommandEvent& event);
		void toggleStitch(wxCommandEvent& event);
		void togglePoints(wxCommandEvent& event);
		void toggleClosing(wxCommandEvent& event);
		void repaint3d(wxCommandEvent& event);
		void changeRotateX(wxScrollEvent& event);
		void changeRotateY(wxScrollEvent& event);
		void changeRotateZ(wxScrollEvent& event);
		void createNewGraph(wxCommandEvent& event);
		void createNewGraph0(wxCommandEvent& event);
		void closeApp(wxCommandEvent& event);
		void saveFileClick(wxCommandEvent& event);
		void loadFileClick(wxCommandEvent& event);
};

#endif
