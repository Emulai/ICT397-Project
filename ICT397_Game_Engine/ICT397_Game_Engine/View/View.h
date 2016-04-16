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

	void MenuView(int windowHeight, int windowWidth){
		glLoadIdentity();
		gluLookAt(	0.0, 1.0f, 0.0,
					0.0, 1.0f,  -1.0,
					0.0f, 1.0f,  0.0f);

		glColor3f(0.5f,0.5f,0.5f);
		glBegin(GL_QUADS);
			glVertex3i(0, 0, 0);
			glVertex3i(0, windowHeight, 0);
			glVertex3i(windowWidth, windowHeight, 0);
			glVertex3i(windowWidth, 0, 0);
		glEnd();

		glColor3f(1.0, 0.0, 0.75);
		glBegin(GL_POLYGON);
			glVertex3f(2*windowWidth/3, windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 2*windowHeight/10, 0.1);
			glVertex3f(2*windowWidth/3, 2*windowHeight/10, 0.1);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex3f(2*windowWidth/3, 2*windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 2*windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 3*windowHeight/10, 0.1);
			glVertex3f(2*windowWidth/3, 3*windowHeight/10, 0.1);
		glEnd();

		glColor3f(0.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex3f(2*windowWidth/3, 3*windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 3*windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 4*windowHeight/10, 0.1);
			glVertex3f(2*windowWidth/3, 4*windowHeight/10, 0.1);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(2*windowWidth/3, 4*windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 4*windowHeight/10, 0.1);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(windowWidth/3, 5*windowHeight/10, 0.1);
			glVertex3f(2*windowWidth/3, 5*windowHeight/10, 0.1);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(1.0, 0.0, 1.0);
			glVertex3f(2*windowWidth/3, 5*windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 5*windowHeight/10, 0.1);
			glVertex3f(windowWidth/3, 6*windowHeight/10, 0.1);
			glVertex3f(2*windowWidth/3, 6*windowHeight/10, 0.1);
		glEnd();
	}

private:



};

#endif