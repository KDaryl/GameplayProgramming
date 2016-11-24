#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h> 
#include <gl/GLU.h>

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
	//Drawing functions
	void drawPoints();
	void drawLine();
	void drawLineStrip();
	void drawLineLoop();
	void drawTriangle();
	void drawTriangleStrip();
	void drawTriangleFan();
	void drawQuad();
	void drawQuadStrip();
	void drawPolygon();
};