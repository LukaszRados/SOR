#include "SORApp.h"
#include "SOR.h"

IMPLEMENT_APP(SORApp)

bool SORApp::OnInit()
{
    SOR* frame = new SOR(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int SORApp::OnExit()
{
	return 0;
}
