/*
Problem
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이가 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

Output
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.

Description
한번 입력 받은 카드는 추가 및 삭제가 발생하지 않고 카드에 대한 탐색이 반복적으로 일어나게 되므로, 정렬 후에 이분 탐색을 활용하는 것이 적절하다.

https://www.acmicpc.net/problem/10815
*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int binsearch(int left, int right, int dst, vector<int>&cards)
{
	int mid = (left + right) / 2;
	if (left > right) return 0;
	if (cards[mid] == dst) return 1;
	if (cards[mid] > dst)
		return binsearch(left, mid - 1, dst, cards);
	else
		return binsearch(mid + 1, right, dst, cards);
}
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
		cout << binsearch(0,n-1,checkList[i],cards) << ' ';

	return 0;
}