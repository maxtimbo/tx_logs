// frame.h
#pragma once
#include <wx/frame.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/sizer.h>

class appFrame: public wxFrame {
    public:
        appFrame(const wxString& title);
        wxFlexGridSizer* mainWindow = new wxFlexGridSizer(2, 2, 3, 3);
//        wxPanel* panel = new wxPanel(mainWindow, wxID_ANY);
        wxStaticText* sites = new wxStaticText(this, -1, wxString("&Sites"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT, wxString("&Sites"));
        wxNotebook* views = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP, wxString("&Test"));
        wxRichTextCtrl* textBox = new wxRichTextCtrl(views, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    protected:
        void OnNew(wxCommandEvent& event); 
        void OnOpen(wxCommandEvent& event); 
        void OnSaveAs(wxCommandEvent& event); 
        void OnSave(wxCommandEvent& event); 
        void OnExit(wxCommandEvent& event); 
        wxString fileName;
};





