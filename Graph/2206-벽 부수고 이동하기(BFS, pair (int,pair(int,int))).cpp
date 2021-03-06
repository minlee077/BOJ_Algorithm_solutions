/*
Problem
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

Input
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다.
다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

Output
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

Description
맵을 이동하면서, 벽을 한번 부순경우에는로 이동하고[i][j][1] 부수지 않은 상태에서는 [i][j][0]으로 이동하는 식으로 구현하면, 최단 경로를 구할 수 있다.

https://www.acmicpc.net/problem/2206
*/

#include <iostream>
#include <queue>

using namespace std;

int _map[1000][1000];
int dists[1000][1000][2];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int main() {
	int n, m;
	scanf(" %d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %1d", &_map[i][j]);
		
	queue<pair<int,pair<int,int>>> q;

	dists[0][0][0] = 1;
	q.push(make_pair(0,make_pair(0, 0)));

	while (!q.empty())
	{
		int _break = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (y == n - 1 && x == m - 1) break;
		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n)
			{
				if (_map[ny][nx] == 0 && dists[ny][nx][_break] == 0)
				{
					dists[ny][nx][_break] = dists[y][x][_break]+1;
					q.push(make_pair(_break, make_pair(ny, nx)));
				}
				else if (_break == 0 && _map[ny][nx] == 1 && dists[ny][nx][1] == 0)
				{
					dists[ny][nx][1] = dists[y][x][_break]+1;
					q.push(make_pair(1, make_pair(ny, nx)));
				}
			}
		}
	}
	int d = (dists[n-1][m-1][0] > dists[n-1][m-1][1]) ? dists[n-1][m-1][0] : dists[n-1][m-1][1];
	if (d == 0)d = -1;
	cout << d << '\n';
	return 0;
}