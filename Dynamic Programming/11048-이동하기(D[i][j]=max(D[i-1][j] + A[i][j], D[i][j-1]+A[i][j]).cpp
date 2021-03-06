#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
준규는 N×M 크기의 미로에 갇혀있다. 미로는 1×1크기의 방으로 나누어져 있고, 각 방에는 사탕이 놓여져 있다. 미로의 가장 왼쪽 윗 방은 (1, 1)이고, 가장 오른쪽 아랫 방은 (N, M)이다.

준규는 현재 (1, 1)에 있고, (N, M)으로 이동하려고 한다. 준규가 (r, c)에 있으면, (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있고, 각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다. 또, 미로 밖으로 나갈 수는 없다.

준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최댓값을 구하시오.

Input
첫째 줄에 미로의 크기 N, M이 주어진다. (1 ≤ N, M ≤ 1,000)

둘째 줄부터 N개 줄에는 총 M개의 숫자가 주어지며, r번째 줄의 c번째 수는 (r, c)에 놓여져 있는 사탕의 개수이다. 사탕의 개수는 0보다 크거나 같고, 100보다 작거나 같다.

Output
첫째 줄에 준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수를 출력한다.

Description
D[i][j] : 준규가 (i,j)칸으로 이동할때 사탕의 최대 개수
이때, 각칸의 위치에서는 항상 최대 개수를 유지하므로, 최적화의 원칙에 부합함을 알 수 있다.
따라서, 다이나믹 프로그래밍으로 문제를 해결할 수 있고, 복잡도는 배열의 크기인 n^2이 된다.
특이한 점은 대각선 이동은 고려하지 않아도 된다. 
1	2
3	4
위의 총 네구역이 있을때, 1에서 4로 이동한다고 가정하면, 총 3가지의 경우가 나오게 된다.
1->4
1->2->4
1->3->4
2와 3칸에서 음수의 개수가 발생하지않고 0이상의 사탕이 존재하므로, 대각선이동보다 항상 우측이동과 아래방향 이동을 조합하는게 최대 값이 될 수 밖에 없다.

따라서, 대각이동을 무시한 점화식은 다음과 같이 정의 될 수 있다.
D[i+1][j] = max( D[i][j]+A[i+1][j], D[i+1][j-1]+A[i+1][j] )
-> D[i][j] = max(D[i-1][j] + A[i][j], D[i][j-1]+A[i][j] )
혹은 (두식은 동일)
D[i][j+1] = max( D[i][j]+A[i][j+1], D[i-1][j+1]+A[i][j+1] )
->D[i][j] = max(D[i][j-1]+A[i][j], D[i-1][j]+A[i][j])

https://www.acmicpc.net/problem/11048
*/
#include <iostream>
#include <vector>

#define _MAX(a,b) (a>b)? a : b

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> A(n,vector<int> (m));
	vector<vector<int>> D(n,vector<int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];
			if (i == 0 && j == 0)
				D[i][j] = A[i][j];
			else if (i == 0)
				D[i][j] = A[i][j] + D[i][j-1];
			else if(j==0)
				D[i][j] = A[i][j]+D[i-1][j];

		}

	for(int i =1 ;i<n; i++)
		for (int j = 1; j < m; j++)
		{
			D[i][j] = _MAX(D[i - 1][j] + A[i][j], D[i][j - 1] + A[i][j]);
		}

	cout << D[n-1][m-1];
		
	return 0;
}