#pragma once
#include <cstring>
#include <easyx.h>
#include <conio.h>
#include "musiccontrol.h"
#include "image.h"
#include "text.h"

enum GameState {
	GameStart,
	GameExit,
	Running
};

class Scene{
public:
	virtual void init() = 0;
	virtual void control() = 0;
	virtual int update() = 0;
	virtual void draw() = 0;
	virtual void close() = 0;
};