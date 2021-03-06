/*
Problem
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.



Input

입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K(2≤K≤5)가 주어진다. 
각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)가 빈 칸을 사이에 두고 순서대로 주어진다. 
각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 
이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호가 빈 칸을 사이에 두고 주어진다.

Output
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.


Description
이분그래프를 확인하기 위해서는 그래프를 BFS나 DFS를 통해 검증해야한다.
방법은 매 인접 정점 방문시에 flag를 바꿔주며, 검증하면 된다.

BFS로 해당 코드를 구현하겠다.

탐색 과정에서 특정 vertex가 어느 partition에 있는지를 확정할 수 없다.
따라서, flag값을 사용하여 접근한다.
우선, 탐색알고리즘 특성상, 하나의 정점에 대해 connected component간에만 탐색이 가능하다.
따라서, 모든 정점에 대해 기존에 bfs로 탐색을 했던 component에 있던 정점인지를 확인해야한다.

두번째로, 실제로는 유향 그래프이지만, 무향 그래프로 저장을 해야 bipartite에 대한 올바른 탐색이 가능하다.



https://www.acmicpc.net/problem/1707

*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector <vector<int>> edges(20001);
bool check[20001];
int flag[20001];

bool bfsBp(int x)
{
	queue <int> q;
	q.push(x);
	check[x] = true;

	while (!q.empty())
	{
		int vert = q.front(); q.pop();

		int size = edges[vert].size();
		for (int i = 0; i < size; i++)
		{
			int next = edges[vert][i];
			if (flag[next] == flag[vert])
				return false;
			if (next == vert)
				return false;
			if(check[next] ==false)
			{
				flag[next] = -flag[vert];
				q.push(next);
				check[next] = true;
			}
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		int nofverts, nofedges;
		cin >> nofverts >> nofedges;
		int tempV1, tempV2;

		for (int i = 1; i <= nofedges; i++)
		{
			cin >> tempV1>>tempV2;
			edges[tempV1].push_back(tempV2);
			edges[tempV2].push_back(tempV1);

		}
		for (int i = 1; i <= nofverts; i++)
		{
			if (check[i] == false)
			{
				flag[i] = 1;
				if (bfsBp(i) == false)
				{
					cout << "NO" << '\n';
					break;
				}
			}
			if (i == nofverts)
				cout << "YES" << '\n';
		}
		if (T != 0)
		{
			edges.clear();
			edges.resize(20001);
			memset(check, false, sizeof(check));
			memset(flag, 0, sizeof(flag));
		}
	}
	return 0;
}