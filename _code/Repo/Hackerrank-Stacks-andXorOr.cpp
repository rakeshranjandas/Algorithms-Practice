#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> st) {
	// return;

	string out = "";

	while (!st.empty()) {
		out = st.top() + ", " + out;
		st.pop();
	}

	cout << out << endl;
}

int calculate(int a, int b) {
	return (((a & b) ^ (a | b)) & (a ^ b));
}

int andXorOr(vector<int> v) {

	stack<int> st;
	int max_value = 0;

	for (int i = 0; i < v.size(); i++) {
		
		while (!st.empty()) {

			max_value = max(max_value, calculate(v[i], st.top()));

			if (v[i] < st.top()) {
				st.pop();

			} else {
				break;
			}
		}

		st.push(v[i]);
	}

	return max_value;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v;
	int ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		v.push_back(ip);
	}

	cout << andXorOr(v) << endl;

	return 0;
}