/*
Problem
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 2, 50, 60} 이고, 합은 113이다.

Input
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

Output
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

Description
LIS 문제의 변형이다.
감소식이나 최솟값의 접근법
1. 부호 반전후 일반적인 문제와 동일풀이
2. DATA MAX value로 초기화하고 뒤에서부터 접근

해당문제는 부호 반전을 시행하면, LIS 문제와 동일하게 해결이 가능

점화식
D[i] : i를 마지막항으로하는 가장 긴 증가하는 부분수열
D[i] = max (D[j]) +1( for all possible j )

초깃값 
D[1] = 1
조건
A[i]>A[j] 
D[i] < D[j]

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
	vector <int> D(T + 1);
	int temp;
	for (int i = 1; i <= T; i++)
	{
		cin >> temp;
		A[i] = -temp;
	}


	D[1] = 1;

	for (int i = 2; i <= T; i++)
	{
		for (int j = i - 1; j > 0; j--)
			if (A[i] > A[j] && D[i] <= D[j])
				D[i] = D[j] + 1;
		if (D[i] == 0)
			D[i] = 1;
	}
		
	int max = 0;
	for (int i = 1; i <= T; i++)
		if (D[i] > max)
			max = D[i];
	cout << max << '\n';

	return 0;
}
