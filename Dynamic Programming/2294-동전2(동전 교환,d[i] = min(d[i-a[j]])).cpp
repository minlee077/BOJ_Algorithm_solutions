/*
Problem
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

Input
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다.

Output
첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 작다.

Description
동전교환 문제로, 1, 2, 3 더하기 4 와 비슷한 유형의 문제이다.

d[i] : 가치의 합이 i원일때 사용된 동전의 최소 개수
동전의 가치가 a1, a2, a3, ..., an 일때,
d[i] = min(d[i-a1], d[i-a2], d[i-a3], ..., d[i-an] ) +1

https://www.acmicpc.net/problem/2294

*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k; 
	cin >> n>>k;
	vector<int> coins(n);
	vector<int> ans(k+1, -1);
	for (int i = 0; i < n; i++)
		cin >> coins[i];

	ans[0] = 0;

	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i <= k; i++)
		{
			if (i-coins[j] < 0 || ans[i - coins[j]] == -1) continue;
			if (ans[i] == -1|| ans[i] > ans[i - coins[j]] + 1)
				ans[i] = ans[i - coins[j]] + 1;
		}
	}
	cout << ans[k];

	return 0;
}