#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 10000

vector<int> pieces(N);

void init() {
	pieces[0] = 1;

	for (int i = 1; i < N; i++)
		pieces[i] = pieces[i-1] + i;

	// for (auto x: pieces)
	// 	cout << x << " ";
}

int main() {

	IOS

	init();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << pieces[n] << endl;
	}

	return 0;
}