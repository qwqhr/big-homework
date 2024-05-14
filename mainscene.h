#pragma once
#include "scene.h"
#include "dog.h"
#include "bullet.h"
#include "enemy.h"

class Mainscene :public Scene {
public:
	IMAGE background;
	char backgroundMusic[3][105];
	int musicCnt, musicNum;
	Dog dog;

	int cnt;
	std::vector<Bullet> bullet;
	std::vector<Enemy> enemy;

	void init();
	void control();
	int update();
	void draw();
	void close();
	void generateBullet();
	void generateEnemy();
};