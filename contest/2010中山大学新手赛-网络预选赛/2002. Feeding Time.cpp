#include <iostream>
#include <queue>

using namespace std;

struct farm{
	int x,y;
	char data;
} node[755][755];
int n, m;
int dir[8][2] = { 
					  {0,1},{0,-1},{-1,0},{-1,-1},
					  {-1,1},{1,-1},{1,0},{1,1}
					};

int bfs(int x, int y)
{
	node[x][y].data = '*';
	queue<farm> t;
	t.push(node[x][y]);
	int cnt =  1;
	while ( !t.empty() )
	{
		farm cur = t.front();
		t.pop();
		int x, y;
		for ( int i = 0; i < 8; i++ )
		{
			x = cur.x+dir[i][0];
			y = cur.y+dir[i][1];
			if ( x >= 0 && x <= m && y >= 0 && y <= n && node[x][y].data == '.')
			{
				node[x][y].data = '*';
				t.push(node[x][y]);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	
	cin >> n >> m;
	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; j++ )
		{
			cin >> node[i][j].data;
			node[i][j].x = i;
			node[i][j].y = j;
		}
	int max = 0;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
		{
			if ( node[i][j].data == '.' )
			{
				int t = bfs(i,j);
				if ( t > max) max = t;
			}
		}
	
	cout << max << endl;
	
	return 0;
}
