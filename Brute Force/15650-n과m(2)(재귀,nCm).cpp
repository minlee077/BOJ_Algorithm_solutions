/*
Problem

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.

Input

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

Output

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description
재귀 함수를 통해 nCm을 구현하여 접근할 수 있다.
index는 오름 차순으로 접근하기 위해 수열에 포함되는지 아닌지를 결정하기 위해 설정한다.

https://www.acmicpc.net/problem/15650

*/
#include <iostream>

using namespace std;

int present[9];

void go(int index, int selected,int n, int  m)
{
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
			cout << present[i] << ' ';
		cout << '\n';
		return;
	}
	if (index >= n) return;
	present[selected] = index + 1;
	go(index + 1, selected + 1, n, m);
	present[selected] = 0;
	go(index + 1, selected, n, m);

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;



	return 0;
}