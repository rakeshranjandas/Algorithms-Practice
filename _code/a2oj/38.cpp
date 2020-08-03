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

	int minm = INT_MAX, min_c = 0, ip, min_i;

	for (int i = 0; i < n; i++) {
		cin >> ip;

		if (ip < minm) {
			minm = ip;
			min_i = i;
			min_c = 1;
		
		} else if (ip == minm) {
			min_c++;
		}
	}

	cout << (min_c == 1 ? to_string(min_i+1) : "Still Rozdil");

	return 0;
}