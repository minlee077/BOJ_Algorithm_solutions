/*
Problem
N개의 에너지 구슬이 일렬로 놓여져 있고, 에너지 구슬을 이용해서 에너지를 모으려고 한다.

i번째 에너지 구슬의 무게는 Wi이고, 에너지를 모으는 방법은 다음과 같으며, 반복해서 사용할 수 있다.

에너지 구슬 하나를 고른다. 고른 에너지 구슬의 번호를 x라고 한다. 단, 첫 번째와 마지막 에너지 구슬은 고를 수 없다.
x번째 에너지 구슬을 제거한다.
Wx-1 × Wx+1의 에너지를 모을 수 있다.
N을 1 감소시키고, 에너지 구슬을 1번부터 N번까지로 다시 번호를 매긴다. 번호는 첫 구슬이 1번, 다음 구슬이 2번, ... 과 같이 매겨야 한다.
N과 에너지 구슬의 무게가 주어졌을 때, 모을 수 있는 에너지 양의 최댓값을 구하는 프로그램을 작성하시오.

Input
첫째 줄에 에너지 구슬의 개수 N(3 ≤ N ≤ 10)이 주어진다.

둘째 줄에는 에너지 구슬의 무게 W1, W2, ..., WN을 공백으로 구분해 주어진다. (1 ≤ Wi ≤ 1,000)

Output
첫째 줄에 모을 수 있는 에너지의 최댓값을 출력한다.


Description
N제한이 10이하이므로, 각 구슬을 제거해보는 모든 경우를 테스트해보면 된다.
매 스테이지마다 하나씩 지워보는 경우의 수 이므로 (N-2)!의 경우의수를 수행해보게 된다.
또한, 각 과정에서 배열의 요소를 삭제하고 인덱스를 다시 부여하는 작업으로인해, 매 과정에서 N의 복잡도가 요구된다.
따라서, N*(N-2)!의 복잡도를 가진다.

https://www.acmicpc.net/problem/16198
*/

#include <iostream>

using namespace std;

int w[11];

int ecalc(int energy, int n)
{
	if (n == 2) return energy;
	int _max = 0;
	
	for (int k = 1; k < n-1; k++)
	{
		int temp = w[k];
		for (int i = 0; i < n - k; i++)
			w[k + i] = w[k + i + 1];
		int now = ecalc(w[k-1] * w[k],n-1) + energy;
		for (int i = n-1; i >= k; i--)
			w[i] = w[i-1];
		w[k] = temp;
		if (now > _max)
			_max = now;
	}
	return _max;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	cout << ecalc(0, n) << '\n';

	return 0;
}
