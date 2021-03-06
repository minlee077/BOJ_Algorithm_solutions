/*
Problem
1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 다음에 오는 순열을 구하는 프로그램을 작성하시오.

사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.

N = 3인 경우에 사전순으로 순열을 나열하면 다음과 같다.

1, 2, 3
1, 3, 2
2, 1, 3
2, 3, 1
3, 1, 2
3, 2, 1

Input
첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄에 순열이 주어진다.

Output
첫째 줄에 입력으로 주어진 순열의 다음에 오는 순열을 출력한다. 만약, 사전순으로 마지막에 오는 순열인 경우에는 -1을 출력한다.

Description
1. A[i-1] < A[i]를 만족하는 가장 큰 i를 찾음 ( 뒤에서 부터 순차적으로 내림차순이 위배되는 순간을 찾음 ).
2. A[j] > A[i-1]를 만족하는 가장 큰 j를 찾음 ( 뒤에서 부터 순차적으로 내림차순에 포함되지 않은 i-1을 기준으로, A[i-1]보다 큰 값의 위치를 찾음
3. A[i-1]과 A[j] swap
4. A[i] ~ A[n]의 순열을 뒤집음

https://www.acmicpc.net/problem/10972
*/
#include <iostream>

using namespace std;

int status[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> status[i];

	int incPos = n;
	while (incPos!=1)
	{
		if (status[incPos - 1] > status[incPos])
		{
			incPos--;
		}
		else
			break;
	}
	if (incPos == 1)
	{
		cout << -1;
		return 0;
	}
	int swapPoint;
	for (int j = n; j >= incPos; j--)
	{
		if (status[incPos - 1] < status[j])
		{
			swapPoint = j;
			break;
		}
	}

	int temp = status[incPos - 1];
	status[incPos - 1] = status[swapPoint];
	status[swapPoint] = temp;

	for (int i = n, j = incPos; i >j ; i--, j++)
	{
		int temp = status[i];
		status[i] = status[j];
		status[j] = temp;
	}

	for (int i = 1; i <= n; i++)
		cout << status[i] << " ";

	return 0;
}