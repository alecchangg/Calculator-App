#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("Calculator");
	mainFrame->SetClientSize(400, 650);
	mainFrame->Center();
	mainFrame->Show(true);
	return true;
}