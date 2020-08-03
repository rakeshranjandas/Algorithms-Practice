#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> st) {

	string t = "";
	while (!st.empty()) {
		auto popped = st.top();
		t = to_string(popped) + ", " + t;
		st.pop();
	}

	cout << t << endl;
}

string minimal(string s) {

	vector<pair<char, int>> v;
	for (int i = 0; i < s.length(); i++) {
		v.push_back({s[i], i});
	}

	sort(v.begin(), v.end());
	stack<int> st;
	string u = "";
	int ind = 0, nextIndex;

	for (auto x: v) {
		cout << x.first << "(" << x.second << "), ";

		nextIndex = x.second;



		while (!st.empty() && st.top() <= ind) {
			
			u += s[st.top()];
			cout << "XXXXXXXXX " << st.top() << endl;
			st.pop();

		} 

		if (nextIndex >= ind) {

			// Push till prev of nextIndex
			for (int i = ind; i < nextIndex; i++)
				st.push(i);

			u += s[nextIndex];
			ind = nextIndex + 1;
		}

		cout << "Stack : ";
		printStack(st);
		cout << "    - " << u << endl;
	}

		printStack(st);

	while (!st.empty()) {
		u += s[st.top()];
		st.pop();
	}

	return u;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	cout << minimal(s) << endl;

	return 0;
}