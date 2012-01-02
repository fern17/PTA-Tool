#include "wx/wx.h"

class Visual : public wxApp{
	public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame {
	public:
	MyFrame(const wxString &title);

	void OnQuit(wxCommandEvent & event);
	void OnAbout(wxCommandEvent & event);

	private:
	DECLARE_EVENT_TABLE();
};

DECLARE_APP(Visual)

IMPLEMENT_APP(Visual)

bool Visual::OnInit(){
	MyFrame * frame = new MyFrame(wxT("PTA Tool"));
	frame->Show(true);
	return true;
}

BEGIN_EVENT_TABLE(MyFrame,wxFrame)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
	EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent & event){
	wxString msg;
	msg.Printf(wxT("PTA Tool Alpha"));
	wxMessageBox(msg, wxT("About PTA Tool"),wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent & event){
	Close();
}

MyFrame::MyFrame(const wxString & title) : wxFrame(NULL, wxID_ANY, title) {
	wxMenu * fileMenu = new wxMenu;
	wxMenu * helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT, wxT("About"), wxT("About dialog"));
	fileMenu->Append(wxID_EXIT, wxT("Exit"), wxT("Quit this program"));
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu,wxT("File"));
	menuBar->Append(helpMenu,wxT("Help"));
	SetMenuBar(menuBar);

	CreateStatusBar(2);
	SetStatusText(wxT("Welcome to PTA Tool"));
}
