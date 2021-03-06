#include "pch.h"
/*

Problem
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

Output
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

https://www.acmicpc.net/problem/11726

*/

#include <iostream>
using namespace std;

int memo[1001] = { 0, };

int twoNSquare(int n)
{
	if (n <= 1)
		return 1;
	if (memo[n]!=0)
		return memo[n];
	return memo[n] = (twoNSquare(n - 1) + twoNSquare(n - 2))%10007;
}


int main(void)
{
	int n; 
	cin >> n;
	memo[0]=1, memo[1] = 1;
	cout << twoNSquare(n)<<'\n';
	return 0;
}