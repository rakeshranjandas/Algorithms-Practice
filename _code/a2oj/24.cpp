#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string g, h, p;
	cin >> g >> h >> p;

	g = g + h;
	sort(g.begin(), g.end());
	sort(p.begin(), p.end());

	cout << (g == p ? "YES" : "NO") << endl;

	return 0;
}