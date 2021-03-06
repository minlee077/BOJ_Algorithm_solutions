/*
Problem
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

1 i v : Ai를 v로 바꾼다.
2 i j : Ai, Ai+1, ..., Aj에서 가장 크기가 작은 값을 출력한다.
수열의 인덱스는 1부터 시작한다.


Input
첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)

넷째 줄부터 M개의 줄에는 쿼리가 주어진다.

Output
2번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.


Description

초기화 : O(NlogN)
쿼리 : O(logN)
변경 : O(logN)

https://www.acmicpc.net/problem/14438
*/
#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>

using namespace std;

void init(vector<int> &tree, vector<int> &a, int nodeIdx, int start, int end) // O(nlogn)
{
	if (start == end)
		tree[nodeIdx] =a[start];
	else
	{
		init(tree, a, nodeIdx * 2, start, (start + end) / 2);
		init(tree, a, nodeIdx * 2 + 1, (start + end) / 2 + 1, end);
		tree[nodeIdx] = min(tree[nodeIdx * 2], tree[nodeIdx * 2 + 1]);
	}
}

int segQuery(vector<int>&tree, int nodeIdx, int start, int end, int i, int j) // O(log(n))
{
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[nodeIdx];

	int left = segQuery(tree, nodeIdx * 2, start, (start + end) / 2, i, j);
	int right= segQuery(tree, nodeIdx * 2+1, (start+end)/2+1,  end,i, j);
	if (left == -1)
		return right;
	else if (right == -1)
		return left;
	else
		return min(left, right);
}

void updateTree(vector<int> &tree, int nodeIdx, int start, int end, int goal, int val) // O(log(n))
{
	if (goal < start || goal > end) return;
	if (start == end)
	{
		tree[nodeIdx] = val;
		return;
	}
	updateTree(tree, nodeIdx * 2, start, (start + end) / 2, goal, val);
	updateTree(tree, nodeIdx * 2+1, (start+end)/2+1, end, goal, val);
	tree[nodeIdx] = min(tree[nodeIdx * 2], tree[nodeIdx * 2 + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n ;

	vector <int> a(n+1);
	for (int i = 1; i <= n; i++)
		cin >>a[i];
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	cin >> m;
	init(tree, a, 1, 1, n);
	for (int k = 0; k < m; k++)
	{
		int option;
		cin >> option;
		int i, j;
		cin >> i >> j;
		switch (option)
		{
		case 1:
			updateTree(tree, 1, 1, n , i , j);
			break;
		case 2:
			cout << segQuery(tree, 1, 1, n , i, j ) << '\n';
			break;
		}

	}
	return 0;
}