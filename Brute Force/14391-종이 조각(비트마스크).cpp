/*
Problem
영선이는 숫자가 쓰여 있는 직사각형 종이를 가지고 있다. 종이는 1×1 크기의 정사각형 칸으로 나누어져 있고, 숫자는 각 칸에 하나씩 쓰여 있다. 
행은 위에서부터 아래까지 번호가 매겨져 있고, 열은 왼쪽부터 오른쪽까지 번호가 매겨져 있다.

영선이는 직사각형을 겹치지 않는 조각으로 자르려고 한다. 각 조각은 크기가 세로나 가로 크기가 1인 직사각형 모양이다. 
길이가 N인 조각은 N자리 수로 나타낼 수 있다. 가로 조각은 왼쪽부터 오른쪽까지 수를 이어 붙인 것이고, 세로 조각은 위에서부터 아래까지 수를 이어붙인 것이다.

아래 그림은 4×4 크기의 종이를 자른 한 가지 방법이다.

각 조각의 합은 493 + 7160 + 23 + 58 + 9 + 45 + 91 = 7879 이다.

종이를 적절히 잘라서 조각의 합을 최대로 하는 프로그램을 작성하시오.

Input
첫째 줄에 종이 조각의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 4)

둘째 줄부터 종이 조각이 주어진다. 각 칸에 쓰여 있는 숫자는 0부터 9까지 중 하나이다.

Output
영선이가 얻을 수 있는 점수의 최댓값을 출력한다.

Description
무조건 4개로 자르는게 좋아보이지만
0 0 0 9
0 0 0 0
0 0 0 0
9 0 0 0 
이러한 상황에서는 9009 가 최대 같지만, 아래한줄, 오른쪽에 3칸 세로줄을 같는 9900이 최대이다.
따라서, n,m제한이 작으므로 브루트포스로 모든 경우를 검증하는 것이 맞는 문제이다.

모든 경우를 생각해보면, 각 칸이 가로 카운트에 속할지 세로카운트에 속할지를 생각해보면 모든 경우의 수가 도출된다.
2^NM으로 최대 2^16의 경우의 수가 존재한다. 특정 경우가 산정되면, 점수를 카운트하는 작업이 필요한데 이때, NM의 복잡도가 소요된다.
결국 최악의 경우의 복잡도는 2^16*4*4 = 2^20 = 1048576으로 괜찮은 방법이다.

각 칸이 가로나 세로에 들어간 경우를 산정할때 비트마스크를 활용하여 접근하겠다.
0: 가로
1: 세로

https://www.acmicpc.net/problem/14391
*/
#include <iostream>

using namespace std;

int a[4][4];
int main() {
	int n, m;
	int _max=0;
	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %1d", &a[i][j]);

	// 0 : 가로, 1 : 세로
	for (int state = 0; state < (1 << (n*m)); state++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{ // 가로 탐색 행별 접근
			int now = 0;

			for (int j = 0; j < m; j++) 
			{ //특정 행 내 열단위 카운트
				int k = i * m + j;
				if ((state&(1 << k)) == 0) {
					now = now * 10 + a[i][j];
				}
				else 
				{ // 연속이 끊키는 시점
					sum += now;
					now = 0;
				}
			}
			sum += now;
		}

		for (int j = 0; j < m; j++) 
		{ //세로 행 탐색
			int now = 0;

			for (int i = 0; i < n; i++)
			{ //특정 열 내 행단위 카운트
				int k = i * m + j;
				if ((state&(1 << k)) != 0)
				{
					now = now * 10 + a[i][j];
				}
				else
				{ // 연속이 끊키는 시점
					sum += now;
					now = 0; 
				}
			}
			sum += now;
		}
		if (_max < sum)
			_max = sum;
	}
	printf("%d", _max);
	return 0;
}