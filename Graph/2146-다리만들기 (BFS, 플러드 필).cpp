/*
Problem
여러 섬으로 이루어진 나라가 있다. 이 나라의 대통령은, 섬들을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다. 하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다. 그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.

이 나라는 N×N크기의 이차원 평면상에 존재한다. 이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다. 다음은 세 개의 섬으로 이루어진 나라의 지도이다.

위의 그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다. 이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다. 가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다. 다음 그림에서 두 대륙을 연결하는 다리를 볼 수 있다.

물론 위의 방법 외에도 다리를 놓는 방법이 여러 가지 있으나, 위의 경우가 놓는 다리의 길이가 3으로 가장 짧다(물론 길이가 3인 다른 다리를 놓을 수 있는 방법도 몇 가지 있다).

지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.

Input
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다. 그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다. 항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.

Output
첫째 줄에 가장 짧은 다리의 길이를 출력한다.


Description
connected component를 파악한 후에, bfs를 통해 플러드필을 수행하며, 다른 그룹간에 접점이 생기는 순간에 거리를 기록한다.

https://www.acmicpc.net/problem/2146
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> map(n + 1, vector<int>(n + 1));
	vector<vector<int>> dists(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
		cin >> map[i][j];
		if (map[i][j] == 1)
			dists[i][j] = 0;

		else
			dists[i][j] = -1;
		}

	}
	vector<vector<int>> group(n + 1, vector<int>(n + 1));

	//bfs group initialize, 
	int groupNum=0;
	queue <pair<int, int>> ffq;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dists[i][j] == 0 && group[i][j] == 0)
			{
				group[i][j] = ++groupNum;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				ffq.push(make_pair(i, j));

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 < nx && nx <= n && 0 < ny && ny <= n)
						{
							if (group[nx][ny] == 0 && dists[nx][ny] == 0)
							{
								group[nx][ny] = groupNum;
								q.push(make_pair(nx, ny));
								ffq.push(make_pair(nx, ny));

							}

						}
					}
				}
			}
		}
	}
	
	int ans = 9999;
	//Flood fill
	while(!ffq.empty())
	{
		int x = ffq.front().first;
		int y = ffq.front().second;
		int g = group[x][y];
		ffq.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 < nx && nx <= n && 0 < ny && ny <= n)
			{
				int ng = group[nx][ny];
				if (dists[nx][ny] == -1)
				{
					dists[nx][ny] = dists[x][y] + 1;
					group[nx][ny] = g;
					ffq.push(make_pair(nx, ny));
				}
				else if (g != ng)
				{
					ans=min(ans, dists[nx][ny] + dists[x][y]);

				}
				
			}
		}
	}
	cout << ans << '\n';
	return 0;
}