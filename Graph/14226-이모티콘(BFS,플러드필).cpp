/*
Problem
영선이는 매우 기쁘기 때문에, 효빈이에게 스마일 이모티콘을 S개 보내려고 한다.

영선이는 이미 화면에 이모티콘 1개를 입력했다. 이제, 다음과 같은 3가지 연산만 사용해서 이모티콘을 S개 만들어 보려고 한다.

화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
화면에 있는 이모티콘 중 하나를 삭제한다.
모든 연산은 1초가 걸린다. 또, 클립보드에 이모티콘을 복사하면 이전에 클립보드에 있던 내용은 덮어쓰기가 된다. 클립보드가 비어있는 상태에는 붙여넣기를 할 수 없으며, 일부만 클립보드에 복사할 수는 없다. 또한, 클립보드에 있는 이모티콘 중 일부를 삭제할 수 없다. 화면에 이모티콘을 붙여넣기 하면, 클립보드에 있는 이모티콘의 개수가 화면에 추가된다.

영선이가 S개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

Input

첫째 줄에 S (2 ≤ S ≤ 1000) 가 주어진다.



Output
첫째 줄에 이모티콘을 S개 만들기 위해 필요한 시간의 최솟값을 출력한다.

Description
플러드필 문제이다.
각각의 상태에서, 클립보드에 적재된 정보를 함께 저장하며 전이 시키면 된다.
pair를 활용하여, 데이터를 전이시키는 방식으로 구현하였다.

특이한점은 distance의 matrix에도, 클립보드에 대한정보도 따로 저장하며 진행해야 한다.
왜냐하면, 클립보드에 저장된 수도 이전 상태에 따라 다르기 때문이다.


https://www.acmicpc.net/problem/1697

*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dist[1001][1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s;
	cin >> s;
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	dist[1][0] = 0;
	q.push(make_pair(1, 0));
	int output, clip;
	while (!q.empty())
	{
		output = q.front().first;
		clip = q.front().second;
		q.pop();
		if (output == s)
			break;

		if (dist[output][output] ==-1)
		{
			q.push(make_pair(output,output));
			dist[output][output] = dist[output][clip] + 1;
		}

		if (output+clip <=1000  &&dist[output+clip][clip]==-1)
		{
			
			q.push(make_pair(output + clip, clip));
			dist[output + clip][clip] = dist[output][clip] + 1;
		}

		if (output - 1 >= 0 && dist[output-1][clip]==-1)
		{
			q.push(make_pair(output - 1, clip));
			dist[output - 1][clip] = dist[output][clip] + 1;
		}

	}

	cout << dist[output][clip];

	return 0;
}

