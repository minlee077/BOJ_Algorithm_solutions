/*
Problem
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

Input
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

Output
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.

Description
1. A[i-1] < A[i]를 만족하는 가장 큰 i를 찾음 ( 뒤에서 부터 순차적으로 내림차순이 위배되는 순간을 찾음 ).
2. A[j] > A[i-1]를 만족하는 가장 큰 j를 찾음 ( 뒤에서 부터 순차적으로 내림차순에 포함되지 않은 i-1을 기준으로, A[i-1]보다 큰 값의 위치를 찾음
3. A[i-1]과 A[j] swap
4. A[i] ~ A[n]의 순열을 뒤집음

nextPerm의 복잡도는 N으로, 각 N!개의 순열들을 얻기위해 nextPerm을 한번씩 호출하게 되므로, 복잡도는 O(N*N!)이다.

https://www.acmicpc.net/problem/10974
*/
#include <iostream>

using namespace std;

bool nextPerm(int * status, int n)
{
	int incPos = n;
	while (incPos != 1)
	{
		if (status[incPos - 1] > status[incPos])
			incPos--;
		else
			break;
	}
	if (incPos == 1)
		return false;
	
	int swapPoint;
	for (int j = n; j >= incPos; j--)
		if (status[incPos - 1] < status[j])
		{
			swapPoint = j;
			break;
		}

	int temp = status[incPos - 1];
	status[incPos - 1] = status[swapPoint];
	status[swapPoint] = temp;

	for (int i = n, j = incPos; i > j; i--, j++)
	{
		int temp = status[i];
		status[i] = status[j];
		status[j] = temp;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int status[9];
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		status[i] = i;
	
	do
	{
		for (int i = 1; i <= n; i++)
			cout << status[i] << " ";
		cout << '\n';
	} while (nextPerm(status,n));

	return 0;
}