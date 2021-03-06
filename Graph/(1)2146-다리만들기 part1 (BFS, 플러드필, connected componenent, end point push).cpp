#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
여러 섬으로 이루어진 나라가 있다.
이 나라의 대통령은, 섬들을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다. 
하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다. 
그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.

이 나라는 N×N크기의 이차원 평면상에 존재한다. 
이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다.
다음은 세 개의 섬으로 이루어진 나라의 지도이다.

위의 그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다.
이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다. 
가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다. 
다음 그림에서 두 대륙을 연결하는 다리를 볼 수 있다.

물론 위의 방법 외에도 다리를 놓는 방법이 여러 가지 있으나, 위의 경우가 놓는 다리의 길이가 3으로 가장 짧다(물론 길이가 3인 다른 다리를 놓을 수 있는 방법도 몇 가지 있다).

지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.

Input

첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다. 
그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다.
항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.

Output
첫째 줄에 가장 짧은 다리의 길이를 출력한다.

Description
플러드필 문제이다.
Connected component와 dists정보를 같이 갱신하며 모든 섬의 점에서 BFS를 수행해야한다.

먼저, connected component 파악을 위해 BFS를 진행하고, 이때, 섬의 끝점을 큐에 넣어준다.


https://www.acmicpc.net/problem/2146

*/

#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1};

int map[100][100];
int party[100][100];
int dist[100][100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >>N;
	queue <pair<int, int>> dq;
	for(int i =0; i<N;i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if(map[i][j]==1)
				dist[i][j] =1;
		}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (party[i][j] == 0 && dist[i][j] == 1)
			{
				queue<pair<int, int>> gq;
				gq.push(make_pair(i, j));
				party[i][j] = ++cnt;

				while (!gq.empty())
				{
					int nowx=gq.front().first;
					int nowy=gq.front().second;
					gq.pop();
					bool flag = true;
					for (int k = 0; k < 4; k++)
					{
						int nextx = nowx + dx[k];
						int nexty = nowy + dy[k];
						if (0 <= nextx && nextx < N && 0 <= nexty && nexty < N)
						{
							if (party[nextx][nexty] == 0)
							{
								if (dist[nextx][nexty] == 1)
								{
									party[nextx][nexty] = cnt;
									gq.push(make_pair(nextx, nexty));
								}
								else if (dist[nextx][nexty] == 0 && flag)
								{
									dq.push(make_pair(nowx, nowy));
									flag = false;
								}
							}
						}
					}
				}
			}
		}

	cout << endl;

	for(int i= 0;i<N;i++)
	{
		for (int j =0; j < N; j++)
			cout << party[i][j] << " ";
		cout << endl;
	}
	while (!dq.empty())
	{
		cout << dq.front().first +1 << " ";
		cout << dq.front().second +1<< endl;
		dq.pop();
	}




	return 0;
}
