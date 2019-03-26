/*
Problem:
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

Input:
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다.

Output:
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

Description:
수에 대한 쿼리가 빈번하게 일어나므로, 정렬을 수행하고 이후에 이진탐색을 통해 빠르게 접근하는 것이 유리하다.

정렬 복잡도 : NlogN
탐색 복잡도 : logN
탐색 횟수 : M

O(NM(logN)^2)

*/

#include iostream
#include algorithm

using namespace std;

int a[100000];
int ms[100000];
int n, m;

int _bsearch(int k)
{
	int low = 0;
	int high = n - 1;
	while (low = high)
	{
		int mid = (low + high)  2;
		if (a[mid] == k) return 1;
		else if (a[mid]  k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
int main(void)
{
	ios_basesync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin  n;

	for (int i = 0; i  n; i++)
		cin  a[i];
	cin  m;
	for (int i = 0; i  m; i++)
		cin  ms[i];

	sort(a, a + n);

	for(int i=0; im; i++)
		cout_bsearch(ms[i])'n';
}