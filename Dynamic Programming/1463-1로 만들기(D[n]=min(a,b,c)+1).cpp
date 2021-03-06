/*
Problem
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

Input
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

Output
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

Description
D[n] : n을 1로 만들기 위한 최소 연산횟수
D[n] = min(D[n-1], D[n/2], D[n/3]) +1

https://www.acmicpc.net/problem/1463
*/

#include <iostream>
#include <algorithm>

using namespace std;

int D[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	D[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		D[i] = D[i - 1] +1;
		if (i % 2 == 0)
			D[i]=min(D[i / 2]+1, D[i]);
		if (i % 3 == 0)
			D[i] = min(D[i / 3]+1, D[i]);
	}
	cout << D[n];
}