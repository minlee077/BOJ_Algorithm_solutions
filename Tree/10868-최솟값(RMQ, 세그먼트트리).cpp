/*
Problem
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수를 찾는 것은 어려운 일이 아니다. 하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.

여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최솟값을 찾아야 한다. 각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.

Input
첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 주어진다.

Output
M개의 줄에 입력받은 순서대로 각 a, b에 대한 답을 출력한다.

Description
RMQ문제로, 세그먼트트리를 통해 수행할 수 있다.
초기화 : O(NlogN)
쿼리 : O(logN)

https://www.acmicpc.net/problem/10868
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

int segQuery(vector<int>&tree, int nodeIdx, int start, int end, int i, int j) // log(n)
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >>a[i];
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	init(tree, a, 1, 0, n-1);
	for (int k = 0; k < m; k++)
	{
		int i, j;
		cin >> i >> j;
		cout<<segQuery(tree, 1, 0, n-1, i-1, j-1)<<'\n';
	}


	return 0;
}