/*
Problem
n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 n(1≤n≤100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

Output
첫째 줄에 프리오더를 출력한다.

Description
Root를 preorder를 기준으로 탐색하면서 출력해야한다.

1. Divide
root 기준 left, right

2. Conquere
left에 대한 root 출력 
right에 대한 root 출력

주의 : inOrderPosition은 값이 1부터 주어지므로, 100000이 들어오올수도 있으므로, 사전에 배열의 크기를 n+1만큼 선언해둬야 한다.

https://www.acmicpc.net/problem/2263

*/

#include <iostream>

using namespace std;

int inOrd[100000];
int postOrd[100000];
int inOrdPos[100001]; // 주의

void solve(int inS, int inE, int posS, int posE)
{
	if (inS > inS || posS > posE) return;
	int root = postOrd[posE];
	cout << root << ' ';
	int inOrdRootPos = inOrdPos[root];
	int leftSize = inOrdRootPos - inS;

	solve(inS, inOrdRootPos- 1, posS, posS + leftSize - 1);
	solve(inOrdRootPos+1, inE, posS+leftSize, posE-1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> inOrd[i];
	for (int i = 0; i < n; i++)
		cin >> postOrd[i];

	for (int i = 0; i < n; i++)
		inOrdPos[inOrd[i]] = i; // inOrd값을 인덱스로 하는 위치에 inOrd의 인덱스 할당

	solve(0, n- 1, 0, n - 1);

	return 0;
}