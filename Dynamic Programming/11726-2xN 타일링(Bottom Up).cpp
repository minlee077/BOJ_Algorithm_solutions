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
int main(void)
{
	int n; 
	cin >> n;
	int memo[1001];
	memo[0] = 1 , memo[1] = 1;
	for (int k = 2; k <= n; k++)
		memo[k] = (memo[k - 1] + memo[k - 2])%10007;
	cout << memo[n] << '\n';
	return 0;
}