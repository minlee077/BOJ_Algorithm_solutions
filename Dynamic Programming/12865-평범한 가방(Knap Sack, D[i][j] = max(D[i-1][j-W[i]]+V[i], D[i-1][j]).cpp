/*
Problem
이 문제는 아주 평범한 배낭에 관한 문제이다.

한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.

준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K무게까지의 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

Input
첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.

입력으로 주어지는 모든 수는 정수이다.

Output
한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다.

Description
Knap sack 문제

브루트 포스방식 (각 물건을 넣을지 않넣을 지에 대한 경우의수 테스팅 -> O(2^n)
dp 방식 (k의 무게를 채웠을 때, 최대 가치) -> O(NK)

D[i][j] : i번째 물건까지 고려했을때, 무게 j를 채운상태에서 가치의 최대값

D[i][j] = max(i번째물건을 포함시킬때, 포함시키지 않을때)
D[i][j] = max(D[i-1][j-W[i]]+V[i], D[i-1][j])

https://www.acmicpc.net/problem/2294

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
	
	int n,k; 
	cin >> n>>k;
	
	vector<int> W(n+1);
	vector<int> V(n+1);
	vector<vector<int>> D(n+1, vector<int> (k+1,0));

	for (int i = 1; i <= n; i++)
		cin >> W[i]>>V[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
		{
			if (j - W[i] < 0)
			{
				D[i][j] = D[i - 1][j];
				continue;
			}

			D[i][j] = max(D[i - 1][j - W[i]] + V[i], D[i - 1][j]);
		}

	cout << D[n][k]<<'\n';
	return 0;
}