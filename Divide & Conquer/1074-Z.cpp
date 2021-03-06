/*

Problem
한수는 2차원 배열 (항상 2^N * 2^N 크기이다)을 Z모양으로 탐색하려고 한다. 예를 들어, 2*2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.



만약, 2차원 배열의 크기가 2^N * 2^N라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 4등분 한 후에 (크기가 같은 2^(N-1)로) 재귀적으로 순서대로 방문한다.

다음 예는 2^2 * 2^2 크기의 배열을 방문한 순서이다.



N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음 그림은 N=3일 때의 예이다.


Input
첫째 줄에 N r c가 주어진다. N은 15보다 작거나 같은 자연수이고, r과 c는 0보다 크거나 같고, 2^N-1보다 작거나 같은 정수이다


Output
첫째 줄에 문제의 정답을 출력한다.

Description
BruteForce : 각점을 순차적으로 모두 방문해야한다. 최악의 경우 (2^n)² = 4^n의 복잡도가 요구된다. (2^n,2^n)칸에 있을때.

D&C
1. Divide
4등분

2. Conquere
4등분한 곳에서 목표점 찾기
-> boundary에 속해있는지 확인후 해당 부분만 다시 4등분

-> log₄N의 깊이만큼 탐색할 것이다.
복잡도 : log₄N


https://www.acmicpc.net/problem/1074

*/
#include <iostream>
#include <cmath>

using namespace std;

int solve(int n, int r, int c, int sx, int sy, int lx, int ly)
{
	if (sx > lx || sy > ly)
		return 0;
	if (!((sx <= r && r <= lx) && (sy <= c && c <= ly)))
	{
		if (sx <= r || sy <= c)
		{
			return (lx - sx + 1)*(ly - sy + 1);
		}
		else
			return 0;
	}
	if (sx == r && sy == c)
		return 1;

	int w = solve(n - 1, r, c, sx, sy, lx / 2, ly / 2);
	int x = solve(n - 1, r, c, sx, ly / 2 + 1, lx / 2, ly);
	int y = solve(n - 1, r, c, lx / 2, sy, lx, ly / 2);
	int z = solve(n - 1, r, c, lx / 2, ly / 2 + 1, lx, ly);
	return w + x + y + z;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, c;
	cin >> n >> r >> c;

	r += 1;
	c += 1;
	int p = pow(2, n);

	cout << solve(n, r, c, 1, 1, p, p) << '\n';


	return 0;
}