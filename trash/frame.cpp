#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
//#include <wx/wx.h>
#include "frame.h"

//
appFrame::appFrame(const wxString& title) 
    : wxFrame(NULL, wxID_ANY, title) {
        // Sizer Functions
        wxSizerFlags expanded(1);
        expanded.Border(wxALL, 1);
        //mainWindow->Add(panel, expanded);
        mainWindow->Add(sites);
        mainWindow->Add(views);
        views->AddPage(textBox, wxString("&Test"), true);
        //views->AddPage(0, textBox, wxString("&Test"), true);
       // wxBoxSizer* textSizer = new wxBoxSizer(wxHORIZONTAL);
       // textSizer->Add(textBox, 1, wxEXPAND);
       // //panel->SetSizer(textSizer);
//     //   views->SetSizer(textSizer);

       // wxBoxSizer* viewsSizer = new wxBoxSizer(wxHORIZONTAL);
       // viewsSizer->Add(views, 1, wxEXPAND);
       // panel->SetSizer(viewsSizer);

       // wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
       // panelSizer->Add(sites, 1, wxEXPAND);
       // panelSizer->Add(panel, 2, wxEXPAND);
       // SetSizerAndFit(panelSizer);
       // SetSizerAndFit(viewsSizer);

        //Create File Menu
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(wxID_NEW, "&Create...\tCtrl-N", "Create New File");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_OPEN, "&Open...\tCtrl-O", "Open File");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_SAVE, "&Save\tCtrl-S", "Save Changes");
        menuFile->Append(wxID_SAVEAS, "&Save As...\tCtrl-Shift-S", "Save File As");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT, "&Exit", "Exit Program");
        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        SetMenuBar(menuBar);
    
        //Create the Status Bar and populate it with initial text
        CreateStatusBar();
        SetStatusText("Simple Text Editor, so far....");
    
        Bind(wxEVT_MENU, &appFrame::OnExit, this, wxID_EXIT);
        Bind(wxEVT_MENU, &appFrame::OnNew, this, wxID_NEW);
        Bind(wxEVT_MENU, &appFrame::OnOpen, this, wxID_OPEN);
        Bind(wxEVT_MENU, &appFrame::OnSaveAs, this, wxID_SAVEAS);
        Bind(wxEVT_MENU, &appFrame::OnSave, this, wxID_SAVE);
    //Bind(wxEVT_STC_CHANGE, &Frame::OnModified, this);
}


void appFrame::OnNew(wxCommandEvent& event) {
    fileName = "";
//    textBox->ClearAll();
    SetStatusText("New File");
}


void appFrame::OnOpen(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, "Open File", "", "",
            "Text file (*.txt) | *.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    fileName = openFileDialog.GetPath();
    
    if (textBox->LoadFile(fileName))
        SetStatusText("Opened File: " + fileName);
    else
        SetStatusText("Unable to open file: " + fileName);
}


void appFrame::OnSaveAs(wxCommandEvent& event) {
    wxFileDialog saveFileDialog(this, "Save File", "", "",
            "Text file (*.txt) | *.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;
    
    fileName = saveFileDialog.GetPath();

    if (textBox->SaveFile(fileName))
        SetStatusText("File saved as: " + fileName);
    else
        SetStatusText("Unable to save file: " + fileName);
}


inline void appFrame::OnSave(wxCommandEvent& event) {
    if (fileName.length() > 0) {
        //if (textBox->GetModify()) {
            if (textBox->SaveFile(fileName))
                SetStatusText("File Saved");
            else
                SetStatusText("Unable to Save File.");
        //}
    }
    else {
        OnSaveAs(event);
    }
}


void appFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

//
//void appFrame::OnModified(wxStyledTextEvent& event) {
//    if (textBox->GetModify()) {
//        SetStatusText("File Modified");
//    } else {
//        SetStatusText("No Changes");
//    }
//}
