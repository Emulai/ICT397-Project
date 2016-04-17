#include <math.h>
#include <GL/glut.h>
#include <time.h>
//#include <InputManager.h>

#pragma comment(lib, "lua5.1.lib")
#pragma comment(lib, "luabindd.lib")

#include <stdlib.h>
#include <math.h>

using namespace std;

#include "Controller\Controller.h"

Controller g_controller;

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// angle of rotation for the camera direction
float angle = 0.0f;

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f, z=0.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

//Temporarily here for testing, see if can be moved into view later? -Daniel
//int t_windowHeight =900;
//int t_windowWidth =1280;

//the state of the game
//0 is the game, 1 is the menu
short g_gameState = 0;
//short g_lastGameState = 0;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0){
		h = 1;
	}

	g_controller.MenuInit(w, h);

	double ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	if(g_gameState ==0){
		// Set the correct perspective.
		gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	}else{// ie g_gameState ==1
		gluOrtho2D(0.0f, g_controller.GetWindowWidth(), 0.0f, g_controller.GetWindowHeight());
		g_controller.MenuInit(g_controller.GetWindowWidth(), g_controller.GetWindowHeight());
	}

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove) {
	if(g_gameState==0){
		x += deltaMove * lx * 0.1f;
		z += deltaMove * lz * 0.1f;
	}
}

bool viewSet = false;

void renderScene(void) {

	if(g_gameState == 0){//ie. game state
		/*if(g_lastGameState !=0){//debug stuff
			cout << "g_gameState == 0" <<endl;
			g_lastGameState=0;
		}*/

		if (!viewSet)
		{
			g_controller.ModelTest();
			viewSet = true;
		}
	

		if (deltaMove)
			computePos(deltaMove);

		// Clear Color and Depth Buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Reset transformations
		glLoadIdentity();
		// Set the camera
		gluLookAt(	x,		1.0f,	z,
					x+lx,	1.0f,	z+lz,
					0.0f,	1.0f,	0.0f);

	// Draw testing ground
		glColor3f(0.0f, 0.9f, 0.9f);
		glBegin(GL_POLYGON);
			glVertex3f(-100.0f, 0.0f,  100.0f);
			glVertex3f( 0.0f,   0.0f,  100.0f);
			glVertex3f( 0.0f,   0.0f,  0.0f);
			glVertex3f(-100.0f, 0.0f,  0.0f);
		glEnd();

		glColor3f(0.9f, 0.0f, 0.9f);
		glBegin(GL_POLYGON);
			glVertex3f( 0.0f,   0.0f,  100.0f);
			glVertex3f( 100.0f, 0.0f,  100.0f);
			glVertex3f( 100.0f, 0.0f,  0.0f);
			glVertex3f( 0.0f,   0.0f,  0.0f);
		glEnd();

		glColor3f(0.9f, 0.9f, 0.0f);
		glBegin(GL_POLYGON);
			glVertex3f( 0.0f,   0.0f,  0.0f);
			glVertex3f( 100.0f, 0.0f,  0.0f);
			glVertex3f( 100.0f, 0.0f,  -100.0f);
			glVertex3f( 0.0f,   0.0f,  -100.0f);
		glEnd();

		glColor3f(0.9f, 0.9f, 0.9f);
		glBegin(GL_POLYGON);
			glVertex3f(-100.0f, 0.0f,  0.0f);
			glVertex3f( 0.0f,   0.0f,  0.0f);
			glVertex3f( 0.0f,   0.0f,  -100.0f);
			glVertex3f(-100.0f, 0.0f,  -100.0f);
		glEnd();

		glutSwapBuffers();
	}else{//state==1 ie menu
		/*if(g_lastGameState !=1){//debug stuff
			cout << "g_gameState == 1" << endl;
			g_lastGameState=1;
		}*/
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//
		g_controller.MenuCtrl();
		glutSwapBuffers();
	}
} 

void processNormalKeys(unsigned char key, int xx, int yy) { 	

	if (key == 27){
		if(g_gameState == 0){
			g_controller.EnterMenuState();
			g_gameState = 1;
		}else{
			g_controller.EnterGameState();
			g_gameState = 0;
		}
	}
} 

void pressKey(int key, int xx, int yy) {
	if(g_gameState==0){
		switch (key) {
			case GLUT_KEY_UP : deltaMove = 0.5f; break;
			case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
		}
	}
} 

void releaseKey(int key, int x, int y) { 	
	
        switch (key) {
             case GLUT_KEY_UP :
             case GLUT_KEY_DOWN : deltaMove = 0;break;
        }
} 

void mouseMove(int x, int y) { 	
	if(g_gameState==0){
		// this will only be true when the left button is down
		if (xOrigin >= 0) {

			// update deltaAngle
			deltaAngle = (x - xOrigin) * 0.001f;

			// update camera's direction
			lx = sin(angle + deltaAngle);
			lz = -cos(angle + deltaAngle);
		}
	}
}

void mouseButton(int button, int state, int x, int y) {

	if(g_gameState==0){
		// only start motion if the left button is pressed
		if (button == GLUT_LEFT_BUTTON) {

			// when the button is released
			if (state == GLUT_UP) {
				angle += deltaAngle;
				xOrigin = -1;
			}
			else  {// state = GLUT_DOWN
				xOrigin = x;
			}
		}
	}else{//ie menuState
		if (button == GLUT_LEFT_BUTTON) {
			g_controller.MenuPress(x,y);
		}
	}
}

int main(int argc, char* argv[]) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("ICT397_Game_Engine");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	// here are the two new functions
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}

/*int main(int argc, char **argv) {
	
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	// here are the two new functions
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}*/