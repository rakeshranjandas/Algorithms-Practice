#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int k, a, b;
	cin >> k >> a >> b;

	int lm = (a / k) * k;
	
	if (lm < a)
		lm += k;

	cout << (lm >= a && lm <= b ? "OK" : "NG") << endl;

	return 0;
}