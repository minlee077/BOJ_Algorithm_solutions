#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

Input

첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.


Output
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

Description
플러드필 문제이다.
특정 점에서 다음 상태를 정의할때, 3종류로 나뉘게 된다.
말을 움직이는 문제를 움직일 수 있는 좌표에 따라 다음 상태를 정의한 것처럼 진행하면 된다.


https://www.acmicpc.net/problem/1697

*/
#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
const int dir[] = { 1, -1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;

	cin >> n >> k;
	
	queue<int> q;
	dist[n] =1;
	q.push(n);
	while (!q.empty()) 
	{
		int now = q.front();
		q.pop();
		if (now == k)
			break;
		for (int i = 0; i < 2; i++)
		{
			int next= now + dir[i];
			if (next<0 || next >100000 )
				continue;
			if (dist[next] == 0)
			{
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
		int ne = 2*now;
		if (ne < 0 || ne >100000)
			continue;
		if (dist[ne] == 0)
		{
			dist[ne] = dist[now] + 1;
			q.push(ne);
		}
	}
	cout << dist[k]-1 << '\n';

	return 0;
}
