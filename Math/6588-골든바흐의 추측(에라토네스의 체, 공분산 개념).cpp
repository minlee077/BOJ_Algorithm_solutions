#include "pch.h"
/*
Problem
1742년, 독일의 아마추어 수학가 크리스티안 골드바흐는 레온하르트 오일러에게 다음과 같은 추측을 제안하는 편지를 보냈다.

4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
예를 들어 8은 3 + 5로 나타낼 수 있고, 3과 5는 모두 홀수인 소수이다. 또, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 이다.

이 추측은 아직도 해결되지 않은 문제이다.

백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오.


Input
입력은 하나 또는 그 이상의 테스트 케이스로 이루어져 있다. 테스트 케이스의 개수는 100,000개를 넘지 않는다.

각 테스트 케이스는 짝수 정수 n 하나로 이루어져 있다. (6 ≤ n ≤ 1000000)

입력의 마지막 줄에는 0이 하나 주어진다.


Output
각 테스트 케이스에 대해서, n = a + b 형태로 출력한다.
이때, a와 b는 홀수 소수이다. 숫자와 연산자는 공백 하나로 구분되어져 있다. 
만약, n을 만들 수 있는 방법이 여러 가지라면, b-a가 가장 큰 것을 출력한다. 또, 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우에는 "Goldbach's conjecture is wrong."을 출력한다.




Description
기본적으로 에라토네스의 체를 통해 소수를 초기화해야한다.

홀수인 소수를 이용해 두수의 합이 짝수인지 확인하려면,

짝수가 n이라면 홀수는 i, n - i가 된다.
즉, 하나의 수가 정해지면 다른 하나의 수는 유일하게 정해지는 형태이다.
다시말해, 두 소수는 covariance correlation 이 1인 상호 종속적인 관계이다.
따라서, i에 대한 순회를 하며, i와 자동적으로 지정되는 n-i에 대해 소수검증을 하면 된다.ㅁ

https://www.acmicpc.net/problem/6588

*/
#include <iostream>
#include <vector>
using namespace std;

int check[1000001];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	check[0] = check[1] = true;
	vector <int> primes;
	for (int i = 2; i <= 1000000; i++)
		if (check[i] == false)
		{
			primes.push_back(i);
			for (int j = i + i; j <= 1000000; j += i)
				check[j] = true;
		}

	int nOP = primes.size();
	while (n)
	{
		for (int j = 1; primes[j] <= nOP; j++)
		{
			if (check[n - primes[j]] == false)
			{
				cout << n << " = " << primes[j] << " + " << n-primes[j] << '\n';
				break;
			}
		}
		cin >> n;
	}

	return 0;
}