// GL
#include <iostream>
#if   defined(OSX)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <GLUT/glut.h>
#elif defined(LINUX)
#include <GL/glut.h>
#endif

int g_window{0};
void init2D(float r, float g, float b)
{
	glClearColor(0.f,0.f,0.f,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);

	//draw two points
	glBegin(GL_POINTS);
	for(int i = 0; i < 10; i++)
	{
		glVertex2i(10+5*i,110);
	}
	glEnd();

	//draw a line
	glBegin(GL_LINES);
		glVertex2i(10,10);
		glVertex2i(100,100);

	glEnd();

	
	
	glBegin(GL_TRIANGLES);
	std::cout << "Trying the Triangle" << std::endl;

		glVertex2i(10,10);
		glVertex2i(50,10);
		glVertex2i(30,50);

	glEnd();

	

	glFlush();
}


void
keyPressed(GLubyte _key, GLint _x, GLint _y) {
  switch(_key) {
    // Escape key : quit application
    case 27:
      std::cout << "Destroying window: " << g_window << std::endl;
      glutDestroyWindow(g_window);
      g_window = 0;
      break;
    // Unhandled
    default:
      std::cout << "Unhandled key: " << (int)(_key) << std::endl;
      break;
  }
}


int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	g_window = glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();

	return 0;
}