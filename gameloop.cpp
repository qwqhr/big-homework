#include "gameloop.h"

LARGE_INTEGER startCount, endCount, F;

int gameloop(int fps, Scene *scene){
	timeBeginPeriod(1);
	QueryPerformanceFrequency(&F);
	BeginBatchDraw();

	scene->init();
	
	int state;

	while (1) {
		QueryPerformanceCounter(&startCount);
        
		scene->control();
		state=scene->update();
		if (state != Running) break;
		scene->draw();

		FlushBatchDraw();

		QueryPerformanceCounter(&endCount);
		while (endCount.QuadPart - startCount.QuadPart < F.QuadPart / fps) {
			Sleep(1);
			QueryPerformanceCounter(&endCount);
		}
	}

	scene->close();
	timeEndPeriod(1);
	EndBatchDraw();
	return state;
}