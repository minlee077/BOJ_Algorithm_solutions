/*
Problem
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
Input
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

Output
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

Description
거리가 1과 0으로된 그래프에서 최단거리를 탐색하는 bfs문제이다.
0으로 된 거리를 처리하기 위해 큐를 두 개 사용하여, 현재큐와 다음큐를 나눠서 수행하겠다.
만약 탐색된 다음 노드가 거리가 0이라면 현재 큐에 추가할 것이고, 다음 노드의 거리가 1이라면 다음큐에 추가할 것이다.

https://www.acmicpc.net/problem/13549
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dist[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int> now;
	queue<int> next;

	memset(dist, -1, sizeof(dist));
	int n, k;
	cin >> n >> k;

	dist[n] = 0;

	now.push(n);
	while (dist[k] == -1)
	{
		while (!now.empty())
		{
			int npos = now.front(); now.pop();
			if (npos <= 50000)
				if (dist[npos * 2] == -1)
				{
					dist[npos * 2] = dist[npos];
					now.push(npos * 2);
				}
			if (npos == k)
				break;

			if (dist[npos + 1] == -1)
			{
				dist[npos + 1] = dist[npos] + 1;
				next.push(npos + 1);
			}
			if (dist[npos - 1] == -1)
			{
				dist[npos - 1] = dist[npos] + 1;
				next.push(npos - 1);
			}

		}
		now = next;
		next =queue <int> ();
	}
	
	cout << dist[k];

	return 0;
}