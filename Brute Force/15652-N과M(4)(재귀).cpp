/*
Problem

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

Input

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)


Output

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description
비내림차순의 성질을 유지하기 위해, 오름차순으로 출력하는 함수에서 조건을 이전과 같은 것이 와도 되게 구현하면된다.

https://www.acmicpc.net/problem/15652

*/
#include <iostream>

using namespace std;

int present[9];

void go(int selected, int before,int n, int  m)
{
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
			cout << present[i] << ' ';
		cout << '\n';
		return;
	}

	if (before > n) return;
	present[selected] = before;
	go(selected + 1, before, n, m);
	present[selected] = 0;
	go(selected, before + 1, n, m);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	go(0,1, n, m);

	return 0;
}