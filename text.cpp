#include "text.h"
#include "menuscene.h"

void putText(int textColor,int size,const char *style,const char *text,int x,int y,int height,int width) {
	setbkmode(TRANSPARENT);
	settextcolor(textColor);
	settextstyle(size, 0, style);

	LOGFONT fontstyle;
	gettextstyle(&fontstyle);
	fontstyle.lfQuality = 2;
	settextstyle(&fontstyle);

	RECT rect;
	rect.left = x, rect.top = y, rect.bottom = y + height, rect.right = x + width;
	drawtext(text, &rect,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
}