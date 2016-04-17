#include "View.h"


View::View()
{
	
}

void View::LoadModel(string t_modelPath, const int t_index)
{
	m_debug = m_off.Load(t_modelPath, t_index);
	cout << m_debug.c_str();
}

void View::Render()
{
	m_off.Draw(0);

	//Render model from reference list created when models are read
	//REFERENCE LIST NOT IMPLEMENTED

	//Will likely need to include the objectloader, wherever the model list is stored.
	//At the very least will need to be passed a pointer reference to the model list.
	//If including the objloader, a pointer will need to be passed to View to point it to the
	//correct instance of the objloader

}

void View::SetModelNum(int t_size)
{
	m_off.SetModelNum(t_size);
}
