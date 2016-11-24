#include "Game.h"

//Daryl keogh
//Lab 3
//Student ID: C00207452
//Description: Drawing different types of primitives by holding down the Function keys (F1 -> F10)
//Time Spent: 2 hours

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
	
}

void Game::draw()
{
	system("CLS");

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1))
	{
		std::cout << "Drawing Points";
		drawPoints();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2))
	{
		std::cout << "Drawing Line";
		drawLine();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3))
	{
		std::cout << "Drawing Line Strip";
		drawLineStrip();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4))
	{	
		std::cout << "Drawing Line Loop";
		drawLineLoop();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F5))
	{
		std::cout << "Drawing Triangle";
		drawTriangle();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F6))
	{
		std::cout << "Drawing Triangle Strip";
		drawTriangleStrip();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F7))
	{
		std::cout << "Drawing Triangle Fan";
		drawTriangleFan();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F8))
	{
		std::cout << "Drawing Quad";
		drawQuad();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F9))
	{
		std::cout << "Drawing Quad Strip";
		drawQuadStrip();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F10))
	{
		std::cout << "Drawing Polygon";
		drawPolygon();
	}

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

//Draws a line between one vertex to another
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

//Connects each vertex together
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

//Draws a "loop" by connecting th elast vertex drawing to the first one
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

//Draws a triangle using 3 vertices
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

//Connects triangles together after every 3rd vertex
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

//Draws a triangle in which every 2
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

//Draws a four sided shape using 4 vertices
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

//Draws a polygon which is a shape made up with as many vertices as you wish
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