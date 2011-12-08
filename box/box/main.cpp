
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <gl\GL.h>
#include <gl\glut.h>

#include <iostream>

#include "Box.h"
#include "World.h"
#include "PhysicSystem.h"
#include "Renderer.h"

World w(1,1);
PhysicSystem physys(w);
const float viewportLeft = 0.0f;
const float viewportRight = 9.0f;
const float viewportBottom = 0.0f;
const float viewportTop = 9.0f;
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

void drawFrame() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glFrustum(-0.5, 0.5, -0.5, 0.5, 0.5, 5.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); /* clear the matrix */
	glOrtho(viewportLeft, viewportRight, viewportBottom, viewportTop, 0.0f, 1.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	physys.calcBoxPositions();

	glColor4f(0.0f, 0.0f, 0.0f,0.0f);
	Renderer::drawWorld(w);
	Renderer::drawWorldBoxes(&w);

	glutSwapBuffers();

}

void handleMouse(int button, int state, int x, int y) {
	float vpX, vpY;

	vpX = ((float) x/WINDOW_WIDTH) * viewportRight;
	
	y = WINDOW_HEIGHT - y;
	vpY = ((float) y/WINDOW_HEIGHT) * viewportTop;

	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP) { //released button
			physys.dropDraggedBox();
		} else { // GLUT_DOWN
			Box *draggedBox = physys.checkBoxOnPosition(vpX, vpY); 
			if (draggedBox != NULL) {
				physys.dragBox(draggedBox);
			}
		}
	}
	
}

void handleMouseMotion(int x, int y) {
	float vpX, vpY;

	vpX = ((float) x/WINDOW_WIDTH) * viewportRight;
	
	y = WINDOW_HEIGHT - y;
	vpY = ((float) y/WINDOW_HEIGHT) * viewportTop;

	Box *draggedBox = physys.getDraggedBox();
	if (draggedBox != NULL) {
		draggedBox->setXY(vpX, vpY);
	}
}

void init() {
	glClearColor(1.1f, 1.1f, 1.8f, 0.0f);

	Box a(3.5f,3.0f,1.0f);
	Box b(5.5f,5.5f,0.5f);
	Box c(2.0f,2.0f,1.0f);
	Box d(2.0f,4.5f,0.5f);

	w.addBox(a);
	w.addBox(b);
	w.addBox(c);
	w.addBox(d);
	
}

int main(int argc, char** argv) {
	
	int winID;

	/* Initialize glut with the windows system */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(600,100);
	winID = glutCreateWindow("Box!");
	
	std::cout << winID;

	glutDisplayFunc(&drawFrame);
	glutIdleFunc(&drawFrame);
	glutMouseFunc(&handleMouse);
	glutPassiveMotionFunc(&handleMouseMotion);
	glutMotionFunc(&handleMouseMotion);

	init();
	
	glutMainLoop();

	return 1;
}
