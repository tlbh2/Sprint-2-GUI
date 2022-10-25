#include "cMain.h"
//this is about the window

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_TEXT_ENTER(1000, cMain::BoardSize)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "SOS Game", wxPoint(40, 40), wxSize(600, 350))
{
	InitializeComponent();

}

cMain::~cMain()
{
	//prevent memory leak
	//delete[]btn;
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	//Get coordinate of button in field array
	int x = (evt.GetId() - 10000) % length_int;
	int y = (evt.GetId() - 10000) / length_int;

	if (object.CurrentPlayer == object.Bplayer)
	{
		//set label to button once pressed
		btn[y * length_int + x]->SetLabel(object.s);
	}
	if (object.CurrentPlayer == object.Rplayer)
	{
		//set label to button once pressed
		btn[y * length_int + x]->SetLabel(object.o);
	}

	//Disable Button, preventing it being pressed again
	btn[y * length_int + x]->Enable(false);

	object.SetNextPlayer();
	m_txt2 = new wxStaticText(this, wxID_ANY, object.CurrentPlayer + " Player", wxPoint(300, 275), wxSize(150, 50));

	evt.Skip();
}

void cMain::BoardSize(wxCommandEvent& evt)
{
	/*
	length_string = m_txt1->GetValue();
	stringstream StringToInt(length_string);                                                                                  	// object from the class stringstream
	StringToInt >> length_int;
	set_Length(length_int);
	*/

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	InitializeTable(font, length_int);

}

