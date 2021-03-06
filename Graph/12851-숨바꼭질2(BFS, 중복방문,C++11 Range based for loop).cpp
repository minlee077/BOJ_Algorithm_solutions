/*
Problem
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.

Input
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

Output
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에는 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수를 출력한다.

Description
BFS를 통해 목적지까지의 거리를 탐색하고 만약 찾게 된다면, 해당 라운드에서 같은 거리인것들을 카운트 하는 식으로 구현하면 된다.
주의할 점은 카운트시에는 1이 추가되는 것이아니라, now의 카운트를 더 해주어야 한다. 
왜냐하면, next가 i now가 j라고하면, i에서 j로 가는 방법은 i까지 오는 방법의 수와 동일하므로, 이와 같이 계산해야한다.
만약 카운트를 1로하게 되면 방문 정보를 없애줘야 하기 때문에 문제가 생긴다.

구현과정에서 C++11 range-based for-loop을 사용하였다.
https://www.acmicpc.net/problem/12851
*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dists[200001];
int cnts[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	memset(dists, -1, sizeof(dists));
	
	dists[n] = 0;
	cnts[n] = 1;
	queue <int> q;
	q.push(n);
	while (!q.empty())
	{
		int now = q.front(); q.pop();

		for (int next : {now+1, now-1, now*2})
			if (0 <= next && next < 200001)
			{
				if (dists[next] == -1)
				{
					dists[next] = dists[now] + 1;
					cnts[next] = cnts[now];
					q.push(next);
				}
				else if (dists[next] == dists[now] + 1)
					cnts[next] += cnts[now];
			}
	}
	cout << dists[k] << '\n';
	cout << cnts[k] << '\n';
	return 0;
}