#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

vector<int> primes;
#define N 10000001
bool a[N];

void init(int n) {
	for (int i = 2; i < N && n; i++) {
		if (a[i])
			continue;

		cout << i << " ";
		n--;

		for (int k = 2; i*k < N && n; k++)
			a[i*k] = true;
	}
}

int main() {

	IOS

	int n;
	cin >> n;

	init(n);

	return 0;
}