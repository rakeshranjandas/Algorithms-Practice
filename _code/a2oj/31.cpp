#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;

	int sum_f = 0, f; 
	for (int i = 0; i < n; i++) {
		cin >> f;
		sum_f += f;
	}

	int c = 0;

	for (int i = 1; i <= 5; i++) {
		if ((sum_f + i) % (n+1) != 1)
			c++;
	}

	cout << c;

	return 0;
}