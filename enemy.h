#pragma once
#include <easyx.h>
#include "character.h"

enum enemy {
	little,
	middle,
	big
};

class Enemy :public Character {
public:
	int category;
	int hit;

	Enemy(){
		for (int i = 0;i <= 2;++i) {
			img[i] = NULL, mask[i] = NULL;
		}
	}

	void init();
	int update(int direction);
	void draw();
};
