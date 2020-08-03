#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 1000000001
vector<int> fib;

vector<int> genFib() {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);

	int fi = 0, fj = 1;

	while (fj < N) {
		int temp = fj;
		fj = fi + fj;
		fi = temp;

		v.push_back(fj);
	}

	// for (int x: v)
	// 	cout << x << " ";

	return v;
}

int main() {

	IOS

	int n;
	cin >> n;

	fib = genFib();

	bool found = false;

	for (int i = 0; i < fib.size() && !found; i++) {
		for (int j = 0; j < fib.size() && !found; j++) {
			for (int k = 0; k < fib.size() && !found; k++) {
				if (fib[i] + fib[j] + fib[k] == n) {
					cout << fib[i] << " " << fib[j] << " " << fib[k];
					found = true;
				}
			}
		}
	}

	if (!found)
		cout << "I'm too stupid to solve this problem";

	return 0;
}