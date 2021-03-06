/*
Problem
체스판 위에 한 나이트가 놓여져 있다.
나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다.
나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

Input

입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다.
체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

Output
각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.



Description
거리를 기록하는 플러드 필 문제이다.
주의할점은 이동 과정에서 시작점으로 돌아올 수도 있기 때문에, 시작점의 거리를 1로 초기화하고 출력시에 거리를 -1 해야한다.


https://www.acmicpc.net/problem/7562
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1};
int board[300][300];
int dist[300][300];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int I, posx, posy, destx, desty;
	while (T--)
	{
		cin >> I >> posx >> posy >> destx >> desty;
		if(posx==destx && posy==desty)
		{
			cout<<"0"<<'\n';
			continue;
		}
		queue<pair<int,int>> q;
		q.push(make_pair(posx, posy));
		dist[posx][posy] = 1;

		while (!q.empty())
		{
			posx = q.front().first;
			posy = q.front().second;
			q.pop();
			if (posx == destx && posy == desty)
				break;
			for (int i = 0; i < 8; i++)
			{
				int nx = posx + dx[i];
				int ny = posy + dy[i];
				
				if(0<=nx&&nx<I&& 0<=ny&&ny<I)
				{
					if (dist[nx][ny] == 0)
					{
						dist[nx][ny] = dist[posx][posy] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		cout << dist[posx][posy]-1<< '\n';
		memset(dist, 0, sizeof(dist));
	}
	return 0;
}
