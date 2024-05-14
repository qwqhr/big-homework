#include "mainscene.h"

void Mainscene::init() {
	musicCnt = 2,cnt = 0;
	for (int i = 1;i <= musicCnt;++i) 
		sprintf_s(backgroundMusic[i], "./sound/gameMusic%d.mp3", i);
	musicNum = (rand() % musicCnt) + 1;
	soundPlay(backgroundMusic[musicNum]);

	loadimage(&background, "./image/GameBackground.png", 1620 * 0.5, 1215 * 0.5, 0);

	dog.init();
}

void Mainscene::control() {
	char opt;
	if (_kbhit() == 0) return;
	opt = _getch();
	if (opt == 'a' || opt == 'A') dog.update(left);
	else if (opt == 'd' || opt == 'D') dog.update(right);
	else if (opt == 'w' || opt == 'W') dog.update(up);
	else if (opt == 's' || opt == 'S') dog.update(down);
}

int Mainscene::update() {
	generateBullet();

	for (std::vector<Bullet>::iterator it = bullet.begin();it != bullet.end();) {
		int state = it->update(enemy);
		if (state == destroy) it = bullet.erase(it);
		else it++;
	}

	for (std::vector<Enemy>::iterator it = enemy.begin();it != enemy.end();) {
		int state = it->update(left);
		if (state == destroy) it = enemy.erase(it);
		else it++;
	}

	++cnt;
	if (cnt == 20) cnt = 0, generateEnemy();

	return Running;
}

void Mainscene::draw() {
	putimage(0, 0, &background);
	dog.draw();
	for (std::vector<Bullet>::iterator it = bullet.begin();it != bullet.end();it++) {
		it->draw();
	}

	for (std::vector<Enemy>::iterator it = enemy.begin();it != enemy.end();it++) {
		it->draw();
	}
}

void Mainscene::close() {
	soundClose(backgroundMusic[musicNum]);
}

void Mainscene::generateBullet() {
	Bullet b(dog.x + dog.width, dog.y + dog.height / 2, 5);
	bullet.push_back(b);
	bullet.rbegin()->init();
}

void Mainscene::generateEnemy() {
	Enemy e;
	enemy.push_back(e);
	enemy.rbegin()->init();
}