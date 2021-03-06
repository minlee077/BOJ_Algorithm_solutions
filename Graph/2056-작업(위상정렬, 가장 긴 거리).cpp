/*
Problem
수행해야 할 작업 N개 (3 ≤ N ≤ 10000)가 있다. 각각의 작업마다 걸리는 시간(1 ≤ 시간 ≤ 100)이 정수로 주어진다.

몇몇 작업들 사이에는 선행 관계라는 게 있어서, 어떤 작업을 수행하기 위해 반드시 먼저 완료되어야 할 작업들이 있다. 
이 작업들은 번호가 아주 예쁘게 매겨져 있어서, K번 작업에 대해 선행 관계에 있는(즉, K번 작업을 시작하기 전에 반드시 먼저 완료되어야 하는) 작업들의 번호는 모두 1 이상 (K-1) 이하이다. 
작업들 중에는, 그것에 대해 선행 관계에 있는 작업이 하나도 없는 작업이 반드시 하나 이상 존재한다. (1번 작업이 항상 그러하다)

모든 작업을 완료하기 위해 필요한 최소 시간을 구하여라. 물론, 서로 선행 관계가 없는 작업들은 동시에 수행 가능하다.

Input
첫째 줄에 N이 주어진다.

두 번째 줄부터 N+1번째 줄까지 N개의 줄이 주어진다.
2번째 줄은 1번 작업, 3번째 줄은 2번 작업, ..., N+1번째 줄은 N번 작업을 각각 나타낸다. 
각 줄의 처음에는, 해당 작업에 걸리는 시간이 먼저 주어지고, 그 다음에 그 작업에 대해 선행 관계에 있는 작업들의 개수(0 ≤ 개수 ≤ 100)가 주어진다. 그리고 선행 관계에 있는 작업들의 번호가 주어진다.

Output
첫째 줄에 모든 작업을 완료하기 위한 최소 시간을 출력한다.

Description
문제 조건에 따르면, 모든 선행 관계가 없는 작업을 동시에 수행할 수 있으므로, 작업시간을 누적하여 오래걸리는 작업을 찾아내면 전체 작업에 소요되는 최단 시간이 도출된다.
이는 그래프의 임의의 정점 간에 최장 경로라고 생각할 수 있다.
시간을 갱신할때는 간선에 대해서 최대시간을 주는 간선의 누적 시간을 반영해야한다.

https://www.acmicpc.net/problem/2056
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> edge(n+1);
	vector<int> t(n+1);
	vector<int> sumT(n + 1);
	vector<int> ind(n+1);

	for (int i = 1; i <= n; i++)
	{
		int pre;
		cin >> t[i] >> pre;
		for (int j = 0; j < pre; j++)
		{
			int src;
			cin >> src;
			edge[src].push_back(i);
			ind[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
			sumT[i] = t[i];
		}
	}

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		int _size = edge[now].size();
		for(int k =0; k< _size; k++)
		{
			int next = edge[now][k];
			ind[next]--;
			if(t[next]+sumT[now] > sumT[next])
				sumT[next]= t[next] + sumT[now];
			if (ind[next] == 0)
				q.push(next);
		}
	}
	int _max = 0;
	for (int i = 1; i <= n; i++)
	{
		_max =max(_max, sumT[i]);
	}

	cout << _max;
	return 0;
}