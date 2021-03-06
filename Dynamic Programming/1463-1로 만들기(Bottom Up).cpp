#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int * memo = new int [1000001];

	memo[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		memo[i] = memo[i-1] + 1;
		if (i % 2 == 0 && memo[i / 2] < memo[i])
			memo[i] = memo[i / 2]+1;
		if (i % 3 == 0 && memo[i / 3] < memo[i])
			memo[i] = memo[i / 3]+1;
	}

	cout << memo[n]<< '\n';

	return 0;
}