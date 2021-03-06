/*
Problem
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 
이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.

티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다.
비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다.
물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.

티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다.

Input
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와 'S'는 하나씩만 주어진다.

Output
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.


Description
플러드필 방식을 이용해 물을 채우고 물이 언제 채워졌는지를 기록하는 wMap을 만든다.
만든 이후에, 고슴도치가 bfs탐색을 통해 해당 stage에 물이 없는 곳으로만 움직이게하여, 거리를 갱신하는 방식으로 구현한다.

돌이 있는 위치는 -2로 초기화하여, wMap과 dist모두 기록한다.

https://www.acmicpc.net/problem/3055
*/
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int wMap[51][51];
int dists[51][51];

int main() {
	int r, c;
	scanf(" %d %d", &r, &c);
	int dstX, dstY;
	int sx, sy;
	vector<pair<int, int>> wSrc;
	for(int i=1; i<=r; i++)
		for (int j = 1; j <= c; j++)
		{
			char temp;
			scanf(" %1c", &temp);
			if (temp == 'D')
			{
				dstY = i;
				dstX = j;
				wMap[i][j] = -2;
				dists[i][j] = -1;
			}
			else if (temp == 'X')
			{
				dists[i][j] = -2;
				wMap[i][j] = -2;
			}
			else if (temp == '*')
			{
				wMap[i][j] = 0;
				dists[i][j] = -2;
				wSrc.push_back(make_pair(i, j));
			}
			else if(temp =='S')
			{
				wMap[i][j] = -1;
				dists[i][j] = 0;
				sy = i;
				sx = j;
			}
			else
			{
				dists[i][j] = -1;
				wMap[i][j] = -1;
			}
		}
	
	queue <pair<int, int>> q;
	while (!wSrc.empty())
	{
		q.push(wSrc.back());
		wSrc.pop_back();
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (nx <= 0 || nx > c || ny <= 0 || ny > r) continue;
			if (wMap[ny][nx] == -1)
			{
				wMap[ny][nx] = wMap[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}

	q.push(make_pair(sy, sx));
	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == dstY && x == dstX)
			break;

		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (nx <= 0 || nx > c || ny <= 0 || ny > r) continue;

			if (dists[ny][nx] != -1)continue;
			if (wMap[ny][nx] >dists[y][x]+1 || wMap[ny][nx]==-1 || (ny==dstY && nx==dstX) )
			{
				dists[ny][nx] = dists[y][x] + 1;
				q.push(make_pair(ny, nx));
			}

		}
	}
	
	if (dists[dstY][dstX] == -1)
	{
		printf("KAKTUS\n");
	}
	else
	{
		printf("%d\n", dists[dstY][dstX]);
	}

	return 0;
}