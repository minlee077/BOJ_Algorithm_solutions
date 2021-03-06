#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
/*
Problem
N개의 수로 이루어진 수열 A[1], A[2], …, A[N]이 있다. 이 수열에 대해서 버블 소트를 수행할 때, Swap이 총 몇 번 발생하는지 알아내는 프로그램을 작성하시오.

버블 소트는 서로 인접해 있는 두 수를 바꿔가며 정렬하는 방법이다. 예를 들어 수열이 3 2 1 이었다고 하자. 이 경우에는 인접해 있는 3, 2가 바뀌어야 하므로 2 3 1 이 된다. 다음으로는 3, 1이 바뀌어야 하므로 2 1 3 이 된다. 다음에는 2, 1이 바뀌어야 하므로 1 2 3 이 된다. 그러면 더 이상 바꿔야 할 경우가 없으므로 정렬이 완료된다.

Input
첫째 줄에 N(1≤N≤500,000)이 주어진다. 다음 줄에는 N개의 정수로 A[1], A[2], …, A[N]이 주어진다. 각각의 A[i]는 0≤|A[i]|≤1,000,000,000의 범위에 들어있다.

Output
첫째 줄에 Swap 횟수를 출력한다

Description
단순히 직접 버블소트를 수행하며, 스왑되는 횟수를 카운팅하면, 시간초과가 발생한다.

따라서, 다른 소팅알고리즘을 활용해서 접근해야한다.

우선 버블소트의 특징을 확인해보면,
1. 가장 큰 수가 발견되면, 가장 큰 수는 뒤의 위치한 모든 수와 한번씩 스왑이 발생한다.
2. 한번의 순회에서, 앞으로 이동하는 스왑 대상의 수는 한번만 이동한다. 이와 달리, 앞에서 뒤로가는 수의 경우 한번의 순회에서 여러번 이동할 수 있다.
3. 정렬이 수행되기 위해서는 왼쪽에 있는 수는 오른쪽에 자신 보다 작은수와 반드시 스왑이 발생할 수 밖에 없다.

머지소트에서 머지 과정을 생각해보면 위의 특징과 유사하다.
머지 과정에서 오른쪽 파티션에 존재하는 각 수는 앞에 위치하게 될 것이고 이는 왼쪽 파티션에 잔여하는 수의 개수만큼 스왑이 발생할 것이다.
반대로, 왼쪽 파티션에서 존재하는 수들은 할당시에 별다른 추가적인 스왑이 발생할 필요가 없다.

즉, 왼쪽파티션에 수들이 실제 배열의 왼쪽편에 이미 존재하고 있는 수들이라고 가정하고, 오른쪽 파티션에서 수를 하나씩 빼서, 각각의 자리로 이동시켜주는 과정을 카운팅하면, 동일하게 스왑 발생횟수를 판단할 수 있다.
버블 소트와 다른 점은 버블소트의 경우 왼쪽편에 정렬된 배열이 결정되어 있는 상태에서 하나의 수가 투입이 될때, 몇번이 스왑이 발생할지를 상수시간안에 판단할 수 가 없다. 
반대로, 머지소트의 경우 각각의 파티션에 대한 정보를 파악하고 포인터를 이동시키면서 접근하므로, 스왑발생 횟수를 상수시간 안에 판단할 수 있다.

이와 유사한 접근 방식으로 컴파일러에서 연산자 우선순위를 판단하여, 전위식을 후위식으로 바꾸는 과정에서도 비슷한 원리가 이용되고, 다항식을 표현하여 다항식 덧셈을 구현할때도 비슷한 방식이 이용된다.

https://www.acmicpc.net/problem/1517
*/
#include <iostream>
#include <vector>

using namespace std;

long long int mergeSort(vector<long long int>&a, int first, int last)
{
	long long int cnt = 0;
	if (last-first<=0)
		return 0;
	int mid = (first + last) / 2; // divide

	cnt += mergeSort(a,first,mid);
	cnt += mergeSort(a,mid+1,last); // conquer

	//combine (merge)
	int fptr = first;
	int lptr = mid + 1;

	vector <long long int> c(last - first + 1);
	int i = 0;
	while (fptr <= mid && lptr <= last)
	{
		if (a[fptr] > a[lptr])
		{
			c[i] = a[lptr];
			cnt += mid - fptr + 1;
			lptr++;
		}
		else
		{
			c[i] = a[fptr];
			fptr++;
		}
		i++;
	}

	while (fptr <= mid)
	{
		c[i] = a[fptr];
		fptr++,i++;
	}

	while (lptr <= last)
	{
		c[i] = a[lptr];
		lptr++,i++;
	}
	i = 0;
	for (int j = first; j <= last; j++,i++)
		a[j] = c[i];

	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int _size;
	cin >> _size;
	vector <long long int> a(_size);
	for (int i = 0; i < _size; i++)
		cin>>a[i];
	cout<<mergeSort(a, 0, _size-1)<<'\n';

	return 0;
}