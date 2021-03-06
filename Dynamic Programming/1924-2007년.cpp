/*
Problem
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

Input
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 
참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

Output
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

*/


#include <iostream>

using namespace std;

int main(void)
{
	int Month,Day;
	int MD[11] = { 0, };
	int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	MD[0] = 31;
	for (int i = 1; i < 11; i++) 
	{
		MD[i] = MD[i - 1] + Months[i];
	}
	
	cin >>Month >>Day;

	if (Month > 1)
		Day += MD[Month - 2];

	switch (Day % 7)
	{

		case 0:
			cout << "SUN" << '\n'; 
			break;
		case 1:
			cout << "MON" << '\n';
			break;
		case 2:
			cout << "TUE" << '\n';
			break;
		case 3:
			cout << "WED" << '\n';
			break;
		case 4:
			cout << "THU" << '\n';
			break;
		case 5:
			cout << "FRI" << '\n';
			break;
		case 6:
			cout << "SAT" << '\n';
			break;
	}

	return 0;
}
