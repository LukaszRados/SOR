#include <wx/print.h>
class Printout : public wxPrintout
{
    wxMemoryDC & myMemDC;
public:
    Printout( wxMemoryDC & memDC)
        : myMemDC( memDC )
    {
    }
    bool OnPrintPage( int PageNum )
    {
        // copy saved dispay to printer DC

        GetDC()->StretchBlit(0,0,5000,5000,
            &myMemDC, 0, 0, 500,500 );

        return true;
    }

};
