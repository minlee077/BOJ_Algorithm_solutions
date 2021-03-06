/*
Problem
알고스팟 운영진이 모두 미로에 갇혔다. 미로는 N*M 크기이며, 총 1*1크기의 방으로 이루어져 있다. 미로는 빈 방 또는 벽으로 이루어져 있고, 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.

알고스팟 운영진은 여러명이지만, 항상 모두 같은 방에 있어야 한다. 즉, 여러 명이 다른 방에 있을 수는 없다. 어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다. 즉, 현재 운영진이 (x, y)에 있을 때, 이동할 수 있는 방은 (x+1, y), (x, y+1), (x-1, y), (x, y-1) 이다. 단, 미로의 밖으로 이동 할 수는 없다.

벽은 평소에는 이동할 수 없지만, 알고스팟의 무기 AOJ를 이용해 벽을 부수어 버릴 수 있다. 벽을 부수면, 빈 방과 동일한 방으로 변한다.

만약 이 문제가 알고스팟에 있다면, 운영진들은 궁극의 무기 sudo를 이용해 벽을 한 번에 다 없애버릴 수 있지만, 안타깝게도 이 문제는 Baekjoon Online Judge에 수록되어 있기 때문에, sudo를 사용할 수 없다.

현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.

Input
첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다. 0은 빈 방을 의미하고, 1은 벽을 의미한다.

(1, 1)과 (N, M)은 항상 뚫려있다.

Output
첫째 줄에 알고스팟 운영진이 (N, M)으로 이동하기 위해 벽을 최소 몇 개 부수어야 하는지 출력한다.

Description
벽을 부수지 않는 상황을 거리가 0이라고 가정하면, 거리가 0과 1인 BFS문제가 된다.
덱을 사용하여, 거리가 0이라면 front에 push해서 해결하면 된다.

https://www.acmicpc.net/problem/1261
*/
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int main(){
	int dist[101][101];
	int _map[101][101];
	memset(dist, -1, sizeof(dist));
	deque <pair<int,int>> dq;
	int n, m;
	scanf(" %d %d",&n,&m);

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf(" %1d", &_map[i][j]);

	dist[1][1] = 0;
	dq.push_back(make_pair(1,1));
	while (!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		if (x == m && y==n)
			break;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (nx < 1 || nx > m || ny <1 || ny >n)
				continue;

			if(dist[nx][ny]==-1)
				if (_map[nx][ny] == 0)
				{
					dq.push_front(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y];
				}
				else
				{
					dq.push_back(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
				}
		}
	}

	printf("%d", dist[m][n]);

	return 0;
}