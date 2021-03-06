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
0으로 된 거리를 처리하기 위해 덱을 활용하겠다.
거리가 1인경우에는 push_back 하지만, 거리가 0인경우에는 push_front하여, 거리가 0인 것에 우선순위를 주어 탐색하게 한다.

https://www.acmicpc.net/problem/13549
*/
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int dist[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque <int> dq;
	int n, k;
	cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	dist[n] = 0;
	dq.push_back(n);
	while (!dq.empty())
	{
		int now = dq.front(); dq.pop_front();
		if (now == k)
			break;

		if (now <= 50000)
			if (dist[now * 2] == -1)
			{
				dq.push_front(now * 2);
				dist[now * 2] = dist[now];
			}
		if (dist[now + 1] == -1)
		{
			dq.push_back(now + 1);
			dist[now + 1] = dist[now] + 1;
		}
		if (dist[now - 1 ]== -1)
		{
			dq.push_back(now - 1);
			dist[now - 1] = dist[now] + 1;
		}

	}
	cout << dist[k];
	return 0;
}