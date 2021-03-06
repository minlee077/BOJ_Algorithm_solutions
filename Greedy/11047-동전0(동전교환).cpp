#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

Input
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

Output
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

Description
 화폐간에 배수관계가 성립하므로, 높은 금액의 거스름돈부터 최대한 많이 주는 그리디 방식으로 접근하면, 이를 통해 도출되는 solution은 global solution이 된다.

https://www.acmicpc.net/problem/11047

*/
#include <iostream>
#include <algorithm>

using namespace std;

int values[11];
int n;
int k;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> values[i];
	int coins = 0;

	do {
		coins += k / values[n];
		k %= values[n];
	} while (--n || k != 0);
	cout << coins;
	return 0;
}