#pragma once
#include <easyx.h>
#include <vector>
#include "image.h"
#include "enemy.h"
#include "character.h"

class Bullet {
public:
	int x, y, v;
	int width, height;

	IMAGE *img, *mask;
	
	Bullet() {
		img = NULL, mask = NULL;
	}

	Bullet(int X, int Y,int V) {
		x = X, y = Y, v = V;
		img = NULL, mask = NULL;
	}

	Bullet(const Bullet &b) {
		x = b.x, y = b.y, v = b.v;
		width = b.width,height = b.height;
		img = new IMAGE(), mask = new IMAGE();
		if (b.img != NULL) *img = *b.img;
		if (b.mask != NULL) *mask = *b.mask;
	}

	void init();
	int update(std::vector<Enemy> &enemy);
	void draw();
};