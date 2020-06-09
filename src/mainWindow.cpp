// mainWindow.cpp

#include "mainWindow.h"

appFrame::appFrame(const wxString& title)
    : wxFrame(NULL, -1, title) {

        wxSplitterWindow *splits = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE);
        splits->SetMinimumPaneSize(50);
        
        wxPanel *masterPanel = new wxPanel(this, -1);
        wxBoxSizer *masterSizer = new wxBoxSizer(wxVERTICAL);

        /*
         * Top bar
         */
        wxPanel *topBarPanel = new wxPanel(masterPanel, -1);
        wxBoxSizer *topBarSizer = new wxBoxSizer(wxHORIZONTAL);

        wxStaticText *sites = new wxStaticText(
                topBarPanel,
                -1,
                wxString("Sites"),
                wxDefaultPosition,
                wxDefaultSize,
                wxALIGN_LEFT
                );
        wxStaticText *siteHeader = new wxStaticText(
                topBarPanel,
                -1,
                wxT("Current"),
                wxDefaultPosition,
                wxDefaultSize,
                wxALIGN_CENTER
                );

        // Sizer Flags is currently unused 
        wxSizerFlags topBarStyles(0);
        topBarStyles.Expand().Border(wxALL, 10).Center();

        topBarSizer->Add(sites, topBarStyles);
        topBarSizer->Add(siteHeader, topBarStyles);
        topBarPanel->SetSizerAndFit(topBarSizer);

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
        splits->SplitVertically(sidePanel, viewPanel, 50);
        masterSizer->Add(splits, 0, wxEXPAND);
        masterPanel->SetSizerAndFit(masterSizer);

        CreateStatusBar();
        SetStatusText("Testing");
//        Center();
//        Layout();
    }

