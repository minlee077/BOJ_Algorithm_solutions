/*
Problem
N×M 크기의 보드와 4개의 버튼으로 이루어진 게임이 있다. 
보드는 1×1크기의 정사각형 칸으로 나누어져 있고, 각각의 칸은 비어있거나, 벽이다.
두 개의 빈 칸에는 동전이 하나씩 놓여져 있고, 두 동전의 위치는 다르다.

버튼은 "왼쪽", "오른쪽", "위", "아래"와 같이 4가지가 있다. 버튼을 누르면 두 동전이 버튼에 쓰여 있는 방향으로 동시에 이동하게 된다.

동전이 이동하려는 칸이 벽이면, 동전은 이동하지 않는다.
동전이 이동하려는 방향에 칸이 없으면 동전은 보드 바깥으로 떨어진다.
그 외의 경우에는 이동하려는 방향으로 한 칸 이동한다.이동하려는 칸에 동전이 있는 경우에도 한 칸 이동한다.
두 동전 중 하나만 보드에서 떨어뜨리기 위해 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

Input
첫째 줄에 보드의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 20)

둘째 줄부터 N개의 줄에는 보드의 상태가 주어진다.

o: 동전
.: 빈 칸
#: 벽
동전의 개수는 항상 2개이다.

Output
첫째 줄에 두 동전 중 하나만 보드에서 떨어뜨리기 위해 눌러야 하는 버튼의 최소 횟수를 출력한다.
만약, 두 동전을 떨어뜨릴 수 없거나, 버튼을 10번보다 많이 눌러야 한다면, -1을 출력한다.

Description
BFS를 통해 동시에 떨어지지 않으면서, 하나가 떨어지는 상황을 구해내면 된다.
n제한이 10이므로, 모든 경우의수를 시도해볼때, 4^10 = 4048로, 브루트포스 방식으로도 구현이 가능하다.
만약, BFS로 구현하게 된다면, 이전 기록했던 상태와 같아지는 상황을 사전에 중단하므로써, 시간을 단축할 수 있다.

이 코드에서는 브루트포스를 통해 구현하겠다.

https://www.acmicpc.net/problem/16197
*/
#include <iostream>
using namespace std;

int n, m;
char board[21][21];

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int fin(int fx, int fy, int sx, int sy)
{
	if (fx < 0 || fy < 0 || fx>=m || fy>=n)
	{
		if (sx < 0 || sy < 0 || sx>=m || sy>=n)
			return 0;
		else
			return 1;
	}
	if (sx < 0 || sy < 0 || sx>=m|| sy>=n)
	{
		if (fx < 0 || fy < 0 || fx>=m || fy>=n)
			return 0;
		else
			return 1;
	}
	return -1;
}
int go(int fx, int fy, int sx, int sy, int cnt)
{
	if (cnt == 10)
		return -1;
	
	int _min = -1;
	for (int k = 0; k < 4; k++)
	{
		int nfx = fx + dx[k];
		int nfy = fy + dy[k];
		int nsx = sx + dx[k];
		int nsy = sy + dy[k];
		int fincheck = fin(nfx, nfy, nsx, nsy);
		if (fincheck == 0)
			continue;
		if (fincheck == 1)
			return cnt+1;

		if (board[nfy][nfx] == '#')
			nfx = fx, nfy = fy;
		if (board[nsy][nsx] == '#')
			nsx = sx, nsy = sy;

		int _val = go(nfx, nfy, nsx, nsy, cnt + 1);
		if (_val == -1)continue;
		if (_min == -1 || _min > _val)
			_min = _val;
	}
	return _min;
}

int main(void)
{
	scanf(" %d %d", &n, &m);
	int fx = -1, fy = -1, sx = -1, sy = -1;
	for(int i= 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'o')
			{
				if (fx == -1)
					fx = j, fy = i;
				else
					sx = j, sy = i;
				board[i][j] = '.';
			}
		}
	printf("%d", go(fx, fy, sx, sy, 0));
	return 0;
}