#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Game.h"
using namespace std;

Game::Game()
{
	player[0] = NULL;
	player[1] = NULL;
	events[0] =  NULL;
	events[1] =  NULL;
	round = 0;
	turn = 1;
	eventMess[0] = "竟然被楼上丢下来的花盆砸到！" ;
	eventMess[1] = "今天出门踩到狗屎！";
	eventMess[2] = "哇，突然下起狂风暴雨！";
	eventMess[3] = "感冒太可怕了！";
	eventMess[4] = "今天天气真好！";
	eventMess[5] = "运气不错！" ;
	gameInterface.welcomePage();
	gameInterface.introductionPage();
}
void Game::start()
{
	int gameMode = gameInterface.selectModePage();
	_n = gameInterface.inputSizePage();
	for (int i = 0; i < 2; i++)
		initialEvents(events[i]);	
	if (gameMode == 1) {
		int difficulty = gameInterface.selectDifficultyPage();
		player[0] = new HumanPlayer("玩家", events[0], _n/10);
		player[1] = new ComputorPlayer("电脑", events[1], _n/10, _n, difficulty);
	}
	else {
		player[0] = new HumanPlayer("玩家1", events[0], _n/10);
		player[1] = new HumanPlayer("玩家2", events[1], _n/10);
	}
	player[0]->gainPiece(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "⊕", 0 , 2, 0);
	player[1]->gainPiece(FOREGROUND_RED|FOREGROUND_INTENSITY, "⊕", 0 , 2, 1);

	gameInterface.runGamePage(player[0]->getPiece(), player[1]->getPiece());
}

Game::~Game()
{
	delete player[0];
	delete player[1];
	delete[] events[0];
	delete[] events[1];
}

bool Game::run()
{
	turn ^= 1;
	++round;
	gameInterface.refreshInfoBox(player[0], player[1], round);// 刷新信息框 
	char s[100];
	sprintf(s, "%s回合",player[turn]->getName());
	gameInterface.displayMess(player[turn], s); // 提示第几回合 
	int diceNum = player[turn]->play(); // player 得到一个点数 
	while(_kbhit())//清除键盘缓冲区
		_getch();
	gameInterface.refreshInfoBox(player[0], player[1], round); // 刷新信息框 
	sprintf(s, "%s得到的骰子数为：%d", player[turn]->getName(), diceNum);
	gameInterface.displayMess(player[turn], s);
	
	gameInterface.movePiece(player[turn]->getPiece(), diceNum); // 移动棋子 
	if ( player[turn]->getPiece().getPos() == _n ) { // 到达终点 
		sprintf(s, "%s到达终点！！不容易啊！！！", player[turn]->getName());
		gameInterface.displayMess(player[turn], s);
		gameInterface.endPage();
		return false;
	}
	gameInterface.displayMess(player[turn], getEvent());  // 
	Sleep(1000);
	gameInterface.movePiece(player[turn]->getPiece(), events[turn][player[turn]->getPiece().getPos()]);
	if ( player[turn]->getPiece().getPos() == _n ) {
		gameInterface.endPage();
		return false;
	}
	Sleep(1000);
	return true;
}

void Game::initialEvents(int *&event)
{
	event = new int[_n+1];
	bool setted[_n+1];
	for (int i = 0; i <= _n; i++ )
		setted[i] = false;
	int last = 0;
	int now = rand()%6+1;
	setted[now] = true;
	event[now] = 0;
	while (now+5 < _n) {
		int a = rand()%(now-last)+5-now+last;
		last = now;
		now += a;
		event[now] = 0;
		setted[now] = true;
	}
	setEvent(event, setted, 10, 2);
	setEvent(event, setted, 20, 3);
	setEvent(event, setted, 40, 5);
	setEvent(event, setted,40, -20);
	setEvent(event, setted,30, -15);
	setEvent(event, setted,20, -10);
	setEvent(event, setted, 10, -5);
	setEvent(event, setted, 10, -3);
	for (int i = 1; i <= _n; i++)
		if (!setted[i] )
			event[i] = -2;	
//	for (int i = 1; i <= _n; i++) {
//		printf("%d\t",event[i]);
//		if (i%10 == 0)
//			printf("\n");
//	} 
//			printf("\n");
	
}
void Game::setEvent(int *event, bool setted[], int n, int value)
{
	for (int i = 0; i < _n/n; i++) {
		int cnt = rand()%_n;
		int pos = 0;
		int count = 0;
		while ( count < cnt ) {
			pos = (pos+1)%_n;
			if ( !setted[pos+1] )
				count++;
		}
		event[pos+1] = value;
		setted[pos+1] = true;
	}
}
const char* Game::getEvent()
{
	static char s[100];
	int pos = player[turn]->getPiece().getPos();
	if ( events[turn][pos] == 0)
		sprintf(s, "还好还好！%s留在了原地", player[turn]->getName());
	else if (events[turn][pos] + pos >= _n) 
		sprintf(s, "%s到达终点！！真不容易啊！！！", player[turn]->getName());
	else if ( events[turn][pos] > 0 ) 
		sprintf(s, "%s, %s前进%d步", eventMess[rand()%2+4], player[turn]->getName(), events[turn][pos]);
	else 
		sprintf(s, "%s, %s回到了位置%d", eventMess[rand()%4], player[turn]->getName(), pos+events[turn][pos]<0?0:pos+events[turn][pos]);
	return s;	 
}
