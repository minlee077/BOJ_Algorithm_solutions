/*
Problem

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

Input

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

Output

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description
중복이 가능하므로, 문제 조건에 맞게 오름차순으로 재귀함수를 호출하면 된다.

https://www.acmicpc.net/problem/15651

*/
#include <iostream>

using namespace std;

int present[9];

void go(int selected,int n, int  m)
{
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
			cout << present[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		present[selected] = i;
		go(selected + 1, n, m);
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	go(0, n, m);

	return 0;
}