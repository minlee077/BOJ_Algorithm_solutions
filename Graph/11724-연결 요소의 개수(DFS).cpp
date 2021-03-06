/*
Problem
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.



Input

첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 
같은 간선은 한 번만 주어진다.

Output
첫째 줄에 연결 요소의 개수를 출력한다.


Description
연결요소를 확인하기 위해선 BFS나 DFS 방식을 통해서 확인해야한다.
이 코드에선 DFS로 탐색을 수행해보겠다.

https://www.acmicpc.net/problem/11724

*/
#include <iostream>
#include <vector>

using namespace std;

vector <bool> check1(1001);
vector <vector<int>> edges(1001);

void dfs(int x)
{
	check1[x] = true;
	int size = edges[x].size();
	for (int i = 0; i < size; i++)
	{
		int next = edges[x][i];
		if (check1[next] == false)
		{
			dfs(next);
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nodes, numOfedges;
	cin >> nodes >> numOfedges;


	int tempNode1, tempNode2;
	for (int i = 1; i <= numOfedges; i++)
	{
		cin >> tempNode1 >> tempNode2;
		edges[tempNode1].push_back(tempNode2);
		edges[tempNode2].push_back(tempNode1);
	}
	int connectedComponet = 0;
	for (int i = 1; i<=nodes; i++)
	{
		if (check1[i] == false)
		{
			dfs(i);
			connectedComponet++;
		}
	}

	cout << connectedComponet;

	return 0;
}