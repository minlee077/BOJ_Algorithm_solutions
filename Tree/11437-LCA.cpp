/*
Problem
N(2 ≤ N ≤ 50,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.

두 노드의 쌍 M(1 ≤ M ≤ 10,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.

Input
첫째 줄에 노드의 개수 N이 주어지고, 다음 N-1개 줄에는 트리 상에서 연결된 두 정점이 주어진다. 그 다음 줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 주어지고, 다음 M개 줄에는 정점 쌍이 주어진다.

Output
M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 공통 조상을 출력한다.

Description
LCA를 구하는 문제

https://www.acmicpc.net/problem/11437
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void initTree(vector<vector<int>> & edge, vector<pair<int,int>> & v, int n)
{
	/*
	v.first : depth
	v.second : parent
	*/
	v[1].first = 0;
	v[1].second = 0;
	vector <bool> check(n + 1, false);
	queue <int>q;
	q.push(1);
	check[1]=true;
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		for (int next : edge[now])
		{
			if (check[next]) continue;
			check[next] = true;
			v[next].first = v[now].first + 1;
			v[next].second = now;
			q.push(next);
		}
	}

}

int lca(int u, int v, vector<pair<int, int>>& vertex)
{
	if (vertex[u].first < vertex[v].first)
		swap(u, v);
	while (vertex[u].first != vertex[v].first)
		u = vertex[u].second; // find common depth
	while (u != v) // find common ancestor
	{
		u = vertex[u].second;
		v = vertex[v].second;
	}

	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector <vector<int>> edge (n + 1);
	for (int i = 0; i < n-1; i++)
	{
		int v1, v2;
		cin >> v1>> v2;
		edge[v1].push_back(v2);
		edge[v2].push_back(v1);
	}
	vector <pair<int, int>> vertex(n + 1); // depth, parent for tree structure
	initTree(edge, vertex,n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		cout << lca(u,v,vertex) << '\n';
	}
	return 0;
}
