#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

string gen(int n) {
	string res = "";
	string s;

	for (int i = 0; i < n; i++)
		res += to_string(i) + " ";

	s = res + to_string(n);
	reverse(res.begin(), res.end());
	s += res;

	return s;
}

int main() {

	IOS

	int n;
	cin >> n;

	string s, t, u;
	vector<string> v(n);

	for (int i = n; i >= 0; i--) {
		s = string(2*i, ' ');
		s += gen(n-i);
		v.push_back(s);
		cout << s << endl;
	}

	for (int i = v.size()-2; i >= 0; i--)
		cout << v[i] << endl;

	return 0;
}