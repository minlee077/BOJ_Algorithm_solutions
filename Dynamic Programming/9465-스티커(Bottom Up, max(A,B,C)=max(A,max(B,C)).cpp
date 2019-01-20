/*
Problem
상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다. 스티커는 그림 (a)와 같이 2행 n열로 배치되어 있다. 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.

상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다. 즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.

모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다. 
먼저, 그림 (b)와 같이 각 스티커에 점수를 매겼다. 상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오. 
즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.

위의 그림의 경우에 점수가 50, 50, 100, 60인 스티커를 고르면, 점수는 260이 되고 이 것이 최대 점수이다. 가장 높은 점수를 가지는 두 스티커 (100과 70)은 변을 공유하기 때문에, 동시에 뗄 수 없다.

Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다. 
다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다.
연속하는 두 정수 사이에는 빈 칸이 하나 있다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다. 

Output
각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.

Description
D[i] : i번째 열에 도달했을때 최대점수
D[i][0] : i번째 열에 스티커 위
D[i][1] : i번재 열에 스티커 아래
D[i][2] : i번째 열에 스티커 x

D[i][0] =  max(D[i-1][1], D[i-1][2]) + a[i][0];
D[i][1] =  max(D[i-1][0], D[i-1][2]) + a[i][1];
D[i][2] =  max(D[i-1][0], D[i-1][1], D[i-1][2]);

* #define max(a,b) (((a)>(b))?(a):(b))를 사용해도 된다.
d[i][0] = max(d[i-1][0],max(d[i-1][1],d[i-1][2]));


*/
#include <iostream>
#include <algorithm>

using namespace std;

long long int D[100001][3];
int a[100001][2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n;
	cin >> T;

	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][0];
		for (int i = 1; i <= n; i++)
			cin >> a[i][1];

		for (int i = 1; i <= n; i++)
		{
			D[i][0] = max(D[i - 1][1], D[i - 1][2]) + a[i][0];
			D[i][1] = max(D[i - 1][0], D[i - 1][2]) + a[i][1];

			D[i][2] = D[i - 1][0];
			if(D[i][2]<D[i-1][1])
				D[i][2] = D[i - 1][1];
			if (D[i][2] < D[i - 1][2])
				D[i][2] = D[i - 1][2];

		}

		cout << max(D[n][1],max(D[n][2],D[n][0]))<<'\n';

	}

	return 0;
}