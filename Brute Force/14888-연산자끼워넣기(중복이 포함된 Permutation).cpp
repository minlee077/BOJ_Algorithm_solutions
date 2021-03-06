/*
Problem
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다.
연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다.
예를 들어, 아래와 같은 식을 만들 수 있다.

1+2+3-4×5÷6
1÷2+3+4-5×6
1+2÷3×4-5+6
1÷2×3-4+5+6
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 
즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

1+2+3-4×5÷6 = 1
1÷2+3+4-5×6 = 12
1+2÷3×4-5+6 = 5
1÷2×3-4+5+6 = 7
N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

Input
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 
둘째 줄에는 A1, A2, ..., AN이 주어진다.(1 ≤ Ai ≤ 100) 
셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

Output
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다.
최댓값과 최솟값은 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 
또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.

Description
브루트 포스 방식으로 접근해야한다. 
숫자는 고정이고, 연산자의 배치를 모두 수행해 보아야한다.
결국, 중복이 포함된 순열로 모든 경우의 수를 시도해 보면 된다.
최악의 경우는 n-1개의 연산자가 각각 골고루 분배되었을 경우로, 2,2,3,3도 한 예가 될 것이다.
이는 10!/(2!*2!*3!*3!)으로 약 2만개의 경우의 수가 나오므로 충분히 해볼만 하다.
이를 만약 재귀함수로 구현했다면, 중복을 제외하지 못하고, 4^10의 경우의 수로 계산해야한다.

https://www.acmicpc.net/problem/14888

*/
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 99999999
#define MIN -999999999

using namespace std;

int A[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	vector<int> operPos;
	for (int i = 1; i <= 4; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			operPos.push_back(i);
	}

	int max = MIN, min = MAX;
	do {
		int sum = A[0];
		int size = operPos.size();
		for(int i = 0; i <size; i++)
			switch (operPos[i])
			{
			case 1:
				sum += A[i+1];
				break;
			case 2:
				sum -= A[i+1];
				break;
			case 3:
				sum *= A[i+1];
				break;
			case 4:
				sum /= A[i+1];
				break;
			default:
				break;
			}
		if (max < sum)
			max = sum;
		if (min > sum)
			min = sum;

	} while (next_permutation(operPos.begin(),operPos.end()));

	cout << max << '\n' << min << '\n';
	return 0;
}
