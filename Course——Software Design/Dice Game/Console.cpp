#include "Console.h"

Console::Console()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

Console::~Console()
{
	CloseHandle(hOut);
}

void Console::write(short x, short y, WORD *att,  const char *lpszString )
{
	COORD pos = {x, y};
	if (att != NULL)
		FillConsoleOutputAttribute( hOut, *att, lstrlen(lpszString), pos, &written);    
	WriteConsoleOutputCharacter(hOut, lpszString, lstrlen(lpszString), pos, &written);
	
}

void Console::fillCharacter(short x, short y, WORD* att, WCHAR ch, short length)
{
	COORD pos = {x, y};
	if ( att != NULL)
		FillConsoleOutputAttribute(hOut, *att, length, pos, &written);
	FillConsoleOutputCharacter(hOut, ch, length, pos, &written);
}

void Console::setWindowSize(short x, short y)
{
	COORD size = {x, y};
 	SetConsoleScreenBufferSize(hOut,size);
 	SMALL_RECT rc = {0,0, x-1, y-1}; 
 	SetConsoleWindowInfo(hOut,true ,&rc);
}

void Console::setTitle(const char *title)
{
	SetConsoleTitle(title); 
}

void Console::moveBlock(SMALL_RECT* block, COORD destinationPos, WORD *att)
{
	COORD bufSize = {block->Right-block->Left+1,block->Bottom-block->Top+1};
	CHAR_INFO buf[bufSize.X*bufSize.Y];	
	COORD bufCoord = {0,0};
	ReadConsoleOutput(hOut,buf,bufSize,bufCoord,block ); 
	CHAR_INFO nbuf[bufSize.X*bufSize.Y];
	CHAR_INFO temp= buf[0];
	temp.Char.AsciiChar = ' ';
	for ( int i = 0; i < bufSize.X*bufSize.Y; i++ )
	{
		nbuf[i] = temp;
	}
	WriteConsoleOutput(hOut,nbuf,bufSize,bufCoord,block);
	SMALL_RECT nblock = {destinationPos.X, destinationPos.Y, destinationPos.X+bufSize.X-1, destinationPos.Y+bufSize.Y-1};
	WriteConsoleOutput(hOut,buf,bufSize,bufCoord,&nblock);
}

void Console::drawBox(SMALL_RECT rc, WORD* att)
{
	if ((rc.Right-rc.Left)%2 == 0)
		rc.Right++; 
	//填充属性 
	for(int i = rc.Top; i <= rc.Bottom; i++)
		fillCharacter(rc.Left,i,att,' ',rc.Right-rc.Left+1);
	// 画边框 
	for (int x = rc.Left;x < rc.Right; x+=2) {
		for ( int y = rc.Top; y <= rc.Bottom; y++) {
			write(x,y,NULL,"  ");
			if (y == rc.Top || y == rc.Bottom ) {
				write(x,y,NULL,"┉");
			}
			else if (x == rc.Left || x == rc.Right-1) {
				write(x,y,NULL,"┋");
			}
			if (x == rc.Left && y == rc.Top)
				write(x,y,NULL,"┏");
			else if (x == rc.Left && y == rc.Bottom)
				write(x,y,NULL,"┗");
			else if (x == rc.Right-1 && y == rc.Top)
				write(x,y,NULL,"┓");
			else if (x == rc.Right-1 && y == rc.Bottom)			
				write(x,y,NULL,"┛");
		}
	}
}

CONSOLE_SCREEN_BUFFER_INFO Console::getScreenInfo()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo; // 获取窗口缓冲区信息
	GetConsoleScreenBufferInfo(hOut, &bufInfo );
	return bufInfo;
}

void Console::setCursorInfo(int x, int y, bool vis)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut,pos);
	CONSOLE_CURSOR_INFO lpConsoleCursorInfo;
	GetConsoleCursorInfo(hOut, &lpConsoleCursorInfo);
	lpConsoleCursorInfo.bVisible = vis;
	SetConsoleCursorInfo(hOut, &lpConsoleCursorInfo);
}

void Console::clearScreen(SMALL_RECT rc)
{
	if (rc.Bottom == 0 && rc.Left == 0 && rc.Right == 0 && rc.Top == 0) {
		COORD size = getScreenInfo().dwSize;
		rc.Right = size.X-1;
		rc.Bottom = size.Y-1;
	}
	WORD att = getScreenInfo().wAttributes;
	for(int i = rc.Top; i <= rc.Bottom; i++)
		fillCharacter(rc.Left,i,&att,' ',rc.Right-rc.Left+1);
} 

void Console::setTextAttribute(WORD att)
{
	SetConsoleTextAttribute(hOut,att);
}
