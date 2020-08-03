#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string s;
	cin >> s;

	set<char> st;
	for (char x: s)
		st.insert(x);

	if (st.size()%2 == 0)
		cout << "CHAT WITH HER!" << endl;
	else
		cout << "IGNORE HIM!" << endl;

	return 0;
}