#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include "QuadTree.h"
#define KEY_ESC 27

using namespace std;

//Crear quad tree



Quadtree *cuad = new Quadtree(Punto(-512,512),Punto(512,-512),5);








//dibuja un simple gizmo
void displayGizmo()
{
	glBegin(GL_LINES);
	glColor3d(255, 0, 0);
	glVertex2d(-512, 0);
	glVertex2d(512, 0);
	glColor3d(0, 255, 0);
	glVertex2d(0, -512);
	glVertex2d(0, 512);
	glEnd();
}
bool r = false;

void OnMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//convertir x,y
		//insertar un nuevo punto en el quadtree
		std::cout << x - 300 << " " << 300 - y << std::endl;
		//cuad->insertar(Punto(x, y));

		//cuad->insertar();


	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		r = true;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		r = false;
	}
}






void OnMouseMotion(int x, int y)
{
	if (r)
		std::cout << x - 300 << " " << 300 - y << std::endl;
	//opcional
	//hacer algo x,z cuando se mueve el mouse
}



void idle() { // AGREGAR ESTA FUNCION
	glutPostRedisplay();
}

//funcion llamada a cada imagen
void glPaint(void) {

	//El fondo de la escena al color initial
	glClear(GL_COLOR_BUFFER_BIT); //CAMBIO
	glLoadIdentity();
	glOrtho(-300.0f, 300.0f, -300.0f, 300.0f, -1.0f, 1.0f);

	//dibujar quadTree (qt->draw())

	/*glBegin(GL_POINTS);
	for()
		glVertex2f(v.at(i)[0],v.at(i)[1])
	glEnd();*/
	//dibuja el gizmo
	displayGizmo();

	//doble buffer, mantener esta instruccion al fin de la funcion
	glutSwapBuffers();
}

//
//inicializacion de OpenGL
//
void init_GL(void) {
	//Color del fondo de la escena
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro

	//modo projeccion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

//en el caso que la ventana cambie de tamaño
GLvoid window_redraw(GLsizei width, GLsizei height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


}




GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {
	case KEY_ESC:
		exit(0);
		break;

	default:
		break;
	}

}
//
//el programa principal
//




int main(int argc, char** argv) {

	//Inicializacion de la GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600); //tamaño de la ventana
	glutInitWindowPosition(100, 100); //posicion de la ventana
	glutCreateWindow("QuadTree"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL

	glutDisplayFunc(glPaint);
	glutReshapeFunc(&window_redraw);
	// Callback del teclado
	glutKeyboardFunc(&window_key);
	glutMouseFunc(&OnMouseClick);
	glutMotionFunc(&OnMouseMotion);
	glutIdleFunc(&idle);


	//qt = new quadTree();
	glutMainLoop(); //bucle de rendering
	//no escribir nada abajo de mainloop
	return 0;
}



