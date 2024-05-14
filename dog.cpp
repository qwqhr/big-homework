#include "dog.h"

void Dog::init() {
	x = 0, y = 200, v = 10;
	width = 100, height = 100;
	hp = 5;
	imgCnt = 1, imgNum = 1;
	char imgName[105];
	for (int i = 1;i <= imgCnt; ++i) {
		img[i] = new IMAGE, mask[i] = new IMAGE;
		sprintf_s(imgName, "./image/testdog%d.png",i);
		loadimage(img[i], imgName, 100, 100, 1);
		sprintf_s(imgName, "./image/testdogmask%d.png", i);
		loadimage(mask[i], imgName, 100, 100, 1);
	}
}

int X[6] = { 0,0,-1,1,0 }, Y[6] = { -1,1,0,0,0 };

int Dog::update(int direction) {
	x += X[direction] * v, y += Y[direction] * v;
	return survival;
}

void Dog::draw() {
	putTransparentImage(x, y, mask[imgNum], img[imgNum]);
}