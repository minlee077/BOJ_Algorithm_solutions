/*
Problem
남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다. 
그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 
김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다.
김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다.
남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

Input
첫째 줄에 단어의 개수 N과 K가 주어진다. N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다.
둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 
단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.

Output
첫째 줄에 김지민이 K개의 글자를 가르칠 때, 학생들이 읽을 수 있는 단어 개수의 최댓값을 출력한다.

Description
가장 먼저 antic를 가르치고 추가적인 것을 학습시켜야한다.
결국, 26-5 = 21개의 문자중에서 k-5개를 고르고 해당 상태에서 몇개가 맞는지 확인하는 문제다.
최악의 경우에 21C10= 352,716의 경우의 수를 가진다.

단순히 재귀함수를 이용해 각문자를 순차적으로 확인하게 되면, n*단어길이의 복잡도가 카운트시에 소요된다.

50*15*352,716 = 264,537,000번의 연산이 필요하다. 이 경우에는 시간초과가 나게 된다.

사실, 단어 검증 과정에서 모든 문자를 확인하지 않고, 단어가 어떤 문자로 구성되었는지 파악하기만 하면된다.

이를 조금 더 단순화하면, 비트마스크를 이용해서, 사용되는 문자에 대해 집합연산 방식을 사용하여 접근할 수 있다.

이렇게 처리하게되면, 초기에 문자열을 할당하는 작업에서 각 문자의 포함관계를 파악할 수 있고, 추후에 경우의 수와 검증과정에서는 352,716*50=약150만의 연산이 필요하므로, 해결가능한 문제가 된다.

https://www.acmicpc.net/problem/1062
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int learn;
int count(vector<int> &words)
{
	int cnt = 0;
	for (int word : words)
	{
		if (word== (learn & word))
			cnt ++;
	}
	return cnt;
}
int go(int idx, int k,vector<int>&words)
{
	if (k < 0) return 0; 
	if (idx == 26) return count(words);
	
	learn =learn | (1 << idx);
	int cnt= go(idx + 1, k - 1, words);
	learn = learn & (~(1<<idx));

	if (idx != 'a' - 'a' && idx != 'n' - 'a'&&idx != 't' - 'a'&&idx != 'i' - 'a' &&idx != 'c' - 'a')
	{
		int skip = go(idx + 1, k, words);
		if (skip > cnt) cnt = skip;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector <int>words(n);
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (char c : temp)
			words[i] =words[i]|(1<<(c - 'a'));
	}
	cout<< go(0, k, words) << '\n';
	return 0;
}