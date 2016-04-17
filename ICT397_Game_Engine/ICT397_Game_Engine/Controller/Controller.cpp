#include "Controller.h"

Controller::Controller()
{
	m_model.SetView(&m_view);
	m_model.LuaSettings();
	m_modelIsLoaded = false;
}

void Controller::ModelTest(string mPath, int iNdex)
{
	if(!m_modelIsLoaded)
	{
	m_model.LoadModels(mPath, iNdex);
	m_modelIsLoaded = true;
	}
}

void Controller::GameCtrl(float t_x, float t_z, float t_lx, float t_lz){
	m_view.GameView(t_x, t_z, t_lx, t_lz);
}

/////////////////////
//INTERACTION with menu here
//Menu DISPLAY is in View
/////////////////////
void Controller::MenuCtrl(){
	m_view.MenuView();
}

void Controller::Credits(){
	std::cout << "TODO: ADD CREDITS" << std::endl;
}

void Controller::Options(){
	std::cout << "TODO: ADD OPTIONS" << std::endl;
}

void Controller::ListCheckpoints(){
	std::cout << "TODO: ADD SAVE LIST" << std::endl;
	std::cout << "TODO: ADD SAVE OPTION" << std::endl;
	std::cout << "TODO: ADD LOAD OPTION" << std::endl;
}

void Controller::MenuPress(int t_x, int t_y){
	short l_actionType;
	extern short g_gameState;

	l_actionType = m_view.CheckForButton(t_x, t_y);

	switch(l_actionType){
		//terminate program
		case 1: exit(0);
			break;
		case 2: ListCheckpoints();
			break;
		case 3: Credits();
			break;
		case 4: Options();
			break;
		//Exit menu to game state
		case 5: g_gameState = 0;
			EnterGameState();
			break;
	}
}

void Controller::MenuInit(float t_windowWidth, float t_windowHeight){
	m_view.SetLocalWindowSize(t_windowWidth, t_windowHeight);
}

float Controller::GetWindowWidth(){
	return(m_view.GetWindowWidth());
}
float Controller::GetWindowHeight(){
	return(m_view.GetWindowHeight());
}

void Controller::EnterMenuState(){
	m_view.EnterMenuState();
}

void Controller::EnterGameState(){
	m_view.EnterGameState();
}