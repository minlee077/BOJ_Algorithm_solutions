#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dists[200001];
long long int cnts[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	memset(dists, -1, sizeof(dists));

	dists[n] = 0;
	cnts[n] = 1;
	queue <int> q;
	q.push(n);

	while (!q.empty())
	{
		int now = q.front(); q.pop();

		int next = now + 1;
		if (0 < next && next < 200001)
		{
			if (dists[next] == -1)
			{
				dists[next] = dists[now] + 1;
				cnts[next] = cnts[now];
				q.push(next);
			}
			else if (dists[next] == dists[now] + 1)
				cnts[next] += cnts[now];
		}

		next = now - 1;
		if (0 < next && next < 200001)
		{
			if (dists[next] == -1)
			{
				dists[next] = dists[now] + 1;
				q.push(next);
				cnts[next] = cnts[now];
			}
			else if (dists[next] == dists[now] + 1)
				cnts[next] += cnts[now];
		}

		next = now * 2;
		if (0 < next && next < 200001)
		{
			if (dists[next] == -1)
			{
				dists[next] = dists[now] + 1;
				q.push(next);
				cnts[next] = cnts[now];
			}
			else if (dists[next] == dists[now] + 1)
				cnts[next] += cnts[now];
		}
	}
	cout << dists[k] << '\n';
	cout << cnts[k] << '\n';

	return 0;
}