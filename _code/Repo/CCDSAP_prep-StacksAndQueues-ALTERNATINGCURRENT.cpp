#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

	// #ifndef ONLINE_JUDGE
	// 	freopen("../input.txt", "r", stdin);
	// 	freopen("../output.txt", "w", stdout);
	// 	#else
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	stack<char> st;

	for (int i = 0; i < s.length(); i++) {

		if (st.empty() || st.top() != s[i]) {
			st.push(s[i]);

		} else {
			st.pop();
		}
	}

	cout << (st.empty() ? "Yes" : "No") << endl;

	return 0;
}