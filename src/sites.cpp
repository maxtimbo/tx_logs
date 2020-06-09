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
        logEntryFlags.Border(wxALL, 10).Left();
        wxSizerFlags leftFlag(1);
        leftFlag.Right();
        wxSizerFlags rightFlag(1);
        rightFlag.Left();
        
        /*
         * Header
         * Initals
         */
        wxPanel *initialsPanel = new wxPanel(logEntryPanel);
        wxBoxSizer *initials = new wxBoxSizer(wxHORIZONTAL);
        wxStaticText *initialsLbl = new wxStaticText(
                                                     initialsPanel,
                                                     -1,
                                                     wxT("Initials: "),
                                                     wxDefaultPosition,
                                                     wxDefaultSize,
                                                     wxALIGN_RIGHT
                                                     );
        wxTextCtrl *initialsEntry = new wxTextCtrl(
                                                   initialsPanel,
                                                   -1,
                                                   wxEmptyString,
                                                   wxDefaultPosition, 
                                                   wxDefaultSize
                                                   );
        initials->Add(initialsLbl, leftFlag);
        initials->Add(initialsEntry, rightFlag);
        initialsPanel->SetSizerAndFit(initials);
        headEntry->Add(initialsPanel, logEntryFlags);

        /*
         * Date Picker
         */
        wxPanel *datePanel = new wxPanel(logEntryPanel);
        wxBoxSizer *datePick = new wxBoxSizer(wxHORIZONTAL);

        wxStaticText *datePickerLbl = new wxStaticText(
                                                       datePanel,
                                                       -1,
                                                       wxT("Date: "),
                                                       wxDefaultPosition,
                                                       wxDefaultSize,
                                                       wxALIGN_RIGHT
                                                       );
        wxDatePickerCtrl *datePicker = new wxDatePickerCtrl(datePanel, -1);

        datePick->Add(datePickerLbl, leftFlag);
        datePick->Add(datePicker, rightFlag);
        datePanel->SetSizerAndFit(datePick);
        headEntry->Add(datePanel, logEntryFlags);
        
        /*
         * Notes Input
         */
        wxStaticText *notesLbl = new wxStaticText(logEntryPanel, -1, wxT("Site Visit Notes: "));
        wxRichTextCtrl *notesEntry = new wxRichTextCtrl(
                                                        logEntryPanel,
                                                        -1,
                                                        wxEmptyString,
                                                        wxDefaultPosition,
                                                        wxSize(100, 150),
                                                        0
                                                        );

        logEntrySizer->Add(headEntry, 0, wxEXPAND | wxALIGN_LEFT);
        logEntrySizer->Add(notesLbl, 0, wxEXPAND | wxALL, 10);
        logEntrySizer->Add(notesEntry, 1, wxEXPAND | wxALL, 10);

        logEntryPanel->SetSizerAndFit(logEntrySizer);
        Center();
        Layout();

        this->AddPage(logEntryPanel, wxT("Log Entry"), true);
    }
