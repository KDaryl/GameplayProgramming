#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
//Daryl keogh
//Lab 4
//Student ID: C00207452
//Description: A program which is to explain the use of glLoadIdentity(), glTranslatef(), glRotatef() & glScalef().
//Time Spent: 25 minutes
using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};