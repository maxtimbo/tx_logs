// mainWindow.cpp

#include "mainWindow.h"

appFrame::appFrame(const wxString& title)
    : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxDefaultSize) {

        wxSplitterWindow *splits = new wxSplitterWindow(this, wxID_ANY);
        splits->SetMinimumPaneSize(50);
        
        wxPanel *masterPanel = new wxPanel(this, -1);
        wxBoxSizer *masterSizer = new wxBoxSizer(wxVERTICAL);

        /*
         * Top bar
         */
        wxPanel *topBarPanel = new wxPanel(masterPanel, -1);
        wxBoxSizer *topBarSizer = new wxBoxSizer(wxHORIZONTAL);

        wxStaticText *sites = new wxStaticText(topBarPanel, -1, wxT("Sites"));
        wxStaticText *siteHeader = new wxStaticText(topBarPanel, -1,
                wxT("Current"));
        wxSizerFlags topBarStyles(0);
        topBarStyles.Expand();
        topBarSizer->Add(sites, topBarStyles);
//        topBarSizer->Add(siteHeader, topBarStyles);
        topBarPanel->SetSizer(topBarSizer);
        masterSizer->Add(topBarPanel, 0, wxEXPAND);

        /*
         * Side Bar
         */
        wxPanel *sidePanel = new wxPanel(splits, -1);
        wxBoxSizer *sideSizer = new wxBoxSizer(wxVERTICAL);

        wxStaticText *placeHolder = new wxStaticText(sidePanel, -1, wxT("PlaceH"));
        sideSizer->Add(placeHolder, 0, wxEXPAND);
        sidePanel->SetSizer(sideSizer);

        /*
         * View Panel
         */
        wxPanel *viewPanel = new wxPanel(splits, -1);
        wxBoxSizer *viewSizer = new wxBoxSizer(wxHORIZONTAL);

        sitesLog *rincon = new sitesLog(viewPanel, wxT("Rincon"));
        viewSizer->Add(rincon, 0, wxEXPAND);
        viewPanel->SetSizer(viewSizer);

        /*
         * Splitter
         */
        splits->SplitVertically(sidePanel, viewPanel);
        masterSizer->Add(splits, 0, wxEXPAND);
        SetSizerAndFit(masterSizer);

//        masterSizer->Add(topBar, 0, wxEXPAND);
//        masterSizer->Add(sideBar, 1, wxEXPAND);
//        masterSizer->Add(viewMain, 0, wxEXPAND);

//        masterPanel->SetSizerAndFit(masterSizer);
        
        CreateStatusBar();
        SetStatusText("Testing");
        Center();
        Layout();
    }

