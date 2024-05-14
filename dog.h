#pragma once
#include <vector>
#include "character.h"

class Dog :public Character{
public:
	Dog() {
		for (int i = 0;i <= 2;++i) {
			img[i] = NULL, mask[i] = NULL;
		}
	}

	void init();
	int update(int direction);
	void draw();
};