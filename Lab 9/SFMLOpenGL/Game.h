#ifndef GAME_H
#define GAME_H

#include <Debug.h>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Vector3.h>
#include <Matrix3.h>

using namespace std;
using namespace sf;
using namespace gpp;

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
	void render();
	void unload();
	void readVertexShader();
	void readFragShader();

	Clock clock;
	Time elapsed;

	bool setFrSrc;
	bool setVsSrc;
	char* vs_src;
	char* fs_src;
	float numOfChars = 0;
	float rotationAngle = 0.0f;
};

#endif