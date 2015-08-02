#include <conio.h>
#include <windows.h>

#ifndef _CONSOLE_H_
#define _CONSOLE_H_
class Console
{
public:
	Console();
	~Console();
	void write(short x, short y, WORD *att,  const char *string ); 
	void fillCharacter(short x, short y, WORD *att, WCHAR ch, short length);
	void setWindowSize(short x, short y);
	void setTitle(const char *title);
	void setCursorInfo(int x, int y, bool vis = true);
	void drawBox(SMALL_RECT rc, WORD* att);
	void setTextAttribute(WORD att);
	void clearScreen(SMALL_RECT rc = {0,0,0,0});
	CONSOLE_SCREEN_BUFFER_INFO getScreenInfo(); 
	void moveBlock(SMALL_RECT* block, COORD destinationPos, WORD *att);
private:	
	HANDLE hOut;
	DWORD written;	
};
#endif
