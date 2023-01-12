#include "MainFrame.h"
#include "Calculator.h"
#include <wx/wx.h>

#define WINDOW_STYLE (wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
#define NUM_BUTTONS 20
#define BUTTON_FONT_SIZE 30
#define INPUT_DISPLAY_FONT_SIZE 30
#define OUTPUT_DISPLAY_FONT_SIZE 17
#define INPUT_DISPLAY_ID 69

enum BUTTON_ID {
	left_parenthesis = 0, right_parenthesis, sign_change, division,
	seven, eight, nine, multiplication,
	four, five, six, subtraction,
	one, two, three, addition,
	zero, decimal, display_clear, equals
};

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, WINDOW_STYLE) {

	wxPanel* main_panel = new wxPanel(this);
	main_panel->SetBackgroundColour(*wxBLACK);

	wxStaticText* input_display = new wxStaticText(main_panel, INPUT_DISPLAY_ID, "", wxPoint(0, 90), wxSize(400, -1), wxALIGN_RIGHT);
	wxFont* input_display_font = new wxFont(INPUT_DISPLAY_FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	input_display->SetFont(*input_display_font);
	input_display->SetBackgroundColour(*wxBLACK);
	input_display->SetForegroundColour(*wxWHITE);

	wxStaticText* output_display = new wxStaticText(main_panel, wxID_ANY, "", wxPoint(0, 25), wxSize(400, -1), wxALIGN_RIGHT);
	wxFont* output_display_font = new wxFont(OUTPUT_DISPLAY_FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	output_display->SetFont(*output_display_font);
	output_display->SetBackgroundColour(*wxBLACK);
	output_display->SetForegroundColour(*wxWHITE);

	wxButton* buttons[] = {
		new wxButton(main_panel, left_parenthesis, "(", wxPoint(0, 150), wxSize(100, 100)),
		new wxButton(main_panel, right_parenthesis, ")", wxPoint(100, 150), wxSize(100, 100)),
		new wxButton(main_panel, sign_change, "+/-", wxPoint(200, 150), wxSize(100, 100)),
		new wxButton(main_panel, division, "/", wxPoint(300, 150), wxSize(100, 100)),
		new wxButton(main_panel, seven, "7", wxPoint(0, 250), wxSize(100, 100)),
		new wxButton(main_panel, eight, "8", wxPoint(100, 250), wxSize(100, 100)),
		new wxButton(main_panel, nine, "9", wxPoint(200, 250), wxSize(100, 100)),
		new wxButton(main_panel, multiplication, "x", wxPoint(300, 250), wxSize(100, 100)),
		new wxButton(main_panel, four, "4", wxPoint(0, 350), wxSize(100, 100)),
		new wxButton(main_panel, five, "5", wxPoint(100, 350), wxSize(100, 100)),
		new wxButton(main_panel, six, "6", wxPoint(200, 350), wxSize(100, 100)),
		new wxButton(main_panel, subtraction, "-", wxPoint(300, 350), wxSize(100, 100)),
		new wxButton(main_panel, one, "1", wxPoint(0, 450), wxSize(100, 100)),
		new wxButton(main_panel, two, "2", wxPoint(100, 450), wxSize(100, 100)),
		new wxButton(main_panel, three, "3", wxPoint(200, 450), wxSize(100, 100)),
		new wxButton(main_panel, addition, "+", wxPoint(300, 450), wxSize(100, 100)),
		new wxButton(main_panel, zero, "0", wxPoint(0, 550), wxSize(100, 100)),
		new wxButton(main_panel, decimal, ".", wxPoint(100, 550), wxSize(100, 100)),
		new wxButton(main_panel, display_clear, "C", wxPoint(200, 550), wxSize(100, 100)),
		new wxButton(main_panel, equals, "=", wxPoint(300, 550), wxSize(100, 100))
	};
	wxColour* button_color = new wxColour(255, 140, 0);
	wxFont* button_font = new wxFont(BUTTON_FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	for (int i = 0; i < NUM_BUTTONS; i++) {

		if (i % 4 == 3) {
			buttons[i]->SetBackgroundColour(*button_color);
		}

		else {
			buttons[i]->SetBackgroundColour(*wxLIGHT_GREY);
		}

		buttons[i]->SetFont(*button_font);
		buttons[i]->Bind(wxEVT_BUTTON, &MainFrame::ButtonClick, this);
	}

	CreateStatusBar();
}

void MainFrame::ButtonClick(wxCommandEvent& evt) {
	int button_id = evt.wxEvent::GetId();
	wxButton* button = (wxButton*) evt.wxEvent::GetEventObject();
	wxPanel* main_panel = (wxPanel*) button->GetParent();
	wxStaticText* input_display = (wxStaticText*) main_panel->wxWindow::FindWindow(INPUT_DISPLAY_ID);

	wxString display_text = input_display->GetLabel();
	wxString button_text = button->GetLabel();

	switch (button_id) {
		case left_parenthesis:
			display_text = display_text + "( ";
			break;
		case right_parenthesis:
			display_text = display_text + " )";
			break;
		case sign_change:
			display_text = display_text + "-";
			break;
		case division:
			display_text = display_text + " / ";
			break;
		case seven:
			display_text = display_text + "7";
			break;
		case eight:
			display_text = display_text + "8";
			break;
		case nine:
			display_text = display_text + "9";
			break;
		case multiplication:
			display_text = display_text + " * ";
			break;
		case four:
			display_text = display_text + "4";
			break;
		case five:
			display_text = display_text + "5";
			break;
		case six:
			display_text = display_text + "6";
			break;
		case subtraction:
			display_text = display_text + " - ";
			break;
		case one:
			display_text = display_text + "1";
			break;
		case two:
			display_text = display_text + "2";
			break;
		case three:
			display_text = display_text + "3";
			break;
		case addition:
			display_text = display_text + " + ";
			break;
		case zero:
			display_text = display_text + "0";
			break;
		case decimal:
			display_text = display_text + ".";
			break;
		case display_clear:
			display_text = "";
			break;
		case equals:
			//create calculator
			//SetExpression
			// IsValid
			//if yes: Calculate -> set displays
			//if no: warning -> set displays

			std::string expression = std::string(display_text.mb_str());

			Calculator c = Calculator();

			c.SetExpression(expression);
			expression = c.Calculate();

			wxString result(expression);
			display_text = result;

			break;
	}

	input_display->SetLabel(display_text);

	//wxLogStatus(button_text + " " + display_text);
}