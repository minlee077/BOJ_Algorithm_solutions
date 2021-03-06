/*
Problem
N의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 그러면 A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.

Input
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.

그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.

Output
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

Description
다익스트라 알고리즘을 활용하면 ElogE로 해결할 수 있다.

https://www.acmicpc.net/problem/1916
*/

#include <iostream>
#include <vector>

#define INF 999999999

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> costs(n + 1, vector<int>(n + 1,INF ));

	for (int i = 1; i <= n; i++)
		costs[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int src, dst, co;
		cin >> src >> dst >> co;
		if (costs[src][dst] > co)
			costs[src][dst] = co;
	}
	int src, dst;
	cin >> src >> dst;
	vector<int> dists(n + 1, INF);
	vector<bool> check(n + 1, false);

	dists[src] = 0;

	for (int k = 0; k < n - 1; k++) {
		
		int m = INF + 1;
		int x = -1;
		for (int i = 1; i <= n; i++) { // 거리가 최소인 미방문 인접 노드를 찾는과정
			if (check[i] == false && m > dists[i]) {
				m = dists[i];
				x = i;
			}
		}

		check[x] = true;
		for (int i = 1; i <= n; i++) {
			if (dists[i] > dists[x] + costs[x][i]) {
				dists[i] = dists[x] + costs[x][i];
			}
		}
	}

	cout<<dists[dst];

	return 0;
}