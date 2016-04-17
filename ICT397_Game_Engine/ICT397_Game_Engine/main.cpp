
//Library Headers
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h> //Standard library - c library
#include <time.h>
//#include <InputManager.h>

#include <iostream>
#include <cstdio>
using namespace std;
#include <lua.hpp>

#include <stdlib.h>
#include <math.h>

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

	if(g_gameState == 0){//ie. game state
		/*if(g_lastGameState !=0){//debug stuff
			cout << "g_gameState == 0" <<endl;
			g_lastGameState=0;
		}*/

		if (!viewSet){
			g_controller.ModelTest();
			viewSet = true;
		}
	

		if (deltaMove){
			computePos(deltaMove);
		}

		checkUp(deltaUp);

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

int multiply(int a, int b)
{
  return a*b;
}

int add(int a, int b)
{
  return a+b;
}

int cpp_Multiply(lua_State* luaVM)
{ 
	//determine number of params on the stack
    int numParams=lua_gettop(luaVM);
    if(numParams!=2) {
	   cout<<"not enough params"<<endl;
	   return 0;
    }
    if(!lua_isnumber(luaVM,1)||!lua_isnumber(luaVM,2)){
	  cout<<"bad params"<<endl;
	  return 0;
	}

    //pull params off stack
   int num1=(int)lua_tonumber(luaVM,1);
   int num2=(int)lua_tonumber(luaVM,2);
   //call the real function
   int result=multiply(num1,num2);
   //push result onto the stack
   lua_pushnumber(luaVM,result);
   return 1;  //return the number of values returned
}

int cpp_Add(lua_State* luaVM)
{ 
	//determine number of params on the stack
    int numParams=lua_gettop(luaVM);
    if(numParams!=2) {
	   cout<<"not enough params"<<endl;
	   return 0;
    }
    if(!lua_isnumber(luaVM,1)||!lua_isnumber(luaVM,2)){
	  cout<<"bad params"<<endl;
	  return 0;
	}

    //pull params off stack
   int num1=(int)lua_tonumber(luaVM,1);
   int num2=(int)lua_tonumber(luaVM,2);
   //call the real function
   int added=add(num1,num2);
   //push result onto the stack
   lua_pushnumber(luaVM,added);
   return 1;  //return the number of values returned
}

int main(int argc, char* argv[]) {

	//create lua state
    lua_State* L = lua_open();
    if (L==NULL){
       cout<<"Error Initializing lua"<<endl;;
       return -1;
    }
	lua_register(L,"cpp_Add",cpp_Add);
	// reister the wrapper function
    lua_register(L,"cpp_Multiply",cpp_Multiply);

    // load standard lua library functions
    luaL_openlibs(L);

	// load and run Lua script
    if (luaL_dofile(L, "script4.lua" )){
		cout<<"error opening file\n";
	
	    getchar(); return 1;
	}

    lua_close(L);
    //getchar();
	//return 0;

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
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}