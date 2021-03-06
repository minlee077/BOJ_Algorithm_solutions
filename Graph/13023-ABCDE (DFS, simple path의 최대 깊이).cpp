/*
Problem
BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.

오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.

A는 B와 친구다.
B는 C와 친구다.
C는 D와 친구다.
D는 E와 친구다.
위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

Input
첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.

둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

Output
문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.

Description
그래프의 단순 경로의 깊이가 5가 되는 것이 있는 지를 찾는 문제이다.
DFS를 통해 깊이가 5가 되는 것을 찾아야 한다.
단, 주의할 점은 dfs후 함수 콜 스택에 의해 회귀할때 기존의 방문점을 미방문점으로 다시 바꿔줘야 한다.
왜냐하면, 출발점이 A이고
A-B-C-D-E-F,
A-E-Z-G-Q-B의 간선들이 있을때,
A-B-C-D-E-F를 먼저 DFS로 탐색하게되면, A-E-Z-G-Q-B-C-D-E-F의 경로를 얻을 수 가 없게 된다.
따라서, 최대 깊이를 알 수가 없다.
결국 더 이상 나아갈 길이 없는 지점에서는 방문 정보를 미방문으로 처리해야 한다.

https://www.acmicpc.net/problem/13023
*/
#include<iostream>
#include<vector>
#include <cstring>

using namespace std;

vector<int> g[2001];
int dist[2001];

int dfs(int now)
{
	int adjSize=g[now].size();
	if (dist[now] == 5)
	{
		cout << 1;
		return 0;
	}
	for (int i = 0; i < adjSize; i++)
	{
		int next = g[now][i];

		if (dist[next] == 0)
		{
			dist[next] = dist[now] + 1;
			if (dfs(next) == 0)
				return 0;
		}
	}
	dist[now] = 0;
	return 1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	
	for (int i = 1; i <= m; i++)
	{

		if (g[i].size() == 0)
			continue;
		
		dist[i] = 1;
		if (dfs(i) == 0)
			return 0;

		memset(dist, 0, sizeof(dist));
	}
	cout << 0;
	return 0;
}