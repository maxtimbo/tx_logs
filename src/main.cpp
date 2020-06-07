//#include <wx/wx.h>
#include "appConstructor.h"
#include "mainWindow.h"

wxIMPLEMENT_APP(appConstructor);

bool appConstructor::OnInit() {
    appFrame *mainFrame = new appFrame(wxT("some words"));
    mainFrame->Show(true);
    return true;
}


