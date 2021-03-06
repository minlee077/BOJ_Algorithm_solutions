/*

Problem
정렬되어있는 두 배열 A와 B가 주어진다. 
두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

Input
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)
둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

Output
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.

Description
머지소트에서 merge부분에 대한 구현

https://www.acmicpc.net/problem/11728

*/
#include <iostream>
#include <vector>

using namespace std;

void _merge(vector<int> &a, vector<int>& b,int n, int m)
{
	int i = 0, j = 0;
	while (i < n  && j < m)
	{
		if (a[i] > b[j])
		{
			cout << b[j] << ' ';
			j++;
		}
		else
		{
			cout << a[i] << ' ';
			i++;
		}
	}

	if (n == i)
	{
		while (j < m)
		{
			cout << b[j] << ' ';
			j++;
		}
	}
	else
	{
		while (i < n)
		{
			cout << a[i] << ' ';
			i++;
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a (n);
	vector<int> b (m);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	_merge(a, b, n, m);

	return 0;
}