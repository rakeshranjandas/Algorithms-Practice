#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 5
#define V 30001
ll ways[V];
int coin[N] = {1, 5, 10, 25, 50};

void init() {
	for (int i = 0; i < N; i++) {
		ways[coin[i]]++;

		for (int j = 1; j+coin[i] < V; j++) {
			if (!ways[j])
				continue;

			ways[j+coin[i]] += ways[j];
		}
	}

	// for (int i = 0; i < V; i++)
	// 	cout << "(" << i << ")" << ways[i] << " ";
	// cout << endl;
}

int main() {

	IOS

	init();

	int n;

	while (cin >> n) {
		ll w = ways[n];

		if (n == 0 || w == 1)
			cout << "There is only 1 way to produce " << n << " cents change." << endl;

		else
			cout << "There are " << w << " ways to produce " << n << " cents change." << endl;
	}

	return 0;
}