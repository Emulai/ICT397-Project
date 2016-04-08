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
	bool hasHit;
	void MenuView(int windowHeight, int windowWidth){
		if(!hasHit){
			std::cout << "hit MenuView" << std::endl;
			hasHit=true;
		}
		//Set GL state
		glPushMatrix();
		gluLookAt(	0.0, 1.0f, 0.0,
					0.0, 1.0f,  -1.0,
					0.0f, 1.0f,  0.0f);

		glColor3f(0.5f,0.5f,0.5f);
		glBegin(GL_QUADS);
			glVertex3i(0, 0, 0.0);
			glVertex3i(0, windowHeight, 0.0);
			glVertex3i(windowWidth, windowHeight, 0.0);
			glVertex3i(windowWidth, 0, 0.0);
		glEnd();

		
		glPopMatrix();
	}

private:



};

#endif