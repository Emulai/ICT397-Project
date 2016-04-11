
//Library Headers
#include <math.h>
#include <GL/glut.h> //
#include <stdlib.h> //Standard library - c library
#include <time.h>

//Class Headers
#include "Controller\Controller.h"

#pragma comment(lib, "lua5.1.lib")
#pragma comment(lib, "luabindd.lib")

//Objects
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
float x=0.0f, z=5.0f;
float u = 9.0;
// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
float deltaUp = 0;
int xOrigin = -1;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void checkUp(float deltaUp) {

	u = u+deltaUp;
	if(u <= 7.5)
        u=7.5;
    if (u >=10.5)
        u=10.5;
}

bool viewSet = false;

void renderScene(void) {

	if (!viewSet)
	{
		g_controller.ModelTest();
		viewSet = true;
	}
	

	if (deltaMove)
		computePos(deltaMove);

		checkUp(deltaUp);

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	gluLookAt(	x, 9.0f, z,
			x + lx, u,  z + lz,
			0.0f, 1.0f,  0.0f);

// Draw ground

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
} 

void processNormalKeys(unsigned char key, int xx, int yy)
{
	//float tz, tx = 0;

	switch (key) {
	  case 'w':deltaMove = 3.6f;
         break;
      case 'a':x-=4.01f;
         break;
      case 's':deltaMove = -3.6f;
         break;
      case 'd':x+=4.01f;
         break;
      case 'k':deltaUp = -0.01f;
         break;
      case 'l':deltaUp = 0.01f;
         break;
      case 27:exit(0);
         break;
      default:
         break;
   }
}

void releaseKey(unsigned char key, int xx, int yy) {

	switch (key) {
      case 119:deltaMove = 0.0f;
         break;
      case 115:deltaMove = 0.0f;
         break;;
      case 107:deltaUp = 0.0f;
         break;
      case 108:deltaUp = 0.0f;
         break;
   }
}

void mouseMove(int x, int y) { 	

         // this will only be true when the left button is down
    if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;
		
		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
		
	}


		
}

void mouseButton(int button, int state, int x, int y) {

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
}




int main(int argc, char* argv[]) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1280,960);
	glutCreateWindow("ICT397_Game_Engine");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);
	//glutSpecialFunc(processSpecialKeys);
	//glutIgnoreKeyRepeat(1);

	glutKeyboardUpFunc(releaseKey);

	// here are the two new functions
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
