/*
Problem
옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.

길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

S = A[0]*B[0] + ... + A[N-1]*B[N-1]

S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안된다.

S의 최솟값을 출력하는 프로그램을 작성하시오.

Input
첫째 줄에 N이 주어진다. 둘째 줄에는 A에 있는 N개의 수가 순서대로 주어지고, 셋째 줄에는 B에 있는 수가 순서대로 주어진다. N은 50보다 작거나 같은 자연수이고, A와 B의 각 원소는 100보다 작거나 같은 음이 아닌 정수이다.

Output
첫째 줄에 S의 최솟값을 출력한다.

Description
A배열과 B배열의 원소간 곱을 구해야한다.
S의 최솟값을 출력할때, A의 위치를 재배열할 수 있으면, 결과적으로 B의 위치를 재배열하지 못하더라도 B를 재배열해도 같은 결과가 도출된다.
따라서, A배열과 B배열은 오름차순으로 정렬되어 있다고 가정하자.
n=2일때,
A[0]= a, A[1]= a + b
B[0]= c, B[1]= c + d
(a,b,c,d ≥ 0)

A[0]*B[0] + A[1]*B[1] = ac + ac + ad + bc + bd  ... (0)
A[0]*B[1] + A[1]*B[0] = ac + ad + ac + bc  ... (1)
(0) - (1) = bd ≥ 0

마찬가지로, n개의 배열에서 각각의 곱은 큰수는 작은수와의 곱을 취하고 작은수는 큰수와의 곱을 취하는 것이 최소가 되는 값이 도출된다.

https://www.acmicpc.net/problem/1026
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	
	vector<int> A (n);
	vector<int> B (n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	
	for (int j = 0; j < n; j++)
	{
		int t;
		cin >> t;
		B[j] = -t;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += A[i] * B[i];
	
	cout << -ans << '\n';

	return 0;
}