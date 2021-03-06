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

같은 자리에 중복을 위해서는 동일 위치에 중복된 할당이 언제 되는지를 파악해야한다.

재귀 함수호출방식을 생각해보면, 하나의 인덱스를 체우기 위해서 한번의 함수가 호출된다.

결국, 같은 위치에 인덱스에 중복된 값이 오게 되는 경우는 for문에서 입력받은 array인덱스를 접근할때 발생하는 것이다.

입력된 array는 정렬이된 상태로 접근하므로, 중복된 항복이 발생할때도, 순차적으로 접근할때 발생한다.

따라서, for문을 순회할때, 이전에 해당위치에 할당했던 정보를 저장하여, 중복된 할당(이는 곧 동일한 함수 호출로 이어짐)을 사전에 차단하면 된다.


https://www.acmicpc.net/problem/15663
*/
#include <iostream>
#include <algorithm>

using namespace std;

int nArr[9];
bool check[9];
int mOut[9];

void go(int mIdx, int n, int m)
{
	if (mIdx == m)
	{
		for (int i = 0; i < m; i++)
			cout << mOut[i] << ' ';
		cout << '\n';
		return;
	}
	int before = 0;
	for (int i = 0; i < n; i++)
	{
		if (check[i] == true || before==nArr[i]) continue;
		check[i] = true;
		mOut[mIdx] = nArr[i];
		before = nArr[i];
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

	return 0;
}