#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다.
+를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다.
채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

수빈이가 지금 보고 있는 채널은 100번이다.

Input
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.
둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다.
고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러번 주어지는 경우는 없다.

Output
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.

Description
숫자를 누르고, 목적 번호와 차를 구해서 해당 크기만큼 + 혹은 -를 누름

구체적인 구현
-기본 채널을 모두 만들고 고장난 버튼으로 인해 초기 채널이 될 수 없는 채널을 지우기
-(고장난 버튼으로 기본채널을 만들고 접근하기에는 코드가 더 복잡해짐)

브루트포스 방식으로 초기 상태를 0~100만번의 숫자까지 모두 수행해봄


https://www.acmicpc.net/problem/1107

*/
#include <iostream>
#include <cmath>

using namespace std;

int M,N;
bool broken[10];
int check(int num)
{
	if (num == 0)
		if (broken[0])
			return 0;
		else
			return 1;
	
	int len = 0;
	while (num > 0)
	{
		if (broken[num % 10])
		{
			return false;
		}
		num /= 10;
		len++;
	}


	return len;
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int start = 100;
	cin >> N;
	cin >> M;
	int k;
	for (int i = 0; i < M; i++) {
		cin >> k;
		broken[k]=true;
	}
	int min = abs(N -  100);

	for (int i = 0; i < 1000000; i++)
	{
		int len = check(i);
		if (len ==0)
			continue;

		int move = abs(i - N) + len;

		if (move < min)
			min = move;
	}
	cout << min;
	return 0;
}