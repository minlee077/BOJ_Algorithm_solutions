/*
Problem
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

Input
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

Output
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다.

Description
LIS 문제 11053 문제에서 path만 출력하면 되는 문제
자료를 저장하는 과정에서 이전 위치를 저장해야하는데, 복원시에는 종착점에서 출발지로 복원해야한다.
따라서, 역순으로 복원이 된다.
LIFO 구조의 스택을 활용하면, path복원이 쉬워 진다. 
LIFO 특성상 들어간 순서의 역순으로 데이터가 추출되기 때문이다.


*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	vector <int> A (T + 1);
	vector <int> D (T + 1);
	vector <int> back(T + 1);
	for(int i= 1; i<=T ; i++)
		cin >> A[i];
	
	D[1] = 1;


	for (int i = 2; i <= T; i++) 
	{
		for (int j = i-1; j >0 ; j--)
			if (A[i] > A[j] && D[i] <= D[j])
			{
				D[i] = D[j] + 1;
				back[i] = j;
			}
		if (D[i] == 0)
			D[i] = 1;
	}
		
	int max = 0, lastIdx = 1;
	for (int i = 1; i <= T; i++)
		if (D[i] > max)
		{
			max = D[i];
			lastIdx = i;
		}
	cout << max << '\n';
	stack <int> path;
	while (lastIdx)
	{
		path.push(A[lastIdx]);
		lastIdx = back[lastIdx];
	}
	while (!path.empty())
	{
		cout << path.top()<<" ";
		path.pop();
	}

	return 0;
}