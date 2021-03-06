#include "pch.h"
/*
Problem
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.



Input
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)



Output
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.



Description
주어진 구간에서 소수를 찾을때 만약 각각의 수에 대해 검증을한다면, 아무리 낮아도 O(N√N)의 복잡도가 요구된다.
일단 각각의 수를 탐색해야하므로, N의 복잡도는 소요될 수 밖에 없다.
에라토네스의 채를 활용하면, 이를 급격히 낮출 수 있다. 에라토네스의 채를 통해 초기화하게 된다면, 전체를 훑는데 N, 배수를 제거해주는 작업에서 loglogN의 복잡도가 들어가므로,
O(NloglogN)으로 낮출 수 있다.

https://www.acmicpc.net/problem/1929
*/
#include <iostream>
#include <queue>
using namespace std;


int check[1000001];
int main(void)
{
	int m, n;
	cin >> m >> n;
	queue <int>prime;
	check[0] = check[1] = true;
	for (int i = 2; i <= 1000000; i++)
		if (check[i] == false)
			for (int j = i + i; j <= 1000000; j += i)
				check[j] = true;

	for (int i = m; i <= n; i++)
		if (check[i] == false)
			cout << i << '\n';

	return 0;
}