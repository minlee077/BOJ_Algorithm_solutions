/*
Problem

N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 
칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

Input

첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

Output

첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.




Description

거리가 1인 그래프에서 최단 경로를 찾는 문제이다.

따라서, 이 문제는 BFS를 통해 해결할 수 있다.

또한, 입력을 그대로 matrix로 받아 그래프를 구축하지 않고도 경로 탐색이 가능하다.

누적하여 거리를 기록하기위해서는 dist[nx][ny] = dist[x]+1를 추가해주면 된다.

https://www.acmicpc.net/problem/2178

*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int dirx[] = { 0,0,-1,1 };
const int diry[] = { 1,-1,0,0 };


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >>N>> M;
	
	vector<vector<int>> maze(N, vector<int>(M));
	vector<vector<int>> check(N, vector<int>(M));

	for(int i= 0; i< N;i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &maze[i][j]);
	queue<pair<int,int>> q;
	q.push(make_pair<int, int>(0, 0));
	check[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = dirx[k] + x;
			int ny = diry[k] + y;
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (check[nx][ny] == 0 && maze[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y]+1;
				}
			}
		}
	}

	cout << check[N - 1][M - 1] << '\n';
	
	return 0;

}
