#include "pch.h"
/*
Problem
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

Input
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.


Output
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.


Description
D[N][i]=D[N-1][i+1] + D[N-1][i-1]

N범위 1~100
초깃값, D[1][i] = 1

예외처리 사항 
1. i = 0, i = 9 
D[N][0] = D[N-1][1]
D[N][9] = D[N-1][8]

2. D[1][0] = 0


*/
#include <iostream>
#include <vector>
using namespace std;


long long int D [101][10];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	D[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		D[1][i] = 1;

	for (int n = 2; n <= N; n++)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (i == 0)
			{
				D[n][i] = D[n - 1][1]% 1000000000;
				continue;
			}
			if (i == 9)
			{
				D[n][i] = D[n - 1][8]% 1000000000;
				continue;
			}
			D[n][i] = (D[n - 1][i + 1]% 1000000000 + D[n - 1][i - 1]% 1000000000)%1000000000;
		}
	}
	int sum=0;
	for (int i = 0; i <= 9; i++)
		sum = (sum + D[N][i])% 1000000000;
	cout << sum << '\n';
	
	return 0;
}