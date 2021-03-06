/*
Problem
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

Input
첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

Output
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.


Description
D[N][k] : N을 k개의 정수의 조합의 합으로 나타낼 수 있는 모든 경우의 수

N =  ... + p
N = ( ... = N-p, k-1개) + p
D[N][k] = ∑(D[N-p][k-1])

D[i][j] = ∑(D[i-p][j-1])

조건
0<=p<=N

모든경우의수는 N*K*(N-k+1)
복잡도가 약 O(N^2k)로, 800만 이하로 해볼만한 시도이다.

*/
#include <iostream>

using namespace std;

long long int D[201][201];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k;
	cin >> N >> k;

	D[0][0] = 1;

	for (int i = 0; i <= N; i++)
		for (int j = 1; j <= k; j++)
			for (int p = 0; p <= i; p++)
			{
				D[i][j] += D[i - p][j - 1];
				D[i][j] %= 1000000000;
			}

	cout << D[N][k];
	return 0;
}