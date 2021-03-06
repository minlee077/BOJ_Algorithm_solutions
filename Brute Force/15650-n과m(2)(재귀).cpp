#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.

Input

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

Output

각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

Description

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.


https://www.acmicpc.net/problem/15650

*/
#include <iostream>

using namespace std;

bool used[9];
int output[9];
void go(int index,int n,int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << output[i]<<' ';
		cout << '\n';
	}
	int k = 0;
	if(index>0)
		k = output[index - 1];
	for(int i = k; i < n; i++)
	{
			used[i] = true;
			output[index] = i+1;
			go(index + 1, n, m);
			used[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n>>m;

	go(0,n, m);

	return 0;
}