#include "glew.h"
#include "freeglut.h"

#include "main.h"

#include <iostream>

//Variables
bool* KeyStates = new bool[256]; //Array of booleans for current key state
// false = Not pressed
// true = Pressed

//Perform key operations
void Key_Operations (void) {
	if (KeyStates['q']) {
		drawPoint(200, 200);
	} else if (KeyStates['a']) {
		drawLine(250, 250, 450, 450);
	}

	glutPostRedisplay();
}

//Detect key presses
void Key_Pressed (unsigned char key, int x, int y) {
	KeyStates[key] = true; //Current key is pressed
}

//Detect key releases
void Key_Released (unsigned char key, int x, int y) {
	KeyStates[key] = false; //Current key is not pressed
}

//Draws a line of pixels from (250, 250) to (500, 500)
void drawLine(int x1, int y1, int x2, int y2) {
	
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

//Draws a pixel at (250, 250)
void drawPoint(int x, int y) {

	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

//Store drawing code
void Display (void) {
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(3.0,0.4,0.2); 
	glPointSize(1.0); 

	Key_Operations(); //Get key processing

	glFlush();
}

void init(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Clear background of window
 
	glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Scribbles");

	init(); //Initialize window
	glutDisplayFunc(Display); //Tell GLUT to use Display method

	glutKeyboardFunc(Key_Pressed); //Tell GLUT to use Key_Pressed method
	glutKeyboardUpFunc(Key_Released); //Tell GLUT to use Key_Released method

	std::cout << "Point: q\nLine: a\n";

	glutMainLoop();
}