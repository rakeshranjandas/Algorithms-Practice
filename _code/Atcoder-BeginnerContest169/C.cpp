#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	ll a;
	cin >> a;

	string b;
	cin >> b;

	int i;
	for (i = 0; i < b.size(); i++)
		if (b[i] == '.')
			break;
	int b_i = stoi(b.substr(0, i));
	int b_f = stoi(b.substr(i+1));

	ll res = (a * b_i) + ((a * b_f) / 100);
	
	cout << res << endl;

	return 0;
}