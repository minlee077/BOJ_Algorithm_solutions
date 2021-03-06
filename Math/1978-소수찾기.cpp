/*
Problem
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.


Input
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.


Output
주어진 수들 중 소수의 개수를 출력한다.


Description
만약 소수 검증을 2부터 n-1까지 모두 진행한다면 복잡도는 O(N)일 것이다.
소수가 √n을 기준으로 대칭인 속성을 응용하여, √n까지만 검증해본다면, 복잡도는 O(√n)까지 낮출 수 있다.

https://www.acmicpc.net/problem/1978
*/
#include <iostream>
using namespace std;

bool prime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++)
		if (!(n%i))
			return false;
	return true;
}
int main(void)
{
	int n,input, cnt=0;
	cin >> n;
	
	while (n--)
	{
		cin >> input;
		if (prime(input))
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}