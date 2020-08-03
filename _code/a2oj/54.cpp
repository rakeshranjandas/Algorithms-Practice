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

	string res = to_string(n);

	for (int i = 1; i < n; i++)
		res += " " + to_string(i);

	cout << res;

	return 0;
}