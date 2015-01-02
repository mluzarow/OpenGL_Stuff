#include "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/include/GL/glew.h"
#include "C:/Program Files (x86)/Microsoft Visual Studio 10.0/VC/include/GL/freeglut.h"

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

