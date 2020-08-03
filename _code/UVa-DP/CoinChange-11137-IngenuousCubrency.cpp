#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 21
#define V 10001
ll ways[V];

void init() {
	for (int i = 1; i <= N; i++) {
		ll coin_val = i*i*i;

		ways[coin_val]++;

		for (int j = 1; j+coin_val < V; j++) {
			if (!ways[j])
				continue;
			ways[j+coin_val] += ways[j]; 
		}
	}
}

int main() {

	IOS

	init();

	int n;
	while (cin >> n)
		cout << (n == 0 ? 1 : ways[n]) << endl;

	return 0;
}