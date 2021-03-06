#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
크리보드는 kriii가 만든 신기한 키보드이다. 크리보드에는 버튼이 4개만 있으며, 하는 역할은 다음과 같다.

화면에 A를 출력한다.
Ctrl-A: 화면을 전체 선택한다
Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다
Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.
크리보드의 버튼을 총 N번 눌러서 화면에 출력된 A개수를 최대로하는 프로그램을 작성하시오.

Input
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

Output
크리보드의 버튼을 총 N번 눌러서 화면에 출력할 수 있는 A 개수의 최댓값을 출력한다.

Description
D[i]: i번 입력했을때, 출력된 문자의 개수 최댓값.

D[i] = max( A출력, 선택+복사+붙여넣기 * p)

D[i] = max( D[i-1] + 1, D[i-3]*2, D[i-4]*3, D[i-5]*4, ...)

D[i] = max( D[i-1] + 1, D[i-(2+j)]*(j+1) ) (1 ≤ j ≤ i-3)

https://www.acmicpc.net/problem/11058
*/
#include <iostream>

using namespace std;

long long int D[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		D[i] = D[i - 1] + 1;
		for (int j = 1; j <= i - 3; j++)
			if (D[i] < D[i - (2 + j)] * (j + 1))
				D[i] = D[i - (2 + j)] * (j + 1);
	}
	cout << D[n];
	return 0;
 }