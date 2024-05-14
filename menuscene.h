#pragma once
#include "scene.h"

class Button {
public:
	int x, y;
	int width, height;//init

	int textColor;//init
	char text[105];
	
	int lineColor;

	bool isTouch;//init
	bool isClick;//init

	void set(int X, int Y,const char *Text);
	void init();
	void update();
	void draw();
};

class Menuscene :public Scene {
public:
	IMAGE background;
	char backgroundMusic[105];

	Button button[5];
	int buttonCnt;

	void init();
	void control();
	int update();
	void draw();
	void close();
};
