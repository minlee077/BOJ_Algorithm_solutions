/*
Problem
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

Input
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

Output
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

Description
1번 컴퓨터와 연결된 모든 요소를 찾아내면 된다.

BFS혹은 DFS를 사용하면 모든 연결 요소를 확인할 수 있다.

이 코드에선 재귀함수 없이 Stack을 활용한 DFS를 구현하였다.

재귀함수를 사용할경우에는 함수 콜스택을 활용하게 된다. 마찬가지로 스택에 정점을 순차적으로 누적하면 DFS를 구현할 수 있다.

단, 함수콜스택에서 pop될때, 지역변수가 유지되는 점을 고려하여, 사용되는 스택에도 연결노드를 확인할때 사용하는 변수를 할당해야 불필요한 중복 연산을 줄일 수 있다.

https://www.acmicpc.net/problem/2606
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, e;
	cin >> n >> e;
	vector<vector<int>> a(n + 1);
	vector<bool> check(n + 1, false);
	int cnt = 0;
	for (int i = 0; i < e; i++)
	{
		int s, d;
		cin >> s >> d;
		a[s].push_back(d);
		a[d].push_back(s);
	}

	stack <pair<int, int>>st;
	st.push(make_pair(1, 0));

	while (!st.empty())
	{
		bool _flag = false;
		int now = st.top().first;
		int loc = st.top().second;
		check[now] = true;
		int sz = a[now].size();

		for (; loc < sz; loc++)
		{
			int next = a[now][loc];
			if (check[next] == true) continue;
			st.top().second = loc + 1;
			st.push(make_pair(next, 0));
			cnt++;
			_flag = true;
			break;
		}
		if (_flag)
			continue;
		else
			st.pop();
	}
	cout << cnt << '\n';
	return 0;
}