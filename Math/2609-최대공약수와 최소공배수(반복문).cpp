/*
Problem
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.


Input
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.


Output
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.


Description
단순하게, 순차적으로 1부터 N까지 mod 연산을 통해 수행하면, O(N)이 소요된다.
유클리드 호재법을 사용하면 복잡도를 O(logN)으로 낮출 수 있다.

https://www.acmicpc.net/problem/2609
*/
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while(b!=0)
	{
		int r = a%b;
		a= b;
		b= r;
	}
}
int main(void)
{
	int a, b,gc;
	cin>> a>> b;
	gc = gcd(a, b);
	cout << gc << '\n'<<a*b/gc <<'\n';
	return 0;
}