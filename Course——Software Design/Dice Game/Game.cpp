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
	eventMess[0] = "��Ȼ��¥�϶������Ļ����ҵ���" ;
	eventMess[1] = "������Ųȵ���ʺ��";
	eventMess[2] = "�ۣ�ͻȻ�����籩�꣡";
	eventMess[3] = "��ð̫�����ˣ�";
	eventMess[4] = "����������ã�";
	eventMess[5] = "��������" ;
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
		player[0] = new HumanPlayer("���", events[0], _n/10);
		player[1] = new ComputorPlayer("����", events[1], _n/10, _n, difficulty);
	}
	else {
		player[0] = new HumanPlayer("���1", events[0], _n/10);
		player[1] = new HumanPlayer("���2", events[1], _n/10);
	}
	player[0]->gainPiece(FOREGROUND_GREEN|FOREGROUND_INTENSITY, "��", 0 , 2, 0);
	player[1]->gainPiece(FOREGROUND_RED|FOREGROUND_INTENSITY, "��", 0 , 2, 1);

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
	gameInterface.refreshInfoBox(player[0], player[1], round);// ˢ����Ϣ�� 
	char s[100];
	sprintf(s, "%s�غ�",player[turn]->getName());
	gameInterface.displayMess(player[turn], s); // ��ʾ�ڼ��غ� 
	int diceNum = player[turn]->play(); // player �õ�һ������ 
	while(_kbhit())//������̻�����
		_getch();
	gameInterface.refreshInfoBox(player[0], player[1], round); // ˢ����Ϣ�� 
	sprintf(s, "%s�õ���������Ϊ��%d", player[turn]->getName(), diceNum);
	gameInterface.displayMess(player[turn], s);
	
	gameInterface.movePiece(player[turn]->getPiece(), diceNum); // �ƶ����� 
	if ( player[turn]->getPiece().getPos() == _n ) { // �����յ� 
		sprintf(s, "%s�����յ㣡�������װ�������", player[turn]->getName());
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
		sprintf(s, "���û��ã�%s������ԭ��", player[turn]->getName());
	else if (events[turn][pos] + pos >= _n) 
		sprintf(s, "%s�����յ㣡���治���װ�������", player[turn]->getName());
	else if ( events[turn][pos] > 0 ) 
		sprintf(s, "%s, %sǰ��%d��", eventMess[rand()%2+4], player[turn]->getName(), events[turn][pos]);
	else 
		sprintf(s, "%s, %s�ص���λ��%d", eventMess[rand()%4], player[turn]->getName(), pos+events[turn][pos]<0?0:pos+events[turn][pos]);
	return s;	 
}
