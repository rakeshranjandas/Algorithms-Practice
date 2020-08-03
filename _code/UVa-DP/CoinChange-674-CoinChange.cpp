#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 5
#define V 7490
int coin[N] = {1, 5, 10, 25, 50};
ll ways[V];

void init() {
	for (int i = 0; i < N; i++) {
		ways[coin[i]]++;

		for (int j = 1; j+coin[i] < V; j++) {
			if (!ways[j])
				continue;

			ways[j+coin[i]] += ways[j];
		}
	}
}

int main() {

	IOS

	init();

	int n;
	while (cin >> n) {
		cout << (n == 0 ? 1 : ways[n]) << endl;
	}

	return 0;
}