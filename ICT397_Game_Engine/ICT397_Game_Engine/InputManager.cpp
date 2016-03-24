/// REGIST.H - Regist class definition
///----------------------------------------------------------------------------

#include <iostream>
#include "InputManager.h"


using namespace std;

///----------------------------------------------------------------------------
/// Using indentation so that comments don't clutter code

	/**
	* @class InputManager
	*
	* @author Adrian Hampel
	* @version 01
	* @date 24/03/2016, Started
	*
	* @todo Keep adding to the development.
	*/

///----------------------------------------------------------------------------



class InputManager
{

	InputManager::InputManager()
	{



	}

	void InputManager::renderScene(void)
	{


	}

	void InputManager::computePos(float deltaMove) 
	{



	}	
	
	void InputManager::mouseMove(int x, int y)
	{
		
		
		if (x < 0)
			cam.DirectionRotateLR(0);
		else if (x > width)
			cam.DirectionRotateLR(0);
		else if (x > width/2.0)
		{
			cam.DirectionRotateLR(1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else if (x < width/2.0)
		{
			cam.DirectionRotateLR(-1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else
			cam.DirectionRotateLR(0);
		if (y < 0 || y > height)
			cam.DirectionLookUD(0);

		else if (y > height/2.0) {
			cam.DirectionLookUD(-1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else if (y < height/2.0) {
			cam.DirectionLookUD(1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else
			cam.DirectionLookUD(0);
	}

	void InputManager::mouseButton(int button, int state, int x, int y)
	{
		int isDragging = 0;
		int xDragStart = 0;
		
		if (button == GLUT_LEFT_BUTTON) {
			if (state == GLUT_DOWN) { // left mouse button pressed
				isDragging = 1; // start dragging
				xDragStart = x; // save x where button first pressed
			}
			else  { /* (state = GLUT_UP) */
				angle += deltaAngle; // update camera turning angle
				isDragging = 0; // no longer dragging
			}
		}

	}

	void InputManager::Keys(unsigned char key, int x, int y)
{
    int i = 0;
    switch (key)
    {
        // step left
        case 'A':
        case 'a':
            if(!gLevelWorld)
            {
                cam.DirectionLR(-1);
            }
            if(gLevelWorld)
            {
                lev->DirectionLR(-1);
            }
            break;
        // step right
        case 'D':
        case 'd':
            if(!gLevelWorld)
            {
                cam.DirectionLR(1);
            }
            if(gLevelWorld)
            {
                lev->DirectionLR(1);
            }
        break;
        // step forward
        case 'W':
        case 'w':
            if(!gLevelWorld)
            {
                cam.DirectionFB(1);
            }
            if(gLevelWorld)
            {
                lev->DirectionFB(1);
            }
            break;
        // step backward
        case 'S':
        case 's':
            if(!gLevelWorld)
            {
                cam.DirectionFB(-1);
            }
            if(gLevelWorld)
            {
                lev->DirectionFB(-1);
            }
            break;
        // move up
        case 'T':
        case 't':
            if(!gLevelWorld)
            {
                cam.DirectionUD(1);
            }
            if(gLevelWorld)
            {
                lev->DirectionUD(1);
            }
            break;
        // move down
        case 'G':
        case 'g':
            if(!gLevelWorld)
            {
                cam.DirectionUD(-1);
            }
            if(gLevelWorld)
            {
                lev->DirectionUD(-1);
            }
            break;
        //if on ground and jump OK
        case 'e':
        case 'E':
            if ((gOn) && (jOk))
            {
                jOk = FALSE;
                jump = TRUE;
                cam.SetUD((cam.GetUD() + 100));
                jumpSpeed = jumpSpeed * 3;
                cam.DirectionUD(1);
                jumpSpeed = jumpSpeed / 3;
            }
            break;
        // teleport to gameworld
        case 'f':
        case 'F':
            cam.Position(500, 450, 20000, 90);
            sWorld = FALSE;
            gTutorialWorld = TRUE;
            gOn = TRUE;
            cam.EmptyBoundingBoxes();
            cam.EmptyPlains();
            //movementSpeed = 5;
            break;
        // sprint
        case 'Q':
        case 'q':
            movementSpeed = stepIncrement * 2;
            break;
        // display campus map
        case 'm':
        case 'M':
        {
            if (DisplayMap)
            {
                DisplayMap = false;
            }
            else
            {
                DisplayMap = true;
            }
        }
        break;
        // exit tour (escape key)
        case 'x':
		case 'X':
            {
                cam.SetRotateSpeed (0.0f);
                cam.SetMoveSpeed (0.0f);
                DisplayExit = true;
            }
        break;
        // display welcome page (space key)
        case ' ':
            {
                if (DisplayWelcome)//////////////////////////////////////////Going to be shoot case
                {
                    cam.SetRotateSpeed (rotationSpeed);
                    cam.SetMoveSpeed (movementSpeed);
                    DisplayWelcome = false;
                }
                else
                {
                    cam.SetRotateSpeed (0.0f);
                    cam.SetMoveSpeed (0.0f);
                    DisplayWelcome = true;
                }
            }
        break;
        // display light fittings
        case 'l':
        case 'L':
        {
            if (lightsOn)
            {
                lightsOn = false;
            }
            else
            {
                lightsOn = true;
            }
        }
        break;

        case 'P':
        case 'p':
        {
            // Display ECL Block
            if (displayECL)
            {
                displayECL = false;
            }
            else
            {
                displayECL = true;
            }
        }
        break;

        case 'u':
        case 'U':
            if(!sWorld)
            {
                if (cDT){
                    cDT = FALSE;
                    gOn = FALSE;
                    cam.DirectionUD(0);
                    cam.SetCollisionDetectionOn(cDT);
                }else{
                    cDT = TRUE;
                    gOn = TRUE;
                    cam.DirectionUD(0);
                    cam.SetCollisionDetectionOn(cDT);
                }
            }else if(sWorld)
            {
                if (cDT){
                    cDT = FALSE;
                    cam.SetCollisionDetectionOn(cDT);
                }else{
                    cDT = TRUE;
                    cam.SetCollisionDetectionOn(cDT);
                }
            }
        break;
    }
}

	void ProcessSpecialKeys(int key, int x, int y)
	{
		switch (key)
		{
			case GLUT_KEY_LEFT :
				if(!gLevelWorld)
				{
					cam.DirectionRotateLR(-1);
				}
				if(gLevelWorld)
				{
					lev->DirectionRotateLR(-1);
				}
				break;

			case GLUT_KEY_RIGHT :
				if(!gLevelWorld)
				{
					cam.DirectionRotateLR(1);
				}
				if(gLevelWorld)
				{
					lev->DirectionRotateLR(1);
				}
				break;

			case GLUT_KEY_UP :
				if(!gLevelWorld)
				{
					cam.DirectionLookUD(1);
				}
				if(gLevelWorld)
				{
					lev->DirectionLookUD(1);
				}
				break;

			case GLUT_KEY_DOWN :
				if(!gLevelWorld)
				{
					cam.DirectionLookUD(-1);
				}
				if(gLevelWorld)
				{
					lev->DirectionLookUD(-1);
				}
				break;
		}
	}

	void InputManager::processNormalKeys(unsigned char key, int x, int y)
	{


	}

}