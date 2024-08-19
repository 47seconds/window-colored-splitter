#include <wx/wx.h>
#include <wx/splitter.h>

class MyApp : public wxApp
{
    public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
    public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Hello World!", wxDefaultPosition, wxDefaultSize);
    frame -> Show(true);
    return true;
}

// Setters

// MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
// {
//     wxPanel *panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200,100));
//     panel_top -> SetBackgroundColour(wxColor(100,100,200));
    
//     wxPanel *panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200,100));
//     panel_bottom -> SetBackgroundColour(wxColor(100,200,100));

//     wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
//     sizer -> Add(panel_top, 1, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 5);
//     sizer -> Add(panel_bottom, 1, wxEXPAND | wxALL, 5);

//     this -> SetSizerAndFit(sizer);
// }



// Splitters

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    wxSplitterWindow *splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);
    wxSplitterWindow *right_splitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);
    wxSplitterWindow *left_splitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);

    wxPanel *top_left = new wxPanel(left_splitter);
    wxPanel *bottom_left = new wxPanel(left_splitter);
    wxPanel *top_right = new wxPanel(right_splitter);
    wxPanel *bottom_right = new wxPanel(right_splitter);

    top_left -> SetBackgroundColour(wxColor(200,100,100));
    top_right -> SetBackgroundColour(wxColor(100,200,100));
    bottom_left -> SetBackgroundColour(wxColor(200,200,100));
    bottom_right -> SetBackgroundColour(wxColor(100,100,200));

    left_splitter -> SetMinimumPaneSize(100);
    left_splitter -> SplitHorizontally(top_left, bottom_left);

    right_splitter -> SetMinimumPaneSize(100);
    right_splitter -> SplitHorizontally(top_right, bottom_right);

    left_splitter -> SetSashGravity(0.5);
    right_splitter -> SetSashGravity(0.5);

    splitter -> SetMinimumPaneSize(200);
    splitter -> SplitVertically(left_splitter, right_splitter);

    splitter -> SetSashGravity(0.5);
}