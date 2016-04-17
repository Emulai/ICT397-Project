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

void View::GameView(float t_x, float t_z, float t_lx, float t_lz){
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	t_x,		1.0f,	t_z,
				t_x+t_lx,	1.0f,	t_z+t_lz,
				0.0f,		1.0f,	0.0f);

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
}

//////////////////////////
//Function to DISPLAY menus here
//Menu INTERACTION in Controller
//////////////////////////

void View::SetLocalWindowSize(float t_newWindowWidth, float t_newWindowHeight){
	m_windowWidth = t_newWindowWidth;
	m_windowHeight = t_newWindowHeight;
}

void View::EnterMenuState(){
	std::cout << "Switching to menu state" << std::endl;
	std::cout << "Early prototype, some functionality missing" << std::endl
		<< "From top to bottom, functionality is \n\tResume\n\tOptions(unimplemented)" << std::endl
		<< "\tCredits(unimplemented)\n\tListCheckpoints[includes save/load](unimplemented)" << std::endl
		<< "\tExit" << std::endl;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, GetWindowWidth(), 0.0f, GetWindowHeight());// 0.0f, 0.0f, 1.0f
	//glDisable(GLUT_DEPTH);

	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void View::EnterGameState(){
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	double l_ratio =  GetWindowWidth() * 1.0 / GetWindowHeight();

	gluPerspective(45.0f, l_ratio, 0.1f, 100.0f);
	std::cout << "Switching to game state" <<std::endl;
	glEnable(GLUT_DEPTH);

	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void View::MenuView(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	glutSwapBuffers();
}

/****************************************
	* returns a short indicating what button was pressed.
	* Numbers start with 1 at the bottom button to 5 at the top button
	* -1 is a sentinel for no interaction
	* takes arguments originating from OpenGL API indicating location of a mouse click on screen
	*
	* Currently: 1= EXIT, 5=Return (to game state)
****************************************/
short View::CheckForButton(int t_x, int t_y){
		
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

float View::GetWindowWidth(){
	return(m_windowWidth);
}
float View::GetWindowHeight(){
	return(m_windowHeight);
}

