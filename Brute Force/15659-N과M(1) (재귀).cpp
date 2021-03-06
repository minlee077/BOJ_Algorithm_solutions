/*
Problem
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

Input

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)


Output
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description
재귀함수를 이용해 출력되어야 하는 칸을 채워나가는 방식을 구현할 수 있다.

https://www.acmicpc.net/problem/15649

*/
#include <iostream>

using namespace std;

bool check[9];
int present[9];

void go(int index, int n, int  m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << present[i]<<' ';
		cout << '\n';
		return;
	}
		
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == true)
			continue;
		check[i] = true;
		present[index] = i;
		go(index + 1, n,m);
		check[i] = false;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	go(0,n,m);

	return 0;
}