/*

Problem
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

Input
첫째 줄에 N(1≤N≤3^7, N은 3^k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

Output
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

Description
1. Divide
9개로 분할

2. Conquere
모두 같은 수 인지 확인
맞다면 해당수 count
아니라면 D&C()재귀

https://www.acmicpc.net/problem/1780

*/
#include <iostream>
#include <vector>

using namespace std;

int cnt[3];

bool _check(vector<vector<int>> & a, int x0, int y0, int x1, int y1)
{
	int val = a[x0][y0];
	for (int i = x0; i <= x1; i++)
	{
		for (int j = y0; j <= y1; j++)
		{
			if (val != a[i][j])
				return false;
		}
	}
	return true;
}

void solve(vector<vector<int>> & a, int x0, int y0, int x1, int y1)
{
	if (_check(a, x0, y0, x1, y1))
	{
		cnt[a[x0][y0] + 1]++;
		return;
	}

	int ratio = (x1-x0 + 1) / 3;

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			solve(a, x0 + ratio * i, y0 + ratio * j, x1 - ratio * (2 - i), y1 - ratio * (2 - j));
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<vector<int>> a (n,vector<int>(n,0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	
	solve(a, 0,0,n-1,n-1);

	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';

	return 0;
}