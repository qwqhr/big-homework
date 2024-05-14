#include "musiccontrol.h"

void soundPlay(char* musicName) {
	char command[105];
	sprintf_s(command, "%open %s", musicName);
	mciSendString(command, 0, 0, 0);
	sprintf_s(command, "play %s", musicName);
	mciSendString(command, 0, 0, 0);
}

void soundClose(char* musicName) {
	char command[105];
	sprintf_s(command, "close %s", musicName);
	mciSendString(command, 0, 0, 0);
}