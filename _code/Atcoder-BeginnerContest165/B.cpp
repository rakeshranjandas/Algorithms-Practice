#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	double x;
	cin >> x;

	double a = 100;
	int years = 0;

	while (a < x) {
		a = floor(a + a*0.01);
		years++;
	}

	cout << years << endl;

	return 0;
}