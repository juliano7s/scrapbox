#include "Renderer.h"


Renderer::Renderer(void)
{
}


Renderer::~Renderer(void)
{
}

void Renderer::drawWorldBoxes(World *w)
{
	std::vector<Box> &boxList = w->getBoxList();
	std::vector<Box>::iterator it1;

	for (it1 = boxList.begin(); it1 != boxList.end(); it1++) {
		Box *b1 = &(*it1);

		glBegin(GL_LINE_LOOP);
			glVertex2f(b1->getX(), b1->getY());
			glVertex2f(b1->getX(), b1->getY() + b1->getSide());		
			glVertex2f(b1->getX() + b1->getSide(), b1->getY() + b1->getSide());
			glVertex2f(b1->getX() + b1->getSide(), b1->getY());
		glEnd();
	}
}

void Renderer::drawWorld(World const w) {
		glBegin(GL_LINE_LOOP);
			glVertex2f(w.getX(), w.getY());
			glVertex2f(w.getX(), w.getY() + w.getHeight());		
			glVertex2f(w.getX() + w.getWidth(), w.getY() + w.getHeight());
			glVertex2f(w.getX() + w.getWidth(), w.getY());
		glEnd();
}