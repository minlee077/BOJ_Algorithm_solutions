/*
Problem
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

-X가 3으로 나누어 떨어지면, 3으로 나눈다.
-X가 2로 나누어 떨어지면, 2로 나눈다.
-1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

Input
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

Output
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

https://www.acmicpc.net/submit/1463
*/

#include <iostream>

using namespace std;

int memo[1000001] = { 0 };
int makeOne(int n)
{
	if (n == 1) return 0; // 가장먼저 1인지 검증하여 1이면 0 return
	if (memo[n] > 0)return memo[n];// memo에 데이터 있는지 확인 없다면, 아래 프로세스 진행 (DP에서 중복연산을 피하기 위한 핵심)
	memo[n] = makeOne(n - 1) + 1; //n->n-1
	if (n % 2 == 0) //n->n/2 연산이 가능한지 검증 후 맞다면, memo와 비교하여 갱신 or 유지
	{
		int temp = makeOne(n / 2) + 1;
		if (memo[n] > temp) memo[n] = temp;
	}
	if (n % 3 == 0) // n->n/3 연산이 가능한지 검증 후 맞다면, memo와 비교하여 갱신 or 유지
	{
		int temp = makeOne(n / 3) + 1;
		if (memo[n] > temp) memo[n] = temp;
	}
	return memo[n];
}


int main(void)
{
	int input;
	cin >> input;
	cout << makeOne(input) << '\n';

	return 0;
}