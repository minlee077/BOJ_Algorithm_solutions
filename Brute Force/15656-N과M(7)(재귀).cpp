/*
Problem
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

Input
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

Output

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description
for문에서 재귀함수를 호출할때, 오름차순으로 호출하게 된다.

https://www.acmicpc.net/problem/15656
*/
#include <iostream>
#include <algorithm>

using namespace std;

int present[9];
int inputAry[9];

void go(int index,  int n, int  m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << present[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		present[index] = inputAry[i];
		go(index + 1, n, m);
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
		cin >> inputAry[i];
	sort(inputAry, inputAry + n);

	go(0, n, m);

	return 0;
}