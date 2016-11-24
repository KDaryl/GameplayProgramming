#include "Game.h"

//Daryl keogh
//Lab 3
//Drawing different types of primitives using the Function keys (F1 -> F10)

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game(){}

void Game::run()
{

	double num = acos(-1) / 180 * 2;

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1))
		drawPoints();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2))
		drawLine();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3))
		drawLineStrip();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4))
		drawLineLoop();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F5))
		drawTriangle();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F6))
		drawTriangleStrip();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F7))
		drawTriangleFan();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F8))
		drawQuad();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F9))
		drawQuadStrip();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F10))
		drawPolygon();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::drawPoints()
{
	glPointSize(25);
	glBegin(GL_POINTS);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
}

void Game::drawLine()
{
	glLineWidth(15);
	glBegin(GL_LINES);
	{
		glVertex3f(0.2f, .0f, -1.0);
		glVertex3f(.2f, .3f, -1.0);
	}
	glEnd();
}

void Game::drawLineStrip()
{
	glLineWidth(15);
	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(0.2f, .0f, -1.0);
		glVertex3f(.2f, .3f, -1.0);
		glVertex3f(-.2f, .4f, -1.0);
	}
	glEnd();
}

void Game::drawLineLoop()
{
	glLineWidth(15);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0.2f, .0f, -1.0);
		glVertex3f(.2f, .3f, -1.0);
		glVertex3f(-.2f, .4f, -1.0);
		glVertex3f(-.2f, -.25f, -1.0);
	}
	glEnd();
}

void Game::drawTriangle()
{
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
}

void Game::drawTriangleStrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.0, .2, -5.0);
		glVertex3f(-.2, -.2, -5.0);
		glVertex3f(.2, -2.0, -5.0);

		glVertex3f(0.0, -.2, -5.0);
		glVertex3f(.2, .2, -5.0);
		glVertex3f(-.2, 2.0, -5.0);
	}
	glEnd();
}

void Game::drawTriangleFan()
{
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.0, .2, -5.0);
		glVertex3f(-.2, -.2, -5.0);
		glVertex3f(.2, -2.0, -5.0);

		glVertex3f(0.0, -.2, -5.0);
		glVertex3f(.2, .2, -5.0);
	}
	glEnd();
}

void Game::drawQuad()
{
	glBegin(GL_QUADS);
	{
		glVertex3f(.2f, .0f, -1.0);
		glVertex3f(.2f, .3f, -1.0);
		glVertex3f(0.f, .0f, -1.0);
		glVertex3f(0.f, .3f, -1.0);
	}
	glEnd();
}

void Game::drawQuadStrip()
{
	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(.2f, .0f, -1.0);
		glVertex3f(.2f, .3f, -1.0);
		glVertex3f(0.f, .0f, -1.0);
		glVertex3f(0.f, .3f, -1.0);
	}
	glEnd();
}

void Game::drawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glVertex3f(.2f, .0f, -1.0);
		glVertex3f(.2f, .3f, -1.0);
		glVertex3f(0.f, .4f, -1.0);
		glVertex3f(-.35, -.2, -1.0);
	}
	glEnd();
}