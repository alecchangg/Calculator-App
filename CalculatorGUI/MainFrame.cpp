#include "MainFrame.h"
#include <wx/wx.h>


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	wxStaticText* screen = new wxStaticText(panel, wxID_ANY, "Welcome", wxPoint(0, 0), wxSize(400, 150));
	wxButton* leftParenButton = new wxButton(panel, wxID_ANY, "(", wxPoint(0, 150), wxSize(100, 100));
	wxButton* rightParenButton = new wxButton(panel, wxID_ANY, ")", wxPoint(100, 150), wxSize(100, 100));
	wxButton* signButton = new wxButton(panel, wxID_ANY, "+/-", wxPoint(200, 150), wxSize(100, 100));
	wxButton* divButton = new wxButton(panel, wxID_ANY, "/", wxPoint(300, 150), wxSize(100, 100));
	wxButton* sevenButton = new wxButton(panel, wxID_ANY, "7", wxPoint(0, 250), wxSize(100, 100));
	wxButton* eightButton = new wxButton(panel, wxID_ANY, "8", wxPoint(100, 250), wxSize(100, 100));
	wxButton* nineButton = new wxButton(panel, wxID_ANY, "9", wxPoint(200, 250), wxSize(100, 100));
	wxButton* multButton = new wxButton(panel, wxID_ANY, "x", wxPoint(300, 250), wxSize(100, 100));
	wxButton* fourButton = new wxButton(panel, wxID_ANY, "4", wxPoint(0, 350), wxSize(100, 100));
	wxButton* fiveButton = new wxButton(panel, wxID_ANY, "5", wxPoint(100, 350), wxSize(100, 100));
	wxButton* sixButton = new wxButton(panel, wxID_ANY, "6", wxPoint(200, 350), wxSize(100, 100));
	wxButton* subButton = new wxButton(panel, wxID_ANY, "-", wxPoint(300, 350), wxSize(100, 100));
	wxButton* oneButton = new wxButton(panel, wxID_ANY, "1", wxPoint(0, 450), wxSize(100, 100));
	wxButton* twoButton = new wxButton(panel, wxID_ANY, "2", wxPoint(100, 450), wxSize(100, 100));
	wxButton* threeButton = new wxButton(panel, wxID_ANY, "3", wxPoint(200, 450), wxSize(100, 100));
	wxButton* plusButton = new wxButton(panel, wxID_ANY, "+", wxPoint(300, 450), wxSize(100, 100));
	wxButton* zeroButton = new wxButton(panel, wxID_ANY, "0", wxPoint(0, 550), wxSize(100, 100));
	wxButton* dotButton = new wxButton(panel, wxID_ANY, ".", wxPoint(100, 550), wxSize(100, 100));
	wxButton* clearButton = new wxButton(panel, wxID_ANY, "C", wxPoint(200, 550), wxSize(100, 100));
	wxButton* enterButton = new wxButton(panel, wxID_ANY, "=", wxPoint(300, 550), wxSize(100, 100));

	
	
	wxColour* orange = new wxColour(255, 140, 0);
	
	panel->SetBackgroundColour(*wxBLACK);
	screen->SetBackgroundColour(*wxBLACK);
	screen->SetForegroundColour(*wxWHITE);
	leftParenButton->SetBackgroundColour(*wxLIGHT_GREY);
	rightParenButton->SetBackgroundColour(*wxLIGHT_GREY);
	signButton->SetBackgroundColour(*wxLIGHT_GREY);
	sevenButton->SetBackgroundColour(*wxLIGHT_GREY);
	eightButton->SetBackgroundColour(*wxLIGHT_GREY);
	nineButton->SetBackgroundColour(*wxLIGHT_GREY);
	fourButton->SetBackgroundColour(*wxLIGHT_GREY);
	fiveButton->SetBackgroundColour(*wxLIGHT_GREY);
	sixButton->SetBackgroundColour(*wxLIGHT_GREY);
	oneButton->SetBackgroundColour(*wxLIGHT_GREY);
	twoButton->SetBackgroundColour(*wxLIGHT_GREY);
	threeButton->SetBackgroundColour(*wxLIGHT_GREY);
	zeroButton->SetBackgroundColour(*wxLIGHT_GREY);
	dotButton->SetBackgroundColour(*wxLIGHT_GREY);



	divButton->SetBackgroundColour(*orange);
	multButton->SetBackgroundColour(*orange);
	subButton->SetBackgroundColour(*orange);
	plusButton->SetBackgroundColour(*orange);
	clearButton->SetBackgroundColour(*orange);
	enterButton->SetBackgroundColour(*orange);
}
