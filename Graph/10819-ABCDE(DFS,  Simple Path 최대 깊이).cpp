/*
Problem
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|


Input
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 
둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 
배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.


Output
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

Description

입력의 N제한이 최대 8이므로, 모든 순열을 브루트포스 방식으로 수행할 수 있다.

pair를 사용해서 임의의 index를 부여해서 사전순으로 접근하거나,

주어진 입력값을 sort하고, 기존의 것을 그대로 사용하여, 사전순으로 접근할 수도 있을 것이다.

주어진 순열의 길이가 3~8로 sort에 아주 적은 연산이 요구되므로, sort를 하고 접근하는 것이 바람직하다.


https://www.acmicpc.net/problem/10819

*/
#include <iostream>
#include<algorithm>

using namespace std;

void swap(int*pos1, int *pos2)
{
	int temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}
bool nextPerm(int * perm, int n)
{
	int incPos = 1;
	for (int i = n; i > 0; i--)
		if (perm[i - 1] < perm[i])
		{
			incPos = i;
			break;
		}
	if (incPos == 1)
		return false;
	int swapPoint;
	for (int i = n; i >= incPos; i--)
		if (perm[i] > perm[incPos - 1])
		{
			swapPoint = i;
			break;
		}
	swap(&perm[swapPoint], &perm[incPos - 1]);

	for (int i = incPos, j = n; i < j; i++, j--)
		swap(&perm[i], &perm[j]);
	return true;
}

int calc(int * perm, int n)
{
	int sum = 0;
	for (int i = 1; i <= n - 1; i++)
		sum+=abs(perm[i] - perm[i + 1]);
	return sum;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int perm[9] = { 0, };
	for (int i = 1; i <= n; i++)
		cin >> perm[i];

	sort(&perm[1], &perm[n+1]);

	int maxVal = 0;
	do {
		int sum = calc(perm,n);
		if (maxVal < sum)
			maxVal = sum;
	} while (nextPerm(perm,n));
	
	cout << maxVal;
	return 0;
}
