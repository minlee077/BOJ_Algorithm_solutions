#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

Input

첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

Output

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description

이전호출에서 어떤 수를 마지막으로 사용했는지를 parameter로 전달하여 비내림 차순을 유지한다.

또한, for문 내에서 중복된 재귀함수 호출을 막기위해 before를 통해 검증을 하고 진행한다.

https://www.acmicpc.net/problem/15666

*/
#include <iostream>
#include <algorithm>

using namespace std;

int nArr[9];
bool check[9];
int mOut[9];

void go(int mIdx,int last,int n, int m)
{
	if (mIdx == m)
	{
		for (int i = 0; i < m; i++)
			cout << mOut[i] << ' ';
		cout << '\n';
		return;
	}

	int before = 0;
	for (int i = last; i < n; i++)
	{
		if (before==nArr[i]) continue;
		mOut[mIdx] = nArr[i];
		before = nArr[i];
		go(mIdx + 1,i,n, m);

	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> nArr[i];
	sort(nArr, nArr + n);
	go(0,0,n, m);

	return 0;
}