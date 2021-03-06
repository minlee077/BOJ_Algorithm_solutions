/*
Problem
바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 서울로 가 버리는 황당한 상황에 직면한 조교들은, 702호에 새로운 보안 시스템을 설치하기로 하였다.
이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다. 
또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 
즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다. 
이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 침투하기 위해 암호를 추측해 보려고 한다.
C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.

Input
첫째 줄에 두 정수 L, C가 주어진다. (3 ≤ L ≤ C ≤ 15) 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다.
주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다.

Output
각 줄에 하나씩, 사전식으로 가능성 있는 암호를 모두 출력한다.

Description
각 알파벳이 포함되거나 포함되지 않는 경우를 이용하여, 문제를 해결 할 수 있다.
C개의 알파벳을 이용하므로 대략 2^C의 경우의 수를 생각할 수 있다.
재귀함수에서 정답이 되는 상황은 만들어진 글자 길이가 l개가 될때, 모음 개수조건과 자음 개수조건을 만족하는 순간이다.
불가능한 상황은 알파벳배열의 인덱스가 c를 초과한 접근이 발생할때이다.
마지막으로, 다음 상황을 정의하기 위해 모음과 자음에 따라 각각 현재 문자를 포함하거나 포함하지 않는 경우를 나타내는 함수를 호출한다.

https://www.acmicpc.net/problem/1759

*/
#include <iostream>
#include<algorithm>

using namespace std;

char alpha[16];
char out[16];
int l, c;
void go(int idx, int cnt, int ja, int mo)
{
	if (cnt == l )
	{
		if (mo >0 && ja > 1)
		{
			for (int i = 0; i < l; i++)
				cout << out[i];
			cout << '\n';
		}
		return;
	}

	if (idx >= c)return;

	if (alpha[idx] == 'a' || alpha[idx] == 'e' || alpha[idx] == 'i' || alpha[idx] == 'o' || alpha[idx] == 'u')
	{
		out[cnt] = alpha[idx];
		go(idx + 1, cnt + 1, ja, mo + 1);
		go(idx + 1, cnt, ja, mo);

	}
	else {
		out[cnt] = alpha[idx];
		go(idx + 1, cnt + 1, ja + 1, mo);
		go(idx + 1, cnt, ja, mo);
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;

	for (int i = 0; i < c; i++)
		cin >> alpha[i];
	sort(alpha, alpha + c);

	go(0, 0, 0, 0);


	return 0;
}