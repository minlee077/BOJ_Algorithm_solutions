/*
Problem

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열

Input

첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

Output

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

Description

초기 배열에 중복이 포함되어 있으므로, 출력시에 중복된 출력이 되지 않게 유의 해야한다.

아래의 코드에서는 출력대상들을 모두 산정하고, sort후에 중복된 출력을 제거하는 방식으로 접근하였다.


https://www.acmicpc.net/problem/15663
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nArr[9];
bool check[9];
int mOut[9];
vector<vector<int>> finalOut;


void go(int mIdx, int n, int m)
{
	if (mIdx == m)
	{
		vector<int> temp;
		for (int i = 0; i < m; i++)
			temp.push_back(mOut[i]);
		finalOut.push_back(temp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] == true) continue;
		check[i] = true;
		mOut[mIdx] = nArr[i];
		go(mIdx + 1, n, m);
		check[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> nArr[i];
	sort(nArr, nArr + n);
	go(0, n, m);

	sort(finalOut.begin(), finalOut.end());
	int size = finalOut.size();
	for (int j = 0; j < m; j++)
		cout << finalOut[0][j] << ' ';
	cout << '\n';

	for (int i = 1; i < size; i++)
	{
		if (finalOut[i] == finalOut[i - 1]) continue;
		for (int j = 0; j < m; j++)
			cout<<finalOut[i][j]<<' ';
		cout << '\n';
	}

	return 0;
}