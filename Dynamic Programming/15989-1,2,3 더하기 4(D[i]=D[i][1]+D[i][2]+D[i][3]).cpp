/*
Problem
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 4가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다. 합을 이루고 있는 수의 순서만 다른 것은 같은 것으로 친다.

1+1+1+1
2+1+1 (1+1+2, 1+2+1)
2+2
1+3 (3+1)
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 10,000보다 작거나 같다.

Output
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

Description
각 수의 등장 순서를 고려하지 않고 경우의 수를 찾아야한다.

숫자들의 등장 순서를 고정하고 진행하면 된다.

가령, 1이 등장할 횟수를 정해주고, 2가 등장할 횟수, 3이 등장할 횟수와 같이 순차적으로 계산해 주면된다.
즉, 오름차순으로 숫자가 등장한다고 하자.

D[i][j] : 합이 i이고 마지막에 등장한 수가 j인 경우의수
D[i][1] = D[i-1][1]
D[i][2] = D[i-2][2] + D[i-1][1]
D[i][3] = D[i-3][3] + D[i-3][2] + D[i-3][1]

D[i] = D[i][1] + D[i][2] + D[i][3]

https://www.acmicpc.net/problem/15989
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T,n; 
	cin >> T;
	

	vector<vector<int>> d(10001, vector<int>(4, -1));

	d[1][1] = 1;
	d[1][2] = 0;
	d[1][3] = 0;
	d[2][2] = 1;
	d[3][3] = 1;

	for (int i = 2; i <= 10000; i++)
	{
		d[i][1] = d[i-1][1];
		if (i > 2)
			d[i][2] = d[i-2][2] + d[i-2][1];
		if (i > 3)
			d[i][3] = d[i - 3][3] + d[i - 3][2] + d[i - 3][1];
	}

	while (T--)
	{	
		cin >> n;
		cout << d[n][3]+ d[n][2] + d[n][1]<<'\n';
	}

	return 0;
}