/*
Problem
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.

보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.

하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.

철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라.

단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

Input
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다.
M은 상자의 가로 칸의 수, N 은 상자의 세로 칸의 수를 나타낸다.
단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다.
즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다.
정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

Output

여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다.
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.



Description

방법 1

플러드필 문제로, 거리가 1이며, 인접한것을 상하좌우로 하는 문제이다.

특징은, 모든 connected component들에 대해 조사를 해야하며, 각각의 원소에는 날짜가 저장되어야한다.

BFS를 진행하게 될때 마다, 날짜를 1일로 집어넣어서 진행하면 된다.

이 과정에서, 각각의 1의 위치별로 BFS를 수행하게 된다.

만약 사전에 연산된 거리가 다른 위치의 토마토에서 새로이 진행한 거리보다 짧다면, 거리를 갱신 해주는 방식으로 접근

초기에 입력을 그대로 matrix에 저장하여 진행하면 된다.

이 방식으로 수행하니 시간초과가 발생함

원인은 1의 개수만큼 bfs를 진행하다보니, 불필요한 연산이 지나치게 많아지는 것에 있다.

즉, connected component에서 1의 개수만큼 bfs가 발생하므로 문제가 되었다.

방법 2

초기화 과정에서 1인 component를 미리 queue에 push해주고, 전체 bfs과정을 한번에 수행하면, 훨씬 빠른 속도로 접근이 가능해진다.

풀이에선 방법2를 기준으로 한다.

https://www.acmicpc.net/problem/7576
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dirx[] = { 0,0,-1,1 };
const int diry[] = { 1,-1,0,0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, N;
	cin >> M >> N;
	vector<vector<int>> tomato(N, vector<int>(M));
	vector<vector<int>> date(N, vector<int>(M));
	
	queue <pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] != 0)
			{
				date[i][j] = tomato[i][j];
				if (tomato[i][j] == 1)
					q.push(make_pair(i, j));
			}
		}

	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dirx[k];
			int ny = y + diry[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (date[nx][ny] == -1)
				continue;
				if (date[nx][ny] == 0 || date[nx][ny] > date[x][y] + 1)
				{
					q.push(make_pair(nx, ny));
					date[nx][ny] = date[x][y] + 1;
				}
			}
		}
	}


	int max = 0;
	int min = N * M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (date[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (date[i][j] > max)
				max = date[i][j];
		}

	cout << max - 1;
	return 0;

}

