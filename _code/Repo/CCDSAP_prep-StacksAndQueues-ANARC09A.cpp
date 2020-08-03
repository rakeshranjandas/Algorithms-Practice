#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printStack(stack<char> st) {

	string t = "";
	while (!st.empty()) {
		t = string(1, st.top()) + " " + t;
		st.pop();
	}

	cout << t << endl;
}

int stable(string s) {

	int d = 0, c = 0;

	for (char x: s) {

		if (x == '{')
			d++;
		else
			d--;

		if (d < 0) {
			d = 1;
			c++;
		}

		// cout << x << " d=" << d << " c=" << c << endl;
	}

	c += d/2;

	return c;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int i = 1;

	while (true) {
		string s;
		cin >> s;

		if (s[0] == '-')
			break;

		cout << i++ << ". " << stable(s) << endl;
	}

	return 0;
}