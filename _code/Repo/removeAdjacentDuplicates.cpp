#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeAdjDuplicates(string s) {

	int n = s.length();

	if (n == 1)
		return s;

	stack<char> st;
	bool dup = false;

	int i = 0;

	while (i < n) {

		if (st.empty())
			st.push(s[i++]);

		else {

			if (dup) {
				if (st.top() == s[i])
					i++;

				else {
					st.pop();
					dup = false;
				}

			} else {
				if (st.top() == s[i]) {
					dup = true;
					i++;

				} else
					st.push(s[i++]);
			}
		}
	}

	if (dup)
		st.pop();

	string res = "";
	while (!st.empty()) {
		res = st.top() + res;
		st.pop();
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		cout << removeAdjDuplicates(s) << endl;
	}

	return 0;
}