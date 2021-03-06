/*
Problem
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

Input
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.


Output
첫째 줄에 답을 출력한다.

Description
MSA 문제
LIS와 유사하게, 마지막수가 어떤것 인가에 따라, 정의하면 문제가 해결된다.
D[i] : i를 마지막수로 가지는 연속합의 최댓값

D[i] = D[i-1] + A[i]

조건
D[i-1]>0

초깃값 
D[1] = A[1]
max = -1001

https://www.acmicpc.net/problem/1912

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
	for (int i = 1; i <= T; i++)
		cin >> A[i];

	D[1] = A[1];
	for (int i = 2; i <= T; i++)
		if (D[i - 1] > 0)
			D[i] = D[i - 1] + A[i];
		else
			D[i] = A[i];

	int max = -1001;
	for (int i = 1; i <= T; i++)
		if (max < D[i])
			max = D[i];

	cout << max << '\n';

	return 0;
}