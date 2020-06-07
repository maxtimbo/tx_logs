// sites.h
#pragma once
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/sizer.h>
#include <wx/splitter.h>

class sitesLog: public wxNotebook {
    public:
        sitesLog(wxWindow *parent, const wxString& city);
};
