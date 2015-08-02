#include "GameInterface.h"
#include <stdio.h>
#define UP      0x4800 
#define DOWN    0x5000 
#define ENTER   0x1c0d 

GameInterface::GameInterface()
{
	gridsCoord = NULL;
	myConsole.setCursorInfo(0,0,false);
}
void GameInterface::welcomePage()
{
	WORD att = FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE;
	myConsole.setTextAttribute( FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	myConsole.setTitle("Dice Game");
	myConsole.setWindowSize(100,35);
	const char *name[6] = {
		" ▁▁▁      ┏┓      _____   ┏━━┓        _____      ____                   ┏━━┓",
		"┃ ▁▁╲    ┗┛    ╱  ___▏ ┃┏━┛      ╱  ___▏  ╱    ╲   ╱▔╲╱▔╲  ┃┏━┛",
		"┃┃  ┃┃   ┏┓   ┃ ╱      ┃┗━┓     ┃ ╱      ┃ ╱╲ ┃ ┃ /\\_  _/\\ ┃ ┃┗━┓",
		"┃┃  ┃┃   ┃┃   ┃┃       ┃┏━┛     ┃┃  ┏┓ ┃┗━┛┃ ┃┃ ┃┃ ┃┃ ┃┏━┛",
		"┃┗━╯┃   ┃┃   ┃╰━━┓ ┃┗━┓     ┃╰━┛┃ ┃┏━┓┃ ┃┃ ┃┃ ┃┃ ┃┗━┓",
		"┗━━━╯   ┗┛   ╰━━━┛ ┗━━┛     ╰━━━┛ ┗┛  ┗┛ ┗┛ ┗┛ ┗┛ ┗━━┛",
	};
 	int x = (100-lstrlen(name[0]))/2;
 	int y = (30-6)/2-3;
 	for ( int i = 0; i < 6; i++)
 		myConsole.write(x,y+i, &att,name[i]);
	while(_kbhit())//清除键盘缓冲区
		_getch();
	att = 0;
	const char* info = "Press any key to start!";
	while (!_kbhit()) {
		att  = (att+1)%15+1;
		myConsole.write((100-lstrlen(info))/2,30-8,&att,info);
		Sleep(200);
		myConsole.fillCharacter((100-lstrlen(info))/2,30-8,&att,' ',lstrlen(info));
		Sleep(200);
	}
	myConsole.clearScreen();
}
void GameInterface::introductionPage()
{
	WORD att = FOREGROUND_INTENSITY|FOREGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE;
	const char* s[11] = {
		"******游戏介绍******",
		" * 本游戏中文名为骰子游戏，游戏分两方，双方各持一个棋子，在地图上的起点出发。",
		" * 游戏双方通过轮流掷骰子在地图上移动，最先到达终点者获胜",
		" * 在某一回合中，当棋子移动到某一点时，会触发游戏事件，可导致棋子前进，后退或不动", 
		" * 智能骰子：使用智能骰子，可以自动躲避导致棋子后退的事件",
		" * 游戏开始时，游戏双方会得到一定数量智能骰子\"●\"", 
		" * 玩家回合时，玩家需要输入一个骰子点数(1-6),若输入其他数字，则表示使用智能骰子", 
		" * 当智能骰子使用完时，如果继续使用智能骰子，将得到普通的随机点数", 
		" * 单人模式下，玩家对战电脑，可选择简单，中等，困难三种难度",
		" * 双人模式下，玩家对战玩家，双方轮流输入骰子点数", 
		"by我心御魔", 
	};
	COORD size = myConsole.getScreenInfo().dwSize;
	SMALL_RECT rc = {7, size.Y/2-12, size.X-8, size.Y/2+12};
	myConsole.drawBox(rc, &att);
	myConsole.write(size.X/2-lstrlen(s[0])/2, rc.Top+2, &att, s[0]);
	for (int i = 1; i <= 9; i++)
		myConsole.write(rc.Left+2,rc.Top+2+i*2, &att, s[i]);
	myConsole.write(rc.Right-lstrlen(s[10])-2, rc.Bottom-1, &att, s[10]);
	while (_kbhit())
		_getch();
	
	while(!_getch());
	myConsole.clearScreen();
}
int GameInterface::selectModePage()
{
	COORD wSize = myConsole.getScreenInfo().dwSize;
	const char *str[3] = {
		"单人模式",
		"双人模式",
		"*按↑↓选择游戏模式，回车确定"
	};
	int x = (wSize.X - 10)/2;
	int y = (wSize.Y - 4)/2;
	myConsole.write(x, y, NULL, str[0]);
	myConsole.write(x, y+2, NULL, str[1]);
	myConsole.write((wSize.X - lstrlen(str[2]))/2, y+10, NULL, str[2]);
	
	int ch;
	bool i = 0;
	myConsole.write(x-4, y+i*2, NULL, "Θ");
	myConsole.write(x-4, y+(i^1)*2, NULL, "  ");
	
	while(_kbhit())//清除键盘缓冲区
		_getch();
	while ( (ch = _getch()) != '\r' ) {
		if ( ch == 0 ) 
			ch = _getch();

		if (ch == (DOWN>>8) || ch == (UP>>8) ) {
			i ^= 1;
		}
		myConsole.write(x-4, y+i*2, NULL, "Θ");
		myConsole.write(x-4, y+(i^1)*2, NULL, "  ");
	}
	myConsole.clearScreen();
	return i+1;
}
int GameInterface::selectDifficultyPage()
{
	COORD wSize = myConsole.getScreenInfo().dwSize;
	const char *str[4] = {
		"简单",
		"中等",
		"困难", 
		"*按↑↓选择电脑难度，回车确定"
	};
	int x = (wSize.X - 10)/2;
	int y = (wSize.Y - 4)/2;
	myConsole.write(x, y, NULL, str[0]);
	myConsole.write(x, y+2, NULL, str[1]);
	myConsole.write(x, y+4, NULL, str[2]);
	myConsole.write((wSize.X - lstrlen(str[3]))/2, y+10, NULL, str[3]);
	
	int ch;
	int i = 0;
	myConsole.write(x-4, y+i*2, NULL, "Θ");
	myConsole.write(x-4, y+(i+1)%3*2, NULL, "  ");
	myConsole.write(x-4, y+(i+2)%3*2, NULL, "  ");
	
	while(_kbhit())//清除键盘缓冲区
		_getch();
	while ( (ch = _getch()) != '\r' ) {
		if ( ch == 0 ) 
			ch = _getch();

		if (ch == (DOWN>>8)) {
			i = (i+1)%3;
		}
		else if (ch == (UP>>8)) {
			i = (i+2)%3;
		}
		myConsole.write(x-4, y+i*2, NULL, "Θ");
		myConsole.write(x-4, y+(i+1)%3*2, NULL, "  ");
		myConsole.write(x-4, y+(i+2)%3*2, NULL, "  ");
	}
	myConsole.clearScreen();
	return i+2;
}
int GameInterface::inputSizePage()
{
	COORD wSize = myConsole.getScreenInfo().dwSize;
	SMALL_RECT rc = {(wSize.X-30)/2, (wSize.Y-5)/2, (wSize.X-30)/2+30, (wSize.Y-5)/2+5};
	WORD att = FOREGROUND_GREEN|FOREGROUND_RED| FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE;
	myConsole.drawBox(rc,&att);
	myConsole.setCursorInfo(rc.Left+2, rc.Top+1);
	const char* str = "*请输入地图大小（32-60）";
	myConsole.write(rc.Left+2,rc.Bottom-1,NULL,str);
	int n;
	scanf("%d",&n);
	myConsole.clearScreen();
	myConsole.setCursorInfo(0,0,false);
	mapSize = n;
	return n;
}
void GameInterface::runGamePage(Piece& piece1, Piece& piece2)
{
	WORD att = FOREGROUND_RED;
	delete gridsCoord;
	gridsCoord = new COORD[mapSize+1];
	int n = (mapSize-2)/3+1;
	int length = n*6+1;
	myConsole.setWindowSize(length+12 < 100?100:length+12,35);
	int posX = (myConsole.getScreenInfo().dwSize.X-length)/2;
	int posY = 3;
	WORD att1 = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY|BACKGROUND_RED | BACKGROUND_GREEN; 
	SMALL_RECT rc = {posX-2,posY-2,posX+length+2,posY+15+2};
	infoBox = {rc.Left,rc.Bottom+2,rc.Right,rc.Bottom+13};
	myConsole.drawBox(rc, &att1);
	myConsole.drawBox(infoBox, NULL);
	for(int i = 0; i < n; i++ )
	{
		myConsole.write(posX+i*6,posY,&att,"┳━━");
		myConsole.write(posX+i*6,posY+1,&att,"┃    ");
		myConsole.write(posX+i*6,posY+2,&att,"┃    ");
		myConsole.write(posX+i*6,posY+3,&att,"┻━━");
		myConsole.write(posX+i*6,posY+6,&att,"┳━━");
		myConsole.write(posX+i*6,posY+7,&att,"┃    ");
		myConsole.write(posX+i*6,posY+8,&att,"┃    ");
		myConsole.write(posX+i*6,posY+9,&att,"┻━━");
		if ( i < mapSize-2-2*n ) {
			myConsole.write(posX+i*6,posY+12,&att,"┳━━");
			myConsole.write(posX+i*6,posY+13,&att,"┃    ");
			myConsole.write(posX+i*6,posY+14,&att,"┃    ");
			myConsole.write(posX+i*6,posY+15,&att,"┻━━");
		}
	}
	myConsole.write(posX,posY,&att,"┏━━");
	myConsole.write(posX,posY+3,&att,"╰━━");
	myConsole.write(posX,posY+6,&att,"┏━━");
	myConsole.write(posX,posY+9,&att,"┣━━╋");
	myConsole.write(posX,posY+10,&att,"┃    ┃");
	myConsole.write(posX,posY+11,&att,"┃    ┃");
	myConsole.write(posX,posY+12,&att,"┣━━╋");
	myConsole.write(posX,posY+15,&att,"╰━━");
	
	myConsole.write(posX+(n-1)*6,posY,&att,"┳━━┓");
	myConsole.write(posX+(n-1)*6,posY+1,&att,"┃    ┃");
	myConsole.write(posX+(n-1)*6,posY+2,&att,"┃    ┃");
	myConsole.write(posX+(n-1)*6,posY+3,&att,"╋━━┫");
	myConsole.write(posX+(n-1)*6,posY+4,&att,"┃    ┃");
	myConsole.write(posX+(n-1)*6,posY+5,&att,"┃    ┃");
	myConsole.write(posX+(n-1)*6,posY+6,&att,"╋━━┫");
	myConsole.write(posX+(n-1)*6,posY+7,&att,"┃    ┃");	
	myConsole.write(posX+(n-1)*6,posY+8,&att,"┃    ┃");	
	myConsole.write(posX+(n-1)*6,posY+9,&att,"┻━━╯");
	myConsole.write(posX+(mapSize-2-2*n)*6,posY+12,&att,"┳━━┓");
	myConsole.write(posX+(mapSize-2-2*n)*6,posY+13,&att,"┃    ┃");
	myConsole.write(posX+(mapSize-2-2*n)*6,posY+14,&att,"┃    ┃");
	myConsole.write(posX+(mapSize-2-2*n)*6,posY+15,&att,"┻━━╯");
	int i = 0;
	while ( i < n ) {
		gridsCoord[i].X = posX+2+i*6;
		gridsCoord[i].Y = posY+1;
		myConsole.write(gridsCoord[i].X,gridsCoord[i].Y,&att,str(i));
		i++;
	}
	gridsCoord[i].X = posX+2+(n-1)*6;
	gridsCoord[i].Y = posY+4;
	myConsole.write(gridsCoord[i].X,gridsCoord[i].Y,&att,str(i));
	i++;
	while (i <= 2*n ) {
		gridsCoord[i].X = posX+2+(2*n-i)*6;
		gridsCoord[i].Y = posY+7;
		myConsole.write(gridsCoord[i].X,gridsCoord[i].Y,&att,str(i));
		i++;
	}
	gridsCoord[i].X = posX+2;
	gridsCoord[i].Y = posY+10;
	myConsole.write(gridsCoord[i].X,gridsCoord[i].Y,&att,str(i));
	i++;
	while( i <= mapSize ) {
		gridsCoord[i].X = posX+2+(i-2*n-2)*6;
		gridsCoord[i].Y = posY+13;
		myConsole.write(gridsCoord[i].X,gridsCoord[i].Y,&att,str(i));
		i++;
	}
	myConsole.write(
		gridsCoord[piece1.getPos()].X+piece1.getAbsCoord().X, 
		gridsCoord[piece1.getPos()].Y+piece1.getAbsCoord().Y,
		piece1.getAttribute(), piece1.getIcon());
	myConsole.write(
		gridsCoord[piece2.getPos()].X+piece2.getAbsCoord().X, 
		gridsCoord[piece2.getPos()].Y+piece2.getAbsCoord().Y,
		piece2.getAttribute(), piece2.getIcon());
}

void GameInterface::refreshInfoBox(Player *player1, Player *player2, const int round)
{
	Piece piece1 = player1->getPiece();
	Piece piece2 = player2->getPiece();
	
	SMALL_RECT rcLeft = {infoBox.Left+2,infoBox.Top+1, infoBox.Left+7,infoBox.Top+3};
	SMALL_RECT rcRight = {infoBox.Right-7,infoBox.Top+1, infoBox.Right-2,infoBox.Top+3};
	SMALL_RECT rcMid = {(infoBox.Right+infoBox.Left)/2-2,infoBox.Top+1, (infoBox.Right+infoBox.Left)/2+2, infoBox.Top+3};
	myConsole.drawBox(rcLeft, NULL);
	myConsole.drawBox(rcRight, NULL);
	myConsole.drawBox(rcMid, NULL);
	char roundNum[10];
	sprintf(roundNum,"%02d", round);
	WORD att = FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
	myConsole.write(rcLeft.Left+2, rcLeft.Top+1, piece1.getAttribute(), piece1.getIcon());
	myConsole.write(rcRight.Left+2, rcRight.Top+1, piece2.getAttribute(), piece2.getIcon());
	myConsole.write(rcMid.Left+2, rcMid.Top+1, &att, roundNum);
	myConsole.write(rcMid.Left, rcMid.Top+3, NULL, "回  合");
	myConsole.write(infoBox.Left+3,infoBox.Top+4, NULL, player1->getName());
	myConsole.write(infoBox.Right-2-lstrlen(player2->getName()),infoBox.Top+4, NULL, player2->getName());
	myConsole.fillCharacter(rcLeft.Right+2, rcLeft.Top+1, NULL, ' ', rcMid.Left-rcLeft.Right-2);
	myConsole.fillCharacter(rcMid.Right+2, rcMid.Top+1, NULL, ' ', rcRight.Left-rcMid.Right-2);
	
	for(int i = 0; i < player1->getNumOfSmartDice(); i++)
		myConsole.write(rcLeft.Right+1+2*i, rcLeft.Top+1,piece1.getAttribute(), "●");
	for(int i = 0; i < player2->getNumOfSmartDice(); i++)
		myConsole.write(rcRight.Left-2-2*i, rcRight.Top+1,piece2.getAttribute(), "●"); 
	const char *tip = "***输入你的骰子（1-6），或输入其他数字使用智能骰子或随机骰子***";
	myConsole.write((infoBox.Right+infoBox.Left)/2-lstrlen(tip)/2, infoBox.Bottom-1, NULL, tip);
	 
}
void GameInterface::displayMess(Player *player, const char *mess)
{
	SMALL_RECT messBox = {infoBox.Left+2, infoBox.Bottom-5, infoBox.Right-2, infoBox.Bottom-2};
	COORD pos = {messBox.Left, messBox.Top-1};
	myConsole.write(messBox.Left,messBox.Bottom,player->getPiece().getAttribute(), player->getPiece().getIcon());
	myConsole.write(messBox.Left+3,messBox.Bottom,player->getPiece().getAttribute(), mess);
	myConsole.moveBlock(&messBox, pos, NULL);
	myConsole.fillCharacter(pos.X, pos.Y, NULL, ' ', messBox.Right-messBox.Left);
	myConsole.write(messBox.Left,messBox.Bottom,player->getPiece().getAttribute(), player->getPiece().getIcon());
	myConsole.setCursorInfo(messBox.Left+3,messBox.Bottom);
}
void GameInterface::movePiece(Piece &piece, int dist)
{
	int sign = 1;
	if ( dist < 0 ) {
		dist = -dist;
		sign = -1;
	}
	int pos = piece.getPos();
	for ( int i = 0; i < dist; i++ ) {
		Sleep(300);
		pos += sign;
		myConsole.write(
			gridsCoord[piece.getPos()].X+piece.getAbsCoord().X,
			gridsCoord[piece.getPos()].Y+piece.getAbsCoord().Y,
			NULL, "  ");
		myConsole.write(
			gridsCoord[pos].X+piece.getAbsCoord().X,
			gridsCoord[pos].Y+piece.getAbsCoord().Y,
			piece.getAttribute(), piece.getIcon());
		piece.setPos(pos);
		
		if( piece.getPos() == 0 || piece.getPos() == mapSize )
			break;
	}
}
void GameInterface::endPage()
{
	COORD size = myConsole.getScreenInfo().dwSize;
	WORD att = FOREGROUND_INTENSITY|FOREGROUND_RED;
	myConsole.setCursorInfo(0,0,false);
	for(int i = size.Y-1; i >= 0; i--)
		for(int j = 0; j < size.X; j += 2) {
			myConsole.write(j,i,&att,"Θ");
			Sleep(5);
		}
	att |= FOREGROUND_GREEN;
	myConsole.write((size.X-4)/2, size.Y/2, &att, "游戏结束");
	while ( !_getch());
}

GameInterface::~GameInterface()
{
	delete gridsCoord;
}

const char* GameInterface::str(int n)
{
	static char s[10];
	sprintf(s,"%d",n);
	return s;
}




