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
	int ip;

	for (int i = 1; i <= n; i++) {
		cin >> ip;
		q.push({ip, i});
	}

	while (q.size() > 1) {
		auto popped = q.front();
		q.pop();

		popped.first -= m;

		if (popped.first > 0)
			q.push({popped});
	}

	cout << q.front().second;

	return 0;
}