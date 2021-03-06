#include "pch.h"
/*
Problem
0과 1로만 이루어진 수를 이진수라 한다. 이러한 이진수 중 특별한 성질을 갖는 것들이 있는데, 이들을 이친수(pinary number)라 한다. 이친수는 다음의 성질을 만족한다.

-이친수는 0으로 시작하지 않는다.
-이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.

예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다. 하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.

N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 N이 주어진다.

Output
첫째 줄에 N자리 이친수의 개수를 출력한다.



Description
마지막 수가 무엇인지에 따라 케이스를 나눠 1차원 배열로 해결이 가능하다.
D[N] : 길이가 N이고, 시작이 1인 이친수 
마지막수 0 : xxxx....(1or0) 0 => D[n-1]
마지막수 0 : xxxx....(1or0) 0 1 => D[n-2]
D[N] = D[N-1] + D[N-2]


*/
#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int D[91] = { 0, };
	
	D[0] = 0;
	D[1] = 1;
	int n;
	cin >> n;
	for (int N = 2; N <= n; N++)
	{
		D[N] = D[N - 1]+D[N-2];
	}

	cout << D[n] << '\n';
	
	return 0;
}