#include <iostream>
using namespace std;

int main()
{
	int dis[18][18];
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> dis[i][j];
	int mini = 1<<30;
	for(int i = 0; i < n; i++) {
		bool vis[18] = {0};
		int now = i, cnt = 1, distance = 0;
//		cout << now << ' ';
		while(cnt < n) {
			vis[now] = true;
			int nextDis = 1<<30;
			int nextIndex = 0;
			for(int j = 0; j < n; j++) {
				if (j != now && !vis[j] && dis[now][j] < nextDis) {
					nextDis = dis[now][j];
					nextIndex = j;
				}
			}
			now = nextIndex;
//			cout << now << ' ';
			distance += nextDis;
			cnt++;
		}
//		cout << endl;
		distance += dis[now][i];
		if (distance < mini)
			mini = distance;		
	}
	cout << mini << endl;
	return 0;
}
