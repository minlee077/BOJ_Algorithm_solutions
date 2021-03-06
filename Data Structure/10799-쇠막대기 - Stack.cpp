#include "pch.h"
/*
Problem :
레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘( ) ’ 으로 표현된다. 또한, 모든 ‘( ) ’는 반드시 레이저를 표현한다.
쇠막대기의 왼쪽 끝은 여는 괄호 ‘ ( ’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다. 

Input :
한 줄에 쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 공백없이 주어진다. 괄호 문자의 개수는 최대 100,000이다.

Output :
잘려진 조각의 총 개수를 나타내는 정수를 한 줄에 출력한다.

Description :
스택을 이용하여, 쇠막대기가 쌓인 개수를 카운팅한다.
레이저가 발생할때마다, 스택에 누적된 쇠막대기의 수 만큼 조각 수를 추가한다.
레이저와 쇠막대기를 의미하는 닫는 괄호를 구분하기 위해, 바로 이전 문자가 무엇인지를 확인하는 조건문을 포함해야한다.

https://www.acmicpc.net/problem/10799
*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int open,ans;
	int val=0;
	string str;

	open = 0; ans = 0;
	cin >> str;
	for( int i = 0; i<str.size();i++)
	{
		if (str[i] == '(')
			open += 1;
		else if (str[i - 1] == '(')
		{
			open -= 1;
			ans += open;
		}
		else
		{
			open -= 1;
			ans += 1;
		}
	}
	cout << ans;
	
	return 0;
}