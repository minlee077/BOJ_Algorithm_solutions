/*
Problem
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 1000000보다 작거나 같다.

Output
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

Description
D[n] : n을 1,2,3의 합으로 나타내는 방법의 수
D[n] = D[n-1] + D[n-2] + D[n-3]
테스트 케이스 정수 n이 매우 클 수 있으므로, 매 케이스 n마다 memo를 초기화 해주는 것은 불필요한 연산을 포함하게 된다.
따라서, memo를 미리 다 초기화 해주는 것이 복잡도를 낮추는 방법이 될 수 있다.

https://www.acmicpc.net/problem/15988
*/
#include <iostream>

using namespace std;

long long int D[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n;
	cin >> t;

	D[0] = 1;
	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= 1000000; i++)
		D[i] = (D[i - 1]+ D[i-2]  +D[i-3] ) % 1000000009;

	while (t--)
	{
		cin >> n;
		cout << D[n] << '\n';
	}
}