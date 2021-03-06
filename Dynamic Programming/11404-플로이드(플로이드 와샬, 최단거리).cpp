/*
Problem
n(1 ≤ n ≤ 100)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 각 버스는 한 번 사용할 때 필요한 비용이 있다.

모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.

Input
첫째 줄에 도시의 개수 n(1 ≤ n ≤ 100)이 주어지고 둘째 줄에는 버스의 개수 m(1 ≤ m ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.

시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

Output
N개의 줄을 출력해야 한다. i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다. 만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.

Description
도시는 그래프상의 노드, 버스가 이동하는 경로는 그래프의 엣지로 모델링 할 수 있다.
각 노드에서 임의의 노드로 가는 최단거리를 적재하기 위해서는 플로이드 와샬 알고리즘을 사용하는 것이 효율적이다.

D[i][j] : i에서 j로 가는 최단거리
D[i][j] = min(D[i][k] + D[k][j])

https://www.acmicpc.net/problem/11404
*/

#include <iostream>
#include <vector>

#define INF 9999999

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
		if(costs[src][dst] > co)
			costs[src][dst] = co;
	}

	for (int k = 1; k <= n; k++)
		for(int i = 1; i<=n;i++)
			for (int j = 1; j <= n ;j++)
			{
				if (costs[i][j] < costs[i][k] + costs[k][j])
					continue;
				costs[i][j] = costs[i][k] + costs[k][j];
			}

	for (int i =1 ; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (costs[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << costs[i][j] << ' ';

		}
		cout << '\n';

	}


	return 0;
}