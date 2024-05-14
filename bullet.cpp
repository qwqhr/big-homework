#include "bullet.h"

void Bullet::init() {
	width = 10, height = 10;
	loadimage(img, "./image/bullet.png", 10, 10, 1);
	loadimage(mask, "./image/bulletmask.png", 10, 10, 1);
}

int	Bullet::update(std::vector<Enemy> &enemy) {
	x += v;
	if (x >= 1620 * 0.5) return destroy;

	for (std::vector<Enemy>::iterator it = enemy.begin();it != enemy.end();++it) {
		if (x + width >= it->x && x <= it->x + it->width) {
			if (y + height >= it->y && y <= it->y + it->height) {
				it->hit++;
				return destroy;
			}
		}
	}

	return survival;
}

void Bullet::draw() {
	putTransparentImage(x, y, mask, img);
}
