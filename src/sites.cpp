// sites.cpp
#include "sites.h"

sitesLog::sitesLog(wxWindow *parent, const wxString& city)
    : wxNotebook(parent, -1, wxDefaultPosition, wxDefaultSize,
            wxNB_TOP, city) {
        
        wxPanel *logEntryPanel = new wxPanel(this, -1);
        wxBoxSizer *logEntrySizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer *headEntry = new wxBoxSizer(wxHORIZONTAL);

        // Set Flags for easier repilacation
        wxSizerFlags logEntryFlags(1);
        logEntryFlags.Border(wxALL, 10).Top().Left();
        
        wxStaticText *initialsLbl = new wxStaticText(logEntryPanel, -1, wxT("Initials: "));
        wxTextCtrl *initialsEntry = new wxTextCtrl(logEntryPanel, -1, wxEmptyString,
                wxDefaultPosition, wxDefaultSize);
        wxStaticText *datePickerLbl = new wxStaticText(logEntryPanel, -1, wxT("Date: "));
        wxTextCtrl *datePickerEntry = new wxTextCtrl(logEntryPanel, -1);
        
        wxStaticText *notesLbl = new wxStaticText(logEntryPanel, -1, wxT("Site Visit Notes: "));
        wxRichTextCtrl *notesEntry = new wxRichTextCtrl(logEntryPanel, -1, wxEmptyString,
                wxDefaultPosition, wxDefaultSize, 0);

        headEntry->Add(initialsLbl, logEntryFlags);
        headEntry->Add(initialsEntry, logEntryFlags);
        headEntry->Add(datePickerLbl, logEntryFlags);
        headEntry->Add(datePickerEntry, logEntryFlags);

        logEntrySizer->Add(headEntry, 0, wxEXPAND);
        logEntrySizer->Add(notesLbl, 0, wxEXPAND);
        logEntrySizer->Add(notesEntry, 1, wxEXPAND);

        logEntryPanel->SetSizerAndFit(logEntrySizer);
        Center();
        Layout();

        this->AddPage(logEntryPanel, wxT("Log Entry"), true);
    }
