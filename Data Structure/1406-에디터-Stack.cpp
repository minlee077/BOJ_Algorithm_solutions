#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.

이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

이 편집기가 지원하는 명령어는 다음과 같다.

L	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
P $	$라는 문자를 커서 왼쪽에 추가함
초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.


Input
첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 이 문자열은 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다. 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 N(1≤N≤500,000)이 주어진다. 셋째 줄부터 N개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

Output
첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.

Description
스택을 두개 사용한다.
커서가 있는 위치 왼쪽의 문자열을 왼쪽스택, 오른쪽 문자열을 오른쪽스택으로 둔다.
커서의 위치가 바뀔때마다, 스택을 조작하며, 삽입이나 삭제는 왼쪽 스택 top에 대해서만 수행한다.
모든 수행이 끝난후 출력을위해 왼쪽스택의 모든 문자를 오른쪽스택으로 옮긴후에 오른쪽 스택에서 모든 문자를 순차적으로 출력한다.


https://www.acmicpc.net/problem/1406
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	char command;
	stack <char> left, right;
	
	int T=0;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
		left.push(str[i]);

	cin >> T;

	while (T--)
	{
		cin >> command;

		if (command=='L')
		{
			if (left.empty())
				continue;
			right.push(left.top());
			left.pop();
		}
		else if (command == 'D')
		{
			if (right.empty())
				continue;
			left.push(right.top());
			right.pop();
		}
		else if (command == 'B')
		{
			if (left.empty())
				continue;
			left.pop();
		}
		else {
			cin >> command;
			left.push(command);
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	return 0;
}