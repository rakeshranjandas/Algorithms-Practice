#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> p_map;

bool isOperator(char c) {
	bool ret = false;

	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')':
			ret = true;
			break;
	}

	return ret;
}

bool isClosingBracket(char c) {
	return c == ')';
}

bool isOpeningBracket(char c) {
	return c == '(';
}

void initPMap() {
	p_map = {
		{'(', 0},
		{'+', 1},
		{'-', 2},
		{'*', 3},
		{'/', 4},
		{'^', 5},
	};
}

int priority(char c) {
	return p_map[c];
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	initPMap();

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		stack<char> st;
		string op = "";

		for (char x: s) {
			if (!isOperator(x))
				op += x;

			else {

				if (st.empty())					
					st.push(x);

				else {

					if (isOpeningBracket(x)) {
						st.push(x);

					} else if(isClosingBracket(x)) {
						
						// pop till opening bracket
						while (!st.empty()) {
							if (isOpeningBracket(st.top())) {
								st.pop();
								break;
							}

							op += st.top();
							st.pop();
						}

					} else if (priority(st.top()) < priority(x)) {
						st.push(x);

					} else {

						// pop till low priority
						while (!st.empty() && priority(st.top()) > priority(x)) {
							op += st.top();
							st.pop();
						}

						st.push(x);
					}
				}
			}
		}

		while (!st.empty()) {
			op += st.top();
			st.pop();
		}

		cout << op << endl;
	}

	return 0;
}