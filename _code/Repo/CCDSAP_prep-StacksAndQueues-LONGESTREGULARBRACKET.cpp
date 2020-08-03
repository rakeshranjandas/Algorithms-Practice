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

void printStackPair(stack<pair<char, int>> st) {

	string t = "";
	while (!st.empty()) {
		auto popped = st.top();
		t = popped.first + "(" + string(1,popped.second) + "), " + t;
		st.pop();
	}

	cout << t << endl;
}

void longestRegBracket(string s) {

	stack<int> st_ind;
	stack<pair<char, int>> st;

	st.push({')', -1});

	int max_len = 0, count = 0;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == ')' && st.top().first == '(') {
			auto popped = st.top();
			st.pop();

			int len = (i- st.top().second);

			if (len > max_len) {
				max_len = len;
				count = 1;

			} else if (len == max_len) {
				count++;				
			}


		} else {
			st.push({s[i], i});
		}
	}

	// printStack(st_ind);

	if (max_len) 
		cout << max_len << " " << count << endl;

	else
		cout << "0 1" << endl;
} 

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

	longestRegBracket(s);
	cout << endl;

	return 0;
}