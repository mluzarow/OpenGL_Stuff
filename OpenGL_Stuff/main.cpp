#include "glew.h"
#include "freeglut.h"

#include "main.h"

//Variables
bool* KeyStates = new bool[256]; //Array of booleans for current key state
// false = Not pressed
// true = Pressed
bool* SpecialKeyStates = new bool[256]; //Array of booleans for current special key state
// false = Not pressed
// true = Pressed

void Special_Key_Operations (void) {
	if (SpecialKeyStates[GLUT_KEY_LEFT]) {
		//stuff
	}
}

//Detect special key presses
void Special_Key_Pressed (int key, int x, int y) {
	SpecialKeyStates[key] = true; //Current special key is pressed
}

//Detect special key releases
void Special_Key_Released (int key, int x, int y) {
	SpecialKeyStates[key] = false; //Current special key is released
}

//Perform key operations
void Key_Operations (void) {
	if (KeyStates['b']) {
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
/*
	int f, x = 0;
	int f_n[501];
	int index = 0;
	
	for (x = 0; x < 501; x++) {
		f_n[x] = x;
	}

	glClear(GL_COLOR_BUFFER_BIT);  
    glColor3f(3.0,0.4,0.2); 
    glPointSize(1.0); 

	for (int i = 0; i < 501; i++) {
		lineDraw(f_n[i], 100);
	}
	
	glBegin(GL_LINES);
    glVertex2d(, 65);
	glVertex2d(345, 432);
    glEnd();

	glFlush();
	*/
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
	glutSpecialFunc(Special_Key_Pressed); //Tell GLUT to use Special_Key_Pressed method
	glutSpecialUpFunc(Special_Key_Released); //Tell GLUT to use Special_Key_Released method

	glutMainLoop();
}
/*
//Variables
bool* KeyStates = new bool[256]; //Array of booleans for current key state
// false = Not pressed
// true = Pressed
bool* SpecialKeyStates = new bool[256]; //Array of booleans for current special key state
// false = Not pressed
// true = Pressed
bool CubeMovement = false; //Current cube movement direction
// false = down
// true = up
float CubeVerticalLocation = 0.0f; //Location of Cube on y axis
float CubeVerticalRotation = 0.0f; //Angle of rotation about y axis


void Render_Primitive (void) {
	//glEnable(GL_COLOR_MATERIAL); //For use with lightmaps

	//glBegin(GL_TRIANGLE_STRIP); // Start drawing a triangle strip primitive
	//// The first triangle
	//glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
	//glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner
	//glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner
	//// The end of the second triangle
	//glVertex3f(1.0f, -1.0f, 0.0f); // The bottom right corner
	//glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
	//glEnd();

	//glBegin(GL_LINE_LOOP); // Start drawing a line primitive
	//glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
	//glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner
	//glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner
	//glVertex3f(1.0f, -1.0f, 0.0f); // The bottom right corner
	//glEnd();

	//glPointSize(20.0f);
	//glBegin(GL_POINTS); // Start drawing a point primitive
	//glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
	//glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner
	//glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner
	//glVertex3f(1.0f, -1.0f, 0.0f); // The bottom right corner
	//glEnd();

	glBegin(GL_QUADS); //Start drawing square
	glColor3f(0.0f, 1.0f, 0.0f); //Color vertex green
	glVertex3f(-1.0f, -1.0f, 0.0f); //The bottom left corner
	glColor3f(0.0f, 1.0f, 0.0f); //Color vertex green
	glVertex3f(-1.0f, 1.0f, 0.0f); //The top left corner
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f); //The top right corner
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f); //The bottom right corner
	glEnd();
}

//Perform special key operations
void Special_Key_Operations (void) {
	if (SpecialKeyStates[GLUT_KEY_LEFT]) {
		//stuff
	}
}

//Perform key operations
void Key_Operations (void) {
	if (KeyStates['a']) {
		//stuff
	}
}

//Detect special key releases
void Special_Key_Released (int key, int x, int y) {
	SpecialKeyStates[key] = false; //Current special key is released
}

//Detect key releases
void Key_Released (unsigned char key, int x, int y) {
	KeyStates[key] = false; //Current key is not pressed
}

//Detect special key presses
void Special_Key_Pressed (int key, int x, int y) {
	SpecialKeyStates[key] = true; //Current special key is pressed
}

//Detect key presses
void Key_Pressed (unsigned char key, int x, int y) {
	KeyStates[key] = true; //Current key is pressed
}

//Control Window Reshape
void Reshape (int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); //Set viewport size
	glMatrixMode(GL_PROJECTION); //Switch to projection matrix for scene render
	glLoadIdentity(); //Reset projection matrix to identity

	//FOV, aspect ratio, render min, reder max
	gluPerspective(60, ((GLfloat)width / (GLfloat)height), 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW); //Switch back to model view matrix
}

//Store drawing code
void Display (void) {
	Key_Operations(); //Get key processing

	//RGB ALPHA
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //Clear background of window
	glClear(GL_COLOR_BUFFER_BIT); //Clear color buffer
	glEnable(GL_BLEND); //Enable blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //blend function
	glLoadIdentity(); //Load Identity matrix to reset draw location

	glTranslatef(0.0f, 0.0f, -5.0f); //Push scene back 5 units along z
	//Render_Primitive(); //Reder the primitive
	glTranslatef(0.0f, CubeVerticalLocation, 0.0f); //translate vertically
	glRotatef(CubeVerticalRotation, 0.0f, 1.0f, 0.0f); //Rotate object around
	glColor4f(0.0f, 1.0f, 0.0f, 0.1f);
	glScalef(2.0f, 0.5f, 1.0f);
	glutSolidCube(2.0f);

	//glFlush(); //Flush OpenGL buffers to window
	glutSwapBuffers(); //Swap the drawing buffer with the display buffer and flush contents

	if (CubeMovement == true) { //Cube moving up
		CubeVerticalLocation -= 0.005f; //Move up
	} else { //Cube moving down
		CubeVerticalLocation += 0.005f; //Move down
	}
	if (CubeVerticalLocation < -3.0f) { //Gone too far up
		CubeMovement = false; //Change direction to down
	} else if (CubeVerticalLocation > 3.0f) { //GOne too far down
		CubeMovement = true; //Change direction to up
	}
	CubeVerticalRotation += 0.050f; //Increment rotation
	if (CubeVerticalRotation > 360.0f) { //Cube has rotated beyond 360
		CubeVerticalRotation -= 360.0f; //restart counting
	}


}

int main (int argc, char **argv) {
	//argc, argv required by GLUT; allow to add command line arguments

	glutInit(&argc, argv); //Initialize GLUT
	//glutInitDisplayMode(GLUT_SINGLE); //Set up basic display buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //Set up double buffering w/ alpha blending
	glutInitWindowSize(500, 500); //Set width and height of window
	glutInitWindowPosition(100,100); //Set Position of window
	glutCreateWindow("You're first OpenGL Window"); //Set the title of the widow

	glutDisplayFunc(Display); //Tell GLUT to use Display method
	glutIdleFunc(Display); //Tell GLUT to use Display as Idle method
	glutReshapeFunc(Reshape); //Tell GLUT to use Reshape method
	glutKeyboardFunc(Key_Pressed); //Tell GLUT to use Key_Pressed method
	glutKeyboardUpFunc(Key_Released); //Tell GLUT to use Key_Released method
	glutSpecialFunc(Special_Key_Pressed); //Tell GLUT to use Special_Key_Pressed method
	glutSpecialUpFunc(Special_Key_Released); //Tell GLUT to use Special_Key_Released method

	glutMainLoop(); //Throw into graphics loop
}

*/

