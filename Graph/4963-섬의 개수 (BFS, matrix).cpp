/*
Problem

정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 지도는 바다로 둘러쌓여 있으며, 지도 밖으로 나갈 수 없다.

Input

입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.


Output

각 테스트 케이스에 대해서, 섬의 개수를 출력한다.



Description

연결요소의 개수를 찾는것과 동일한 문제이다.
각각의 섬간에 인접한것을 간선으로 취급하면된다 따라서, BFS나 DFS를 수행하며, 수행한 횟수를 카운트하면 된다.
단 여기서, 그래프를 정의하지 않고도 풀이가 가능하다.
입력받은 matrix를 그대로 사용하고, 좌표단위로 BFS, DFS 개념을 바탕으로 접근을 하면, 된다.
이 문제의 경우 특정점에서 이동할 수있는 경우가 상,하,좌,우,대각선 4방향으로, 총 8방향이 인접한 영역으로 판단 될 수 있다.
이를 단순화 하기위해, 방향에 대한 정의를 사전에 dirX, dirY를 지정을해서 접근을 하면 조금 더 간결한 코드를 만들 수 있다.

https://www.acmicpc.net/problem/4963

*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int lsmap[51][51];
int island[51][51];
const int dirX[] = { -1,0,1,1,1,0,-1,-1 };
const int dirY[] = { 1,1,1,0,-1,-1,-1,0 };
int w, h;

void bfs(int x, int y,int group)
{
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	island[x][y] = group;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nextX = x + dirX[i];
			int nextY = y + dirY[i];
			if (0 <= nextX && nextX < h && 0 <= nextY && nextY < w)
			{
				if (lsmap[nextX][nextY] == 1 && island[nextX][nextY]==0)
				{
					q.push(make_pair(nextX, nextY));
					island[nextX][nextY] = group;
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h;
	while (w != 0 && h != 0)
	{
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> lsmap[i][j];
		
		int cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (lsmap[i][j] == 1 && island[i][j] == 0)
					bfs(i,j,++cnt);
		cout << cnt <<'\n';
		
		memset(island, 0, sizeof(island));
		memset(lsmap, 0, sizeof(lsmap));
		cin >> w >> h;
	}


}
