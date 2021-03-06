/*
Problem
3*3 표에 다음과 같이 수가 채워져 있다. 오른쪽 아래 가장 끝 칸은 비어 있는 칸이다.

1	2	3
4	5	6
7	8
어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 수를 그 칸으로 이동시킬 수가 있다. 물론 표 바깥으로 나가는 경우는 불가능하다. 우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다. 다음의 예를 보자.

1	 	3
4	2	5
7	8	6

1	2	3
4	 	5
7	8	6

1	2	3
4	5
7	8	6

1	2	3
4	5	6
7	8
가장 윗 상태에서 세 번의 이동을 통해 정리된 상태를 만들 수 있다. 이와 같이 최소 이동 횟수를 구하는 프로그램을 작성하시오.

Input
세 줄에 걸쳐서 표에 채워져 있는 아홉 개의 수가 주어진다. 한 줄에 세 개의 수가 주어지며, 빈 칸은 0으로 나타낸다.


Output
첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 경우 -1을 출력한다.


Description

퍼즐상태를 하나의 정점으로 보고 접근하면, BFS를 활용한 플러드필 문제로 볼 수 있다.
이렇게 가정하게되면, 전체 정점의 개수는 9!개로 약 39만개가 나오므로, 충분히 복잡도가 낮아서 BFS를 수행해볼만하다.
15퍼즐의 경우에는 16!이나오므로, 단순한 bfs로 해결이 불가능하다. (해결하기 위해선, 양쪽에서 bfs를 시작해서, 탐색 크기를 낮추면 가능하다.)

하나에 상태에 개별적인 상태가 9개이므로, 모든 개별 상태를 저장하고 관리하기에는 무리가 있다.
이를 한번에 저장할 방법을 생각해보면, 모든 상태에 대해 시퀀스는 1:1대응 이되므로, 문자열로 상태를 저장한다면, 쉽게 관리가 가능하다.

가령,
1 2 3
4 5 7
6 8 0 이면, 123457680으로 생각할 수 있다. (0은 비어있는 공간)
0이 맨앞으로 가게 되면 정수로 파싱하게 되면, 혹시 모를 문제가 발생할 수도 있으니, 0을 9로 처리하는 것이 조금 더 관리에 용이할 것이다.

다음은, 주어진 상태를 다음 상태로에 전이를 어떻게 처리할 지를 생각해야 한다.

직관적으로 주어진 퍼즐에서, 다음 상태는 9(빈공간)가 상하좌우로의 swap을 통해 정의 될 수 있다.
따라서, 보관중인 문자열을 좌표와 대응시켜야 한다.
문자열의 특성상, 특정위치는 실제 퍼즐로 mapping된 위치와 1:1대응이 되므로, x좌표는 문자열내 위치에서 3으로 나눈 나머지, y좌표는 문자열내 위치에서 3으로 나눈 몫으로 해석하면 된다.

위의 상태 정의에 대한 방식에 따라 BFS를 수행하면 문제는 해결된다.

다음으로, 생각할 문제는 메모리이다.	
위에 방식에 배열을 사용하게 되면, 거리를 저장(+방문여부 확인)하기 위해 실제 필요한 배열의 공간은 arr [123456789] ~ arr[987654321]일 것이다.
문제는 약 10억크기의 메모리를 잡고서 실제로 사용되는 메모리는  362,880(9!)개밖에 매우 큰 메모리 공간 낭비가 우려된다.


따라서, 모든 인덱스(키값)가 아닌 필요한 인덱스만 키로 사용하는 map객체를 쓰는 것이 조금 더 바람직한 접근 방법이다.


https://www.acmicpc.net/problem/1525

*/
#include <iostream>
#include <queue>
#include <map>
#include <string>

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map <int, int> dist;
	
	string firstString="123456789";
	for (int i = 0; i < 9; i++)
		cin>>firstString[i];


	int zpos=firstString.find("0");
	firstString[zpos] = '9';

	int firstState = stoi(firstString);

	queue<int> q;
	q.push(firstState);
	dist[firstState]=1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if (now == 123456789)
			break;

		string nowStr = to_string(now);
		int pos = nowStr.find('9');
		int x = pos % 3;
		int y = pos / 3;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3)
			{
				swap(nowStr[ x+ y*3], nowStr[nx+ ny*3]);
				int next=stoi(nowStr);

				if (dist[next] == 0)
				{
					dist[next] = dist[now] + 1;
					q.push(next);
				}
				swap(nowStr[x + y*3], nowStr[nx + ny*3]);
			}
		}
	}

	cout << dist[123456789]-1;

	return 0;
}