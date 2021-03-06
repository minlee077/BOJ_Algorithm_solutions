#include "pch.h"
/*
Problem
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

Output
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

Description
D[n] : n을 1,2,3의 합으로 나타내는 방법의 수
D[n] = D[n-1] + D[n-2] + D[n-3]

https://www.acmicpc.net/problem/9095
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n,cnt; 
	int memo[11];
	cin >> cnt;
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	while(cnt--)
	{
		cin >> n;
		for (int i = 3; i <= n; i++)
			memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
		cout << memo[n]<<'\n';
	}

	return 0;
}