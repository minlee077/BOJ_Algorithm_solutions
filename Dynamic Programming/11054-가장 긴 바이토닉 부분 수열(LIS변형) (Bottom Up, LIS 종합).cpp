/*
Problem
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

Output
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

Description
LIS 문제의 변형이다.
특정 위치에 수에 대해 왼쪽으로는 증가하는 수열을 정의할 수 있고,
오른쪽으로는 감소하는 수열을 정의할 수 있다

D[i] = i를 기준으로 왼쪽으로는 증가수열이고, 오른쪽으로는 감소수열인 가장 긴 바이토닉 부분 수열의 길이

L[i] = i를 마지막 수로 하는 가장 긴 증가수열의 길이
R[i] = i를 시작으로 하는 가장 긴 감소하는 수열의 길이

D[i] = L[i] + R[i]

L[i]를 초기화하고, R[i]를 초기화한 후에 
둘의 합을 D[i]에 할당하고, maxD[i]를 찾으면 답이 도출된다.


L을 구하는 방법 기존 LIS 문제와동일

초깃값 
L[1] = 1

조건
A[i] > A[j] 
L[i] < L[j]

R을 구하는 방법 감소하는 LIS 문제와 동일

이번풀이에서는 부호반전없이 역순으로 접근하여 LIS와 동일하게 처리했다

차이점은 역순접근과, A[i]<A[j]

https://www.acmicpc.net/problem/11722

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	vector <int> A(T + 1);
	vector <int> L(T + 1);
	vector <int> R(T + 1);
	for (int i = 1; i <= T; i++)
		cin >> A[i];


	L[1] = 1;

	for (int i = 2; i <= T; i++)
	{
		for (int j = i - 1; j > 0; j--)
			if (A[i] > A[j] && L[i] <= L[j])
				L[i] = L[j] + 1;
		if (L[i] == 0)
			L[i] = 1;
	}

	R[T] = 1;

	for (int i = T-1; i > 0; i--)
	{
		for (int j = i + 1; j <= T; j++)
			if (A[i] > A[j] && R[i] <= R[j])
				R[i] = R[j] + 1;
		if (R[i] == 0)
			R[i] = 1;
	}

		
	int max = 0;
	for (int i = 1; i <= T; i++)
		if (L[i] + R[i] > max)
			max = L[i] + R[i];
	cout << max - 1 << '\n';

	return 0;
}
