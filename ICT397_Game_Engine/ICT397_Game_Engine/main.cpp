//Library Headers
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h> //Standard library - c library
#include <time.h>
#include "Model\Lua\lua.hpp"

#include <stdlib.h>

//Library Headers
#include <math.h>
#include <GL/freeglut.h> //
#include <stdlib.h> //Standard library - c library
#include <time.h>

#include <iostream>
#include <cstdio>
using namespace std;



//Class Headers
#include "Controller\Controller.h"



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
float x=0.0f, z=0.0f;
float u = 9.0;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
float deltaUp = 0;
int xOrigin = -1;

//the state of the game
//0 is the game, 1 is the menu
short g_gameState = 0;
//short g_lastGameState = 0;

void changeSize(int t_w, int t_h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (t_h == 0){
		t_h = 1;
	}

	g_controller.MenuInit(t_w, t_h);

	double ratio = t_w * 1.0 / t_h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, t_w, t_h);

	if(g_gameState ==0){
		// Set the correct perspective.
		gluPerspective(45.0f, ratio, 0.1f, 1000.0f);
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

void renderScene(void) {

	if(g_gameState == 0){//ie. game state
		/*if(g_lastGameState !=0){//debug stuff
			cout << "g_gameState == 0" <<endl;
			g_lastGameState=0;
		}*/

		
	

		if (deltaMove){
			computePos(deltaMove);
		}

		checkUp(deltaUp);

		/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();*/
		
		g_controller.ModelLoad("Meshes\\bone.off", 0);

		glPushMatrix();
		glMatrixMode(GL_MODELVIEW);
		glScalef(50.0f, 50.0f, 50.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(-30.0f, 40.0f, 0.0f);
		g_controller.GetView()->Render();
		glPopMatrix();
		//glMatrixMode(GL_PROJECTION);

		g_controller.GameCtrl(x, z, lx, lz);
	}else{//state==1 ie menu
		/*if(g_lastGameState !=1){//debug stuff
			cout << "g_gameState == 1" << endl;
			g_lastGameState=1;
		}*/
		g_controller.MenuCtrl();
	}
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
      case 27: 
	if(g_gameState == 0){
		g_controller.EnterMenuState();
		g_gameState = 1;
	}else{
		g_controller.EnterGameState();
		g_gameState = 0;
	}
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
			if(state == GLUT_DOWN){//only call MenuPress when pressed down, not on release
				g_controller.MenuPress(x,y);
			}
		}
	}
}

void setArray(string t_descript, int t_index, int t_pVecX, int t_pVecY, int t_pVecZ, int t_pRotX, int t_pRotY, int t_pRotZ, string t_pmodelRef, string t_paiPath, int t_phealth, bool l_phostile, bool l_pstatic)
{
	//cout << t_descript << t_index << t_pVecX << t_pVecY << t_pVecZ << t_pRotX << t_pRotY << t_pRotZ << t_pmodelRef << t_paiPath << t_phealth << l_phostile << l_pstatic << endl;
	g_controller.GetModel()->SetGOSize(16);
	g_controller.GetModel()->CreateGameObject(t_descript, t_index, t_pVecX, t_pVecY, t_pVecZ, t_pRotX, t_pRotY, t_pRotZ, t_pmodelRef, t_paiPath, t_phealth, l_phostile, l_pstatic);

}

int cpp_Add(lua_State* luaVM)
{ 
	//determine number of params on the stack
    int numParams=lua_gettop(luaVM);
    if(numParams!=13) {
	   cout<<"not enough params"<<endl;
	   return 0;
    }                                                 
    if(!lua_isstring(luaVM,1)||!lua_isnumber(luaVM,2)||!lua_isnumber(luaVM,3)||!lua_isnumber(luaVM,4)||!lua_isnumber(luaVM,5)||!lua_isnumber(luaVM,6)||!lua_isnumber(luaVM,7)||!lua_isnumber(luaVM,8)||!lua_isstring(luaVM,9)||!lua_isstring(luaVM,10)||!lua_isnumber(luaVM,11)||!lua_isboolean(luaVM,12)||!lua_isboolean(luaVM,13)){
	  cout<<"bad params"<<endl;
	  return 0;
	}

    //pull params off stack
	const char* t_descript=(const char*)lua_tostring(luaVM,1);
	int t_index=(int)lua_tonumber(luaVM,2);
	int t_pVecX=(int)lua_tonumber(luaVM,3);
	int t_pVecY=(int)lua_tonumber(luaVM,4);
    int t_pVecZ=(int)lua_tonumber(luaVM,5);
	int t_pRotX=(int)lua_tonumber(luaVM,6);
	int t_pRotY=(int)lua_tonumber(luaVM,7);
    int t_pRotZ=(int)lua_tonumber(luaVM,8);
	const char* t_pmodelRef=(const char*)lua_tostring(luaVM,9);
	const char* t_paiPath=(const char*)lua_tostring(luaVM,10);
	int t_phealth=(int)lua_tonumber(luaVM,11);
	bool l_phostile=(bool)lua_toboolean(luaVM,12);
	bool l_pstatic=(bool)lua_toboolean(luaVM,13);

   //call the real function
   setArray(t_descript, t_index, t_pVecX, t_pVecY, t_pVecZ, t_pRotX, t_pRotY, t_pRotZ, t_pmodelRef, t_paiPath, t_phealth, l_phostile, l_pstatic);
   //push result onto the stack
   //lua_pushnumber(luaVM,result);
   return 1;  //return the number of values returned
}


int main(int argc, char* argv[]) {
	
	//create lua state
    lua_State* L = lua_open();
    if (L==NULL){
       cout<<"Error Initializing lua"<<endl;;
       return -1;
    }

		lua_register(L, "cpp_Add", cpp_Add);
		lua_register(L, "cpp_Add1", cpp_Add);
		lua_register(L, "cpp_Add2", cpp_Add);
		lua_register(L, "cpp_Add3", cpp_Add);
		lua_register(L, "cpp_Add4", cpp_Add);
		lua_register(L, "cpp_Add5", cpp_Add);
		lua_register(L, "cpp_Add6", cpp_Add);
		lua_register(L, "cpp_Add7", cpp_Add);
		lua_register(L, "cpp_Add8", cpp_Add);
		lua_register(L, "cpp_Add9", cpp_Add);
		lua_register(L, "cpp_Add10", cpp_Add);
		lua_register(L, "cpp_Add11", cpp_Add);
		lua_register(L, "cpp_Add12", cpp_Add);
		lua_register(L, "cpp_Add13", cpp_Add);
		lua_register(L, "cpp_Add14", cpp_Add);
		lua_register(L, "cpp_Add15", cpp_Add);
		
	// reister the wrapper function

    // load standard lua library functions
    luaL_openlibs(L);

	// load and run Lua script
    if (!luaL_dofile(L, "script4.lua" )){
		cout<<"error opening file\n";
	
	    //getchar(); return 1;
	}

    lua_close(L);
    //getchar();
	//return 0;

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(5,5);
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
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}