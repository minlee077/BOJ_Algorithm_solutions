/*
Problem
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 숫자를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 

단, 숫자는 한 개 이상 선택해야 한다. 또, 수열에서 수를 하나 제거할 수 있다. (제거하지 않아도 된다)

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 수를 제거하지 않았을 때의 정답은 12+21인 33이 정답이 된다.

만약, -35를 제거한다면, 수열은 10, -4, 3, 1, 5, 6, 12, 21, -1이 되고, 여기서 정답은 10-4+3+1+5+6+12+21인 54가 된다.


Input
첫째 줄에 정수 n(1≤n≤100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.


Output
첫째 줄에 답을 출력한다.



Description
D[N][0] : N을 마지막수로 하는 MSA의 최댓값
D[N][1] : 어떤수 x가 지워지거나 안지워진 N을 마지막수로 하는 MSA의 최댓값

D[N][0] = max( D[N-1][0]+A[N], A[N])
D[N][1] = max(D[N-1][0], D[N-1][1] + A[N], 0, A[N])

D[1][0]=A[1]
D[1][1]=max(A[1],0)

위는 잘못된 풀이

D[N][0] : 왼쪽부터 합산한 N을 마지막 수로하는 MSA
D[N][1] : 오른쪽부터 합산한 N을 마지막 수로하는MSA

D[k] : 어떤수 k을 제거했을때, 최댓값

D[k] = max((D[k-1][0] + D[k-1][1]), D[k-1][0])

D[k-1][0]은 단순히 생각하면, 수를 안지웠을때라고 생각하면 된다.


https://www.acmicpc.net/problem/13398

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

	int n;
	cin >> n;
	vector <int>A(n + 1);
	vector <int>Dx(n + 1);
	vector <int>Dy(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> A[i];

	Dx[1] = A[1];

	for(int i = 2; i <= n; i++)
		Dx[i] = max(Dx[i - 1] + A[i], A[i]);

	Dy[n] = A[n];
	for (int i = n-1; i >= 1; i--)
		Dy[i] = max(Dy[i + 1] + A[i], A[i]);

	int maxval = max(-1001, Dx[1]);
	for (int i = 2; i <= n; i++)
		if (maxval < Dx[i])
			maxval = Dx[i];
	for (int i = 2; i <= n-1; i++)
	{
		if (maxval < Dy[i + 1] + Dx[i - 1])
			maxval = Dy[i + 1] + Dx[i - 1];
	}
	cout << maxval;

	return 0;
}