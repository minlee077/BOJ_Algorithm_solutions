/*
Problem
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

Input
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이가 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

Output
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.


Description
정렬 후 찾으려는 수에 대해 각수의 lower bound와 upper bound를 구해서 개수를 세면 된다.

https://www.acmicpc.net/problem/10816
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int>cards(n);

	for (int i = 0; i < n; i++)
		cin >> cards[i];
	sort(cards.begin(), cards.end());

	int m;
	cin >> m;
	vector <int> checkList(m);
	for (int i = 0; i < m; i++)
		cin >> checkList[i];

	for (int i = 0; i < m; i++)
	{
		int left = 0;
		int right = n-1;
		int lower=0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (cards[mid] == checkList[i])
			{
				lower = mid;
				right = mid - 1;
			}
			else if (cards[mid] > checkList[i])
				right = mid - 1;
			else
				left = mid + 1;

		}
		left = 0;
		right = n - 1;
		int upper= 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (cards[mid] == checkList[i])
			{
				upper = mid;
				left = mid + 1;
			}
			else if (cards[mid] > checkList[i])
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (upper - lower != 0)
			cout << upper - lower + 1 << ' ';
		else if (cards[upper] == checkList[i])
			cout << 1 << ' ';
		else
			cout << 0<<' ';

	}

	return 0;
}

