#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

string numInParentheses(int n) {
	string ms = "";

	for (int i = 0; i < n; i++)
		ms += "(";

	ms += to_string(n);

	for (int i = 0; i < n; i++)
		ms += ")";

	return ms;
}

string stackDump(stack<char> &st) {
	string res = "";

	while (!st.empty()) {
		char popped = st.top();
		res =  popped + res;
		st.pop();
	}

	return res;
}

string modifiedString(string &s) {
	
	stack<char> st;

	for (auto ch: s) {
		int num = ch-'0';

		string ps = numInParentheses(num);
		int ps_i = 0;

		while (ps_i < ps.size()) {
			char ps_ch = ps[ps_i];

			if (st.empty())
				st.push(ps_ch);

			else if (st.top() == ')' && ps_ch == '(')
				st.pop();

			else
				st.push(ps_ch);

			ps_i++;
		}
	}

	return stackDump(st);
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {

		string s;
		cin >> s;

		cout << "Case #" << t_i << ": " << modifiedString(s) << endl;
	}

	return 0;
}