#include "enemy.h"

int Hp[5] = { 2,5,10 };
int Width[5] = { 50,80,150 };
int Height[5] = { 50,80,150 };
int V[5] = { 8,5,3 };

void Enemy::init(){
	imgCnt = 1, imgNum = 1;
	int r = rand() % 10;
	if (r <= 4) category = little;
	else if (r <= 7) category = middle;
	else category = big;

	width = Width[category], height = Height[category];
	hp = Hp[category], v = V[category];

	x = 1620 * 0.5 - width;
	y = rand() % int(1215 * 0.5 - height);

	char name[105];
	for (int i = 1;i <= imgCnt;++i) {
		img[i] = new IMAGE, mask[i] = new IMAGE;
		sprintf_s(name, "./image/enemy%d%d.png", category, i);
		loadimage(img[i], name, width, height, 1);
		sprintf_s(name, "./image/enemymask%d%d,png", category, i);
		loadimage(mask[i], name, width, height, 1);
	}
}

int Enemy::update(int direction) {
	x = x - v;
	hp = hp - hit;
	hit = 0;
	if (hp <= 0 || x + width <= 0) {
		return destroy;
	}
	return survival;
}

void Enemy::draw() {
	putTransparentImage(x, y, img[imgNum], mask[imgNum]);
}
