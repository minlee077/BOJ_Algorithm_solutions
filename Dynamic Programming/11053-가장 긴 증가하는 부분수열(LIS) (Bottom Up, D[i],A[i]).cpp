/*
Problem
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.

Input
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

Output
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다

Description
LIS 문제
D[i] : A[i]로 끝나는 대한 가장 긴 증가수열의 길이


D[i] = max(D[j]) + 1

* 1 <= j < i
* A[i] > A[j]


참고 : 원소중 가장 큰 요소를 찾을때 쓸만한 함수
 ** cout << *max_element(d.begin(),d.end()) << '\n';

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

	int T;
	cin >> T;
	vector <int> A (T + 1);
	vector <int> D (T + 1);
	for(int i= 1; i<=T ; i++)
		cin >> A[i];
	
	D[1] = 1;


	for (int i = 2; i <= T; i++) 
	{
		for (int j = i-1; j >0 ; j--)
			if (A[i] > A[j] && D[i] <= D[j])
				D[i] = D[j] + 1;
		if (D[i] == 0)
			D[i] = 1;
	}
		
	int max = 0;
	for (int i = 1; i <= T; i++)
		if (D[i] > max)
			max = D[i];
	cout << max << '\n';
	// cout << *max_element(d.begin(), d.end()) << '\n'; 이 문장을 통해 max원소를 찾는 동작 대체 가능

	return 0;
}