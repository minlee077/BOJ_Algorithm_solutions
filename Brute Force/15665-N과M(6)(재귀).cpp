/*
Problem

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열

Input

첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

Output

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description

입력수치가 각기 다르므로, 입력을 모두 받은 후에 정렬을 시행하고 인덱스를 기준으로 오름차순으로 출력하면 된다.

입력되는 수가 모두 다른 수 이므로, 중복을 생각하진 않아도 된다.


https://www.acmicpc.net/problem/15665
*/
#include <iostream>
#include <algorithm>

using namespace std;

int present[9];
int inputAry[9];
bool check[9];

void go(int index,int before, int n, int  m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << present[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = before; i < n; i++)
	{
		if (check[i] == true) continue;

		present[index] = inputAry[i];
		check[i] = true;
		go(index + 1, i,n, m);
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
	for (int i = 0; i < n; i++)
		cin >> inputAry[i];
	sort(inputAry,inputAry + n);
	
	go(0, 0,n, m);

	return 0;
}