/*
Problem
각각 부피가 A, B, C(1≤A, B, C≤200) 리터인 세 개의 물통이 있다. 처음에는 앞의 두 물통은 비어 있고, 세 번째 물통은 가득(C 리터) 차 있다. 

이제 어떤 물통에 들어있는 물을 다른 물통으로 쏟아 부을 수 있는데, 이때에는 한 물통이 비거나, 다른 한 물통이 가득 찰 때까지 물을 부을 수 있다. 

이 과정에서 손실되는 물은 없다고 가정한다.

이와 같은 과정을 거치다보면 세 번째 물통(용량이 C인)에 담겨있는 물의 양이 변할 수도 있다. 첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

Input
첫째 줄에 세 정수 A, B, C가 주어진다.


Output
첫째 줄에 공백으로 구분하여 답을 출력한다. 각 용량은 오름차순으로 정렬한다.

Description
단순히, BFS를 수행하며, C와 B에 물의 양이 C의 용량과 같은 상태를 저장하며, BFS를 수행하면 된다.

A + B + C = C의 전체용량

A = C전체 - (B+C)

경우의 수가 약 800만이 나온다.

https://www.acmicpc.net/problem/2251
*/
#include <iostream>
#include <queue>

using namespace std;

bool check[201][201];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	queue <pair<int, int>> q;

	q.push(make_pair(0,0));
	check[0][0] = true;

 	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		int c = C-a-b;
		q.pop();

		if(a!= A)
		{
			int na = a + b;
			int nb = 0;
			if (na > A)
			{
				nb = na - A;
				na = A;
			}

			if (check[na][nb] == false)
			{
				check[na][nb] = true;
				q.push(make_pair(na, nb));
			}
			
			na = a + c;
			int nc = 0;
			nb = C - a- c;
			if (na > A)
			{
				nc = na-A;
				na = A;
				nb = b;
			}
			if (check[na][nb] == false)
			{
				check[na][nb] = true;
				q.push(make_pair(na, nb));
			}
		}
	
		if (b != B)
		{
			int na = 0;
			int nb = b + a;

			if (nb > B)
			{
				na = nb-B;
				nb = B;
			}
			if (check[na][nb] == false)
			{
				check[na][nb] =true;
				q.push(make_pair(na, nb));
			}


			nb = b+c;
			int nc = 0;
			na = a;
			if (nb > B)
			{
				nc = nb-B;
				nb = B;
			}

			if (check[na][nb] == false)
			{
				check[na][nb] = true;
				q.push(make_pair(na, nb));
			}
		}
		
		if (c != C)
		{
			int nc = a + c;
			int na = 0;
			int nb = b;
			if (nc > C)
			{
				na = nc-C;
				nc = C;
			}

			if (check[na][nb] == false)
			{
				check[na][nb] = true;
				q.push(make_pair(na, nb));
			}

			nc = b + c;
			nb = 0;
			na = a;

			if (nc > C)
			{
				nb =  nc-C;
				nc = C;
			}

			if (check[na][nb] == false)
			{
				check[na][nb] = true;
				q.push(make_pair(na, nb));
			}

		}
	}


	for (int i = C; i >=0; i--)
	{
		if (check[0][i] == true)
			cout << C- i << " ";
	}

	return 0;
}


