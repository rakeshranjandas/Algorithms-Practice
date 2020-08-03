#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

int main() {

	FILE_WR;
	IOS;

	int n;
	cin >> n;

	map<int, set<int>> m;
	int p, d_p;

	for (int i = 0; i < 10; i++) {
		cin >> p;

		for (int j = 0; j < 9; j++) {
			cin >> d_p;

			m[min(p, d_p)].insert(max(p,d_p));
		}
	}

	// for (auto x: m) {
	// 	cout << x.first << ": ";
	// 	for (auto y: x.second)
	// 		cout << y << " ";
	// 	cout << endl;
	// }

	long long int count = ((long long int)(n-1) * n) / 2;
	for (auto x: m) {
		count -= x.second.size();
		
	}

	cout << max((long long int) 0, count) << endl;

	return 0;
}