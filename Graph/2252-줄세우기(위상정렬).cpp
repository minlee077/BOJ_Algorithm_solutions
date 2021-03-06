/*
Problem

N명의 학생들을 키 순서대로 줄을 세우려고 한다. 
각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다.
그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

Input
첫째 줄에 N(1≤N≤32,000), M(1≤M≤100,000)이 주어진다.
M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 
이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

Output
첫째 줄에 N(1≤N≤32,000), M(1≤M≤100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

Description
모든 학생들을 정점으로 취급하면, DAG가 된다.
따라서, 위상정렬을 통해 순서를 생성해야한다.


https://www.acmicpc.net/problem/2252
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> stu(n+1);
	vector<int> indeg(n+1, 0);
	for (int i = 0; i < m; i++)
	{
		int src, dst;
		cin >> src >> dst;
		stu[src].push_back(dst);
		indeg[dst]+=1;
	}

	queue <int> q;
	for (int i = 1; i <=n; i++)
	{
		if (indeg[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		cout << now << ' ';
		int _size= stu[now].size();
		for (int k = 0; k < _size; k++)
		{
			int dst = stu[now][k];
			indeg[dst]-=1;
			if (indeg[dst] == 0)
				q.push(dst);
		}
	}

	return 0;
}