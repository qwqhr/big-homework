#include <easyx.h>
#include <cstdio>
#include "image.h"
#include "musiccontrol.h"

#pragma once

enum direction {
	up,
	down,
	left,
	right,
	none
};

enum state {
	destroy,
	survival
};

class Character{
public:
	int x,y,v;
	int width,height;
	int hp;

	int imgCnt,imgNum;
	IMAGE *img[3],*mask[3];

	virtual void init();
	virtual int update(int direction);
	virtual void draw();
};
