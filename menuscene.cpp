#include "menuscene.h"

using namespace std;

void Button::set(int X, int Y,const char *Text) {
	x = X, y = Y;
	strcpy_s(text, Text);
}

void Button::init() {
	width = 150, height = 50;
	textColor = BLACK;
	lineColor = BLACK;
	isTouch = isClick = 0;
}

void Button::update() {

}

void Button::draw() {
	setlinecolor(lineColor);
	setlinestyle(PS_SOLID,5,0,0);
	roundrect(x, y, x + width, y + height,15,15);
	putText(textColor, 40, "YEFONTTianPinCaiDanTi 標準", text, x, y, height, width);
}

void Menuscene::init(){
	buttonCnt = 2;
	for (int i = 1;i <= buttonCnt;++i) button[i].init();
	button[1].set(336, 300,"开始游戏");
	button[2].set(336, 400,"结束游戏");

	strcpy_s(backgroundMusic, "./sound/menuMusic.mp3");
	soundPlay(backgroundMusic);

	loadimage(&background, "./image/MenuBackground.png",1620*0.5,1215*0.5,0);
	putimage(0,0,&background);
}

void Menuscene::control(){
	ExMessage msg;
	getmessage(&msg, EX_MOUSE);

	for (int i = 1;i <= buttonCnt;++i) {
		if (msg.x >= button[i].x && msg.x <= button[i].x + button[i].width && msg.y >= button[i].y && msg.y <= button[i].y + button[i].height) {
			button[i].isTouch = 1;
			if (msg.message == WM_LBUTTONDOWN) button[i].isClick = 1;
			else button[i].isClick = 0;
		}
		else button[i].textColor = button[i].isTouch = 0;
	}
}

int Menuscene::update() {
	for (int i = 1;i <= buttonCnt;++i) {
		if (button[i].isTouch)
			button[i].textColor = 0x800080;
		else
			button[i].textColor = BLACK;
	}

	if (button[1].isClick) return GameStart;
	if (button[2].isClick) return GameExit;
	return Running;
}

void Menuscene::draw() {
	for (int i = 1;i <= buttonCnt;++i) button[i].draw();
}

void Menuscene::close() {
	soundClose(backgroundMusic);
}