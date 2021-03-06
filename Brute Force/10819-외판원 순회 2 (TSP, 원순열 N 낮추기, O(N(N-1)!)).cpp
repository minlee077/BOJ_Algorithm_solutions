/*
Problem
외판원 순회 문제는 영어로 Traveling Salesman problem (TSP) 라고 불리는 문제로 computer science 분야에서 가장 중요하게 취급되는 문제 중 하나이다. 여러 가지 변종 문제가 있으나, 여기서는 가장 일반적인 형태의 문제를 살펴보자.

1번부터 N번까지 번호가 매겨져 있는 도시들이 있고, 도시들 사이에는 길이 있다. (길이 없을 수도 있다) 이제 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로를 계획하려고 한다. 단, 한번 갔던 도시로는 다시 갈 수 없다. (맨 마지막에 여행을 출발했던 도시로 돌아오는 것은 예외) 이런 여행 경로는 여러 가지가 있을 수 있는데, 가장 적은 비용을 들이는 여행 계획을 세우고자 한다.

각 도시간에 이동하는데 드는 비용은 행렬 W[i][j]형태로 주어진다. W[i][j]는 도시 i에서 도시 j로 가기 위한 비용을 나타낸다. 비용은 대칭적이지 않다. 즉, W[i][j] 는 W[j][i]와 다를 수 있다. 모든 도시간의 비용은 양의 정수이다. W[i][i]는 항상 0이다. 경우에 따라서 도시 i에서 도시 j로 갈 수 없는 경우도 있으며 이럴 경우 W[i][j]=0이라고 하자.

N과 비용 행렬이 주어졌을 때, 가장 적은 비용을 들이는 외판원의 순회 여행 경로를 구하는 프로그램을 작성하시오.


Input
첫째 줄에 도시의 수 N이 주어진다. (2 ≤ N ≤ 10) 다음 N개의 줄에는 비용 행렬이 주어진다. 

각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다. W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.

항상 순회할 수 있는 경우만 입력으로 주어진다.

Output
첫째 줄에 외판원의 순회에 필요한 최소 비용을 출력한다.

Description

N제한이 작다. 브루트 포스의 접근방식을 사용해봐도 될 문제이다.
정점의 방문 순서를 나타내는 순열을 뽑는 데 N!의 복잡도가 소요되고, 각 정점간에 비용을 추출하는데, N의 복잡도가 요구된다.
따라서, O(N!*N)의 복잡도가 요구된다.
이문제는 특이한점이 다시 돌아오는 구조를 생각해보면, 방문에 대한 계산시에 중복이 발생함을 알 수 있다.
원순열의 형태로, 가령, A-B-C-D-E-A라는 경로는 B-C-D-E-A-B, C-D-E-A-B-C, ... 와 모두 동일한 cost가 소요되기 때문이다.
따라서, 모든 순열을 뽑는 과정에서, N!이 아닌 (N-1)!개의 순열만 뽑아도 된다.
결국 (N-1)!*(N), 즉, O(N!)의 복잡도로 계산이 가능하다.

방법은 어느점이든 하나를 고정시키면 된다.
결국, 초기화 할때, 순열에 할당한 위치를 처음 위치를 계속 유지하면 된다.

https://www.acmicpc.net/problem/10971

*/
#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void Swap(T & pos1, T& pos2)
{
	int temp = pos1;
	pos1 = pos2;
	pos2 = temp;
}

template <typename T>
bool nextPerm(T & perm, int n)
{
	int incPos = n-1;
	for (int i = n - 1; i > 0; i--)
	{
		if (perm[i] > perm[i - 1])
			break;
		incPos = i-1;
	}
	if (incPos == 0)
		return false;
	
	int swapPoint=0;
	for (int i = n - 1; i >= incPos; i--)
	{
		if (perm[incPos - 1] < perm[i])
		{
			Swap(perm[incPos - 1], perm[i]);
			break;
		}
	}

	for (int i = n-1, j = incPos; i > j; i--, j++)
		Swap(perm[i], perm[j]);

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector <vector<int>> cost (n, vector<int> (n,0));
	vector <int> perm(n);

	for (int i = 0; i < n; i++)
	{
		perm[i] = i;
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	}
		
	int min = 2000000;
	do {
		int sum = 0;
 		bool flag = true;
		for (int i = 0; i < n - 1; i++)
		{
			if(cost[perm[i]][perm[i+1]] != 0)
				sum += cost[perm[i]][perm[i + 1]];
			else
			{
				flag = false;
				break;
			}
		}
		if (flag == true && cost[perm[n - 1]][perm[0]] != 0)
			sum += cost[perm[n - 1]][perm[0]];
		else
			continue;

		if (sum < min)
			min = sum;
	} while (nextPerm<vector<int>>(perm,n-1));
	
	cout << min;

	return 0;
}
