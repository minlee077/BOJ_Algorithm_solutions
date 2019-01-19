#include "pch.h"
/*
Problem
상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.

오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.

백준이는 비서에게 최대한 많은 상담을 잡으라고 부탁을 했고, 비서는 하루에 하나씩 서로 다른 사람의 상담을 잡아놓았다.

각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.

N = 7인 경우에 다음과 같은 상담 일정표를 보자.


	1일	2일	3일	4일	5일	6일	7일
Ti	3	5	1	1	2	4	2
Pi	10	20	10	20	15	40	200
1일에 잡혀있는 상담은 총 3일이 걸리며, 상담했을 때 받을 수 있는 금액은 10이다. 5일에 잡혀있는 상담은 총 2일이 걸리며, 받을 수 있는 금액은 15이다.

상담을 하는데 필요한 기간은 1일보다 클 수 있기 때문에, 모든 상담을 할 수는 없다. 예를 들어서 1일에 상담을 하게 되면, 2일, 3일에 있는 상담은 할 수 없게 된다. 2일에 있는 상담을 하게 되면, 3, 4, 5, 6일에 잡혀있는 상담은 할 수 없다.

또한, N+1일째에는 회사에 없기 때문에, 6, 7일에 있는 상담을 할 수 없다.

퇴사 전에 할 수 있는 상담의 최대 이익은 1일, 4일, 5일에 있는 상담을 하는 것이며, 이때의 이익은 10+20+15=45이다.

상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.

Input
첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.

둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)


Output
첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.

Description
D[i]: 마지막으로 i일에 했을 때

-> D[i][0] , D[i][1] i일에 일을 했을때[1], i일에 일을 안했을때 [0]

역순저장


D[N][i] : N일차에 일을 i했을때 최대 누적 급여
P[N] : 급여
T[N] : 소요일수

D[N][0] = D[N-1]
D[N][1] = D[N-T[N]] + P[N]

D[N] = max(D[N][0],D[N][1])

조건
N-T[N] > 0
N>1



https://www.acmicpc.net/problem/14501

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
	
	int n;
	cin >> n;
	vector <int> T(n+1);
	vector <int> P(n+1);
	vector <int> D(n + 1);

	for(int i = n; i>=1 ; i--)
		cin >> T[i] >> P[i];
	
	if (1 - T[1] < 0)
		D[1] = 0;
	else
		D[1] = P[1];

	for (int i = 2; i <= n; i++)
	{
		if (i - T[i] < 0) {
			D[i] = D[i - 1];
			continue;
		}
		D[i] = max(D[i - 1], D[i - T[i]] + P[i]);
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
		if (max < D[i])
			max = D[i];

	cout << max << '\n';
	return 0;
}