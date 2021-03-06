/*
Problem
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다.
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.

Input
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

Output
check 연산이 주어질때마다, 결과를 출력한다.

Description
비트마스크를 활용하면, 효율적으로 집합 연산을 할 수 있다.

https://www.acmicpc.net/problem/11723
*/
#include <iostream>
#include <string>

using namespace std;

int _add(int s, int x)
{
	return s | (1<<x-1);
}
int _remove(int s, int x)
{
	return s & ~(1<<(x-1));
}
void _check(int s, int x) 
{
	if ((s& (1 << (x - 1))) != 0)
		cout << 1 << '\n';
	else
		cout<< 0<<'\n';
}
int	_toggle(int s, int x)
{
	return s ^(1<< (x-1));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s = 0;
	int m;
	cin >> m;
	string inst;
	while (m--)
	{
		int x;
		cin >> inst;
		if (inst=="add")
		{
			cin >> x;
			s=_add(s, x);
		}
		else if (inst == "check")
		{
			cin >> x;
			_check(s, x);
		}
		else if (inst == "remove")
		{
			cin >> x;
			s = _remove(s, x);
		}
		else if (inst == "toggle")
		{
			cin >> x;
			s = _toggle(s, x);
		}
		else if (inst == "all")
		{
			s = (1 << 20) - 1;
		}
		else if (inst == "empty")
		{
			s  = 0;
		}
	}
	return 0;
}