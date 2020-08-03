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

	queue<pair<int, int>> q;
	char ip;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ip;

			if (ip == '-') {
				q.push({i, j});
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!q.empty()) {			
				auto topped = q.front();
				if (topped.first == i && topped.second == j) {
					q.pop();
					cout << '-';
					continue;
				}
			}

			cout << ((i+j) % 2 == 0 ? 'B' : 'W');
				// << "(" << ((i+j)%2) << ")";
		}

		cout << endl;
	}

	return 0;
}