#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 1000001

typedef long long int ll;

ll ans[N];

void pre() {
	ans[1] = 1;

	for (int i = 2; i < N; i++) {
		if (i%3 == 0 || i%5 == 0)
			ans[i] = ans[i-1];
		else
			ans[i] = ans[i-1] + i;
	}

	// for (int i = 0; i < N; i++)
	// 	cout << ans[i] << " ";
	// cout << endl;
}

int main() {

	IOS

	pre();

	int n;
	cin >> n;

	cout << ans[n];

	return 0;
}