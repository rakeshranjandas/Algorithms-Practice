#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printStack(stack<string> st) {

	string t = "";
	while (!st.empty()) {
		t = st.top() + " " + t;
		st.pop();
	}

	cout << t << endl;
}

stack<string> expand(string s) {
	stack<string> st;

	for (char x: s) {

		if (x >= '2' && x <= '9') {
			string temp = st.top();
			int times = x - '0';

			for (int i = 0; i < times-1; i++)
				st.push(temp);

		} else if (x == '(') {
			st.push(string (1, x));

		} else if (x == ')') {

			string temp = "";

			// pop till (
			while (!st.empty() && st.top() != "(") {
				temp += st.top();
				st.pop();
			}

			// pop (
			st.pop();

			// push expanded string
			st.push(temp);

		} else {
			st.push(string (1, x));
		}

		// printStack(st);
	}

	return st;
}

int molMass(char c) {
	int ms = 0;
	switch(c) {
		case 'C':
			ms = 12;
			break;

		case 'H':
			ms = 1;
			break;

		case 'O':
			ms = 16;
			break;
	}

	return ms;
}

int findMolMass(string m) {

	int mass = 0;

	for (auto x: m) {
		mass += molMass(x);
	}

	return mass;
}

int findMass(stack<string> st) {

	int mass = 0;

	while (!st.empty()) {
		mass += findMolMass(st.top());
		st.pop();
	}

	return mass;
}

int mmass(string s) {

	stack<string> st = expand(s);

	// printStack(st);

	int mass = findMass(st);

	return mass;
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

	cout << mmass(s) << endl;

	return 0;
}