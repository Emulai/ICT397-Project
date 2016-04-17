#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <GL/glut.h>

class View
{
public:

	/**
        * @brief Default constructor of class View
        *
        * This constructor sets the variables of class View to the default
        * values
        *
        */
	View();

	/**
        * @brief Renders models from the model list
        *
        * This function sets the Vector3 for transform of the GameObject to that supplied
        * by the client program
        *
        * @param int t_modelReference - Model Reference number
        * @return void
        */
	void Render(int t_modelReference);

	//////////////////////////
	//Function to DISPLAY menus here
	//Menu INTERACTION in Controller
	//////////////////////////

	void SetLocalWindowSize(float newWindowWidth, float newWindowHeight){
		m_windowWidth = newWindowWidth;
		m_windowHeight = newWindowHeight;
	}

	void EnterMenuState(){
		std::cout << "Switching to menu state" << std::endl;
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		gluOrtho2D(0.0f, GetWindowWidth(), 0.0f, GetWindowHeight());// 0.0f, 0.0f, 1.0f
		//glDisable(GLUT_DEPTH);

		glMatrixMode(GL_MODELVIEW);
		glutPostRedisplay();
	}

	void MenuView(){
		glLoadIdentity();
		gluLookAt(	0.0, 1.0f, 0.0,
					0.0, 1.0f,  -1.0,
					0.0f, 1.0f,  0.0f);

		glBegin(GL_QUADS);
			glColor3f(0.5f,0.5f,0.5f);
			glVertex3f(0, 0, 0);
			glVertex3f(0, m_windowHeight, 0);
			glVertex3f(m_windowWidth, m_windowHeight, 0);
			glVertex3f(m_windowWidth, 0, 0);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(1.0, 0.0, 0.75);
			glVertex3f(2*m_windowWidth/3, m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 2*m_windowHeight/10, 0.1f);
			glVertex3f(2*m_windowWidth/3, 2*m_windowHeight/10, 0.1f);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(2*m_windowWidth/3, 2*m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 2*m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 3*m_windowHeight/10, 0.1f);
			glVertex3f(2*m_windowWidth/3, 3*m_windowHeight/10, 0.1f);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(2*m_windowWidth/3, 3*m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 3*m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 4*m_windowHeight/10, 0.1f);
			glVertex3f(2*m_windowWidth/3, 4*m_windowHeight/10, 0.1f);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(2*m_windowWidth/3, 4*m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 4*m_windowHeight/10, 0.1f);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(m_windowWidth/3, 5*m_windowHeight/10, 0.1f);
			glVertex3f(2*m_windowWidth/3, 5*m_windowHeight/10, 0.1f);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(1.0, 0.0, 1.0);
			glVertex3f(2*m_windowWidth/3, 5*m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 5*m_windowHeight/10, 0.1f);
			glVertex3f(m_windowWidth/3, 6*m_windowHeight/10, 0.1f);
			glVertex3f(2*m_windowWidth/3, 6*m_windowHeight/10, 0.1f);
		glEnd();
	}

	short CheckForButton(int x, int y){
		if(x >= (2*m_windowWidth/3) && x >= (m_windowWidth/3)){

		}
		return(0);
	}

	float GetWindowWidth(){
		return(m_windowWidth);
	}
	float GetWindowHeight(){
		return(m_windowHeight);
	}

private:

	float m_windowWidth, m_windowHeight;

};

#endif