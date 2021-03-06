/*
Problem
N개의 정수로 이루어진 집합이 있을 때, 이 집합의 공집합이 아닌 부분집합 중에서 그 집합의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1≤N≤20, |S|≤1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 
주어지는 정수의 절댓값은 100,000을 넘지 않는다. 같은 수가 여러 번 주어질 수도 있다.

Output
첫째 줄에 합이 S가 되는 부분집합의 개수를 출력한다.

Description
브루트포스를 통해 각 원소가 포함되는 경우와 포함되지 않는 경우를 산정하면, 2^n의 경우의 수가 나온다.
정답이 되는 상황은 idx가 n번째 항에 도달 했을때 누적 sum이 s와 같을때 이다.
정답이 되지 않는 상황은 n까지 도달했는데 sum이 s가 아닐때이다.

주의해야할 상황은 공집합의 경우 누적 sum이 0이 된다.
이로인해, s=0인 상황을 답으로 구해야할 경우에는 공집합도 n=0,s=0으로 같이 카운팅 된다.
이때문에, 예외적으로 s=0인 상황에 대해서는 count에서 1을 차감해주어야 한다.ㅁ

https://www.acmicpc.net/problem/1182

*/
#include <iostream>
#include<algorithm>

using namespace std;

int arr[21];
int n, s, cnt;
void go(int idx, int sum)
{
	if (idx == n)
	{
		if(sum ==s)
			cnt++;

		return;
	}
	go(idx + 1, sum + arr[idx]);
	go(idx + 1, sum);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	go(0, 0);
	if (s == 0)
		cnt--;
	cout << cnt<<'\n';

	return 0;
}