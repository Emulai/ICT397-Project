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

	void SetLocalWindowSize(float t_newWindowWidth, float t_newWindowHeight){
		m_windowWidth = t_newWindowWidth;
		m_windowHeight = t_newWindowHeight;
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


	/****************************************
	 * returns a short indicating what button was pressed.
	 * Numbers start with 1 at the bottom button to 5 at the top button
	 * -1 is a sentinel for no interaction
	 * takes arguments originating from OpenGL API indicating location of a mouse click on screen
	 *
	 * Currently: 1= EXIT, 5=Return (to game state)
	****************************************/
	short CheckForButton(int t_x, int t_y){
		
		//testing indicates y value is inverted compared to draw location(x is okay apparently)
		//this conversion fixes that
		t_y = m_windowHeight-t_y;
		
		if(t_x <= (2*m_windowWidth/3) && t_x >= (m_windowWidth/3)){
			if(t_y <= (2*m_windowHeight/10) && t_y >= (m_windowHeight/10)){
				std::cout << "Button 1 " << std::endl;//<< m_windowHeight << " : " << 2*m_windowHeight/10 << " " << m_windowHeight/10 << " " << y << std::endl;
				return(1);
			}else if(t_y <= (3*m_windowHeight/10) && t_y >= (2*m_windowHeight/10)){
				std::cout << "Button 2 " << std::endl;//<< m_windowHeight << " : " << 3*m_windowHeight/10 << " " <<2* m_windowHeight/10 << " " << y << std::endl;
				return(2);
			}else if(t_y <= (4*m_windowHeight/10) && t_y >= (3*m_windowHeight/10)){
				std::cout << "Button 3 " << std::endl;//<< m_windowHeight << " : " << 4*m_windowHeight/10 << " " << 3*m_windowHeight/10 << " " << y << std::endl;
				return(3);
			}else if(t_y <= (5*m_windowHeight/10) && t_y >= (4*m_windowHeight/10)){
				std::cout << "Button 4 " << std::endl;//<< m_windowHeight << " : " << 5*m_windowHeight/10 << " " << 4*m_windowHeight/10 << " " << y << std::endl;
				return(4);
			}else if(t_y <= (6*m_windowHeight/10) && t_y >= (5*m_windowHeight/10)){
				std::cout << "Button 5 " << std::endl;//<< m_windowHeight << " : " << 6*m_windowHeight/10 << " " << 5*m_windowHeight/10 << " " << y  << std::endl;
				return(5);
			}else{
				std::cout << "NO BUTTON (internal) " << std::endl;//<< m_windowHeight << " : " << 6*m_windowHeight/10 << " " << m_windowHeight/10 << " " << y  ;
				return(-1);
			}
		}
		std::cout << "NO BUTTON (external)" << std::endl;//<<m_windowWidth << " : " << 2*m_windowWidth/3 << " " << m_windowWidth/3 << " " << x 
		return(-1);
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