#include <ctime>
#include "gameloop.h"
#include "dog.h"
#include "menuscene.h"
#include "mainscene.h"

using namespace std;

int state;

int main(){
	srand(time(0));
	initgraph(1620*0.5,1215*0.5);

	while (1) {
		Menuscene scene1;

		state = gameloop(25, &scene1);
		if (state == GameExit) exit(0);
		
		Mainscene scene2;
		state = gameloop(25, &scene2);
	}
	return 0;
}