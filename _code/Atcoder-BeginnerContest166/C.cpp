#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, m;
	cin >> n >> m;

	int h[n+1];
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	vector<vector<int>> graph(n+1);
	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int c = 0;
	bool is_good;

	for (int i = 1; i <= n; i++) {

		is_good = true;

		for (int obs: graph[i]) {
			if (obs == i)
				continue;

			if (h[i] <= h[obs]) {
				is_good = false;
				break;
			}
		}

		if (is_good)
			c++;
	}

	cout << c << endl;

	return 0;
}