/*
Problem
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 

그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

Input
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

Output
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.


Description
N제한이 매우 작다.
또한, 모든 상태를 정의하기가 어렵다. 그래프로 풀기에는 출발점이 무수히 많고, 상태 변화는 한번만 발생하므로 올바른 해결책이 아니다.
브루트 포스가 이 문제의 접근법으로 바람직해 보인다.
먼저 사탕을 교환하는 경우를 생각해보면, 모든 행에서 좌우 교환은 행마다 n번일어나므로, 좌우 교환은 총 n^2의 경우의 수가 있다.
상하 교환은 열마다 n번일어나므로, 상하교환도 총 n^2의 경우의 수가 있다.
따라서, 모든 상태 변화에 대한 경우의 수는 총 2*n^2이다.
마지막으로, 점수를 확인하기 위한 작업은 매행, 매열을 모두 확인하게 되므로, 2n^2이 소요된다.

따라서, 브루트포스로 모든 경우의 수를 산정하게 된다면, 총 (2n^2) * (2n^2)의 복잡도로 n이 최대 50이므로, 약 250000번의 연산 내로 해결이 가능하므로, 적합한 접근법으로 보인다.
O(n^4)


https://www.acmicpc.net/problem/3085
*/
#include <iostream>

using namespace std;

char mat[50][50];
int n;

int score(void)
{
	int max = 1;

	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n-1; j++)
		{
			if (mat[i][j] == mat[i][j + 1])
				cnt++;
			else
			{
				cnt =1;
			}
			if (max < cnt)
				max = cnt;
		}

		cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (mat[j][i] == mat[j + 1][i])
				cnt++;
			else
			{
				cnt = 1;
			}
			if (max < cnt)
				max = cnt;
		}
	}
	return max;
}

int main(void)
{
/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
*/
	scanf(" %d",&n);

	for(int i = 0; i<n ; i++)
		for (int j = 0; j < n; j++)
		{
			scanf(" %c", &mat[i][j]);
		}

	int max = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			char temp = mat[i][j];
			mat[i][j] = mat[i][j + 1];
			mat[i][j + 1] = temp;

			cnt = score();
			if (max < cnt)
				max = cnt;

			temp = mat[i][j];
			mat[i][j] = mat[i][j + 1];
			mat[i][j + 1] = temp;
		}

		for (int j = 0; j < n - 1; j++)
		{
			char temp = mat[j][i];
			mat[j][i] = mat[j+1][i];
			mat[j+1][i] = temp;

			cnt = score();
			if (max < cnt)
				max = cnt;

			temp = mat[j][i];
			mat[j][i] = mat[j + 1][i];
			mat[j + 1][i] = temp;

		}
	}

	cout << max;
		
	return 0;
}