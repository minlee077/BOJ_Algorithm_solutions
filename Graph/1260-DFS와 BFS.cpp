/*
Problem
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

Input

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

Output
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.


Description
DFS의 경우, 함수 call stack을 활용하여 접근
BFS의 경우, queue를 이용하여, 순차적으로 접근

- 주의사항 
* 양방향이므로 간선 입력시에 두번 추가해줘야한다.
* 연결된 간선이 여러개일때, 낮은 정점부터 방문해야하므로, 각 인접리스트 벡터에 대해 정렬을 한번씩 수행해야한다.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <vector<int>> edges(1001);
vector <bool> check1(1001);
vector <bool> check2(1001);



void dfs(int x)
{
	check1[x] = true;
	cout << x << " ";

	int size = edges[x].size();
	for (int i = 0; i < size; i++)
	{
		int next = edges[x][i];
		if (check1[next]==false)
			dfs(next);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, V;
	cin >> N >> M>>V;

	int v1, v2;
	for (int i = 1; i <= M; i++)
	{
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);

	}
	for (int i = 1; i <= N; i++)
		sort(edges[i].begin(), edges[i].end());
	//DFS
	dfs(V);
	cout << '\n';

	//BFS
	queue <int> q;

	q.push(V);
	check2[V] = true;
	while (!q.empty())
	{
		int head = q.front();
		cout << head << " ";
		q.pop();
		
		int size = edges[head].size();
		for (int i = 0; i < size; i++)
		{
			int next = edges[head][i];
			if (check2[next] == false)
			{
				check2[next] = true;
				q.push(next);
			}
		}
	}

	return 0;
}