/*
Problem
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

이를 사전순으로 정렬하면 다음과 같이 된다.

1+1+1+1
1+1+2
1+2+1
1+3
2+1+1
2+2
3+1

Input
첫째 줄에 정수 n과 k가 주어진다. n은 양수이며 11보다 작고, k는 2^(31-1)보다 작거나 같은 자연수이다.

Output
n을 1, 2, 3의 합으로 나타내는 방법 중에서 사전 순으로 k번째에 오는 것을 출력한다. k번째 오는 식이 없는 경우에는 -1을 출력한다.

Description
D[n] : n을 1,2,3의 합으로 나타내는 방법의 수
D[n] = D[n-1] + D[n-2] + D[n-3]
삼진탐색으로 하나씩 queue에 넣으면서 최종 결과 단에서 출력


https://www.acmicpc.net/problem/12101
*/
#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
int memo[11];
int k;

int triSearch(int n, int start)
{
	if (n == 0) return 0;
	if (start < k && k <= memo[n - 1] + start)
	{

		q.push(1);
		return triSearch(n - 1, start);
	}
	else if (start + memo[n - 1] < k && k <= start + memo[n - 1] + memo[n - 2])
	{
		q.push(2);
		return triSearch(n - 2, start + memo[n - 1]);
	}
	else if (start + memo[n - 2] + memo[n - 1] < k)
	{
		q.push(3);
		return triSearch(n - 3, start + memo[n - 2] + memo[n - 1]);
	}
	else
		return 0;
}
int main(void)
{
	int n;

	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	for (int i = 3; i <= 10; i++)
		memo[i] = (memo[i - 1] + memo[i - 2] + memo[i - 3]);
	cin >> n >> k;
	if (memo[n] < k)
	{
		cout << "-1" << '\n';
		return 0;
	}

	triSearch(n, 0);
	cout << q.front();
	q.pop();
	while (!q.empty())
	{
		cout << "+"<< q.front();
		q.pop();
	}
	return 0;
}