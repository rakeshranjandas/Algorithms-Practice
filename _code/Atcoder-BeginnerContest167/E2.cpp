#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

class CO {
	public:
	int net, open, close;
	
	CO(int c, int o) {
		open = o;
		close = c;
		net = open-close;
	}

	void printCO() {
		cout << "(" << close << "," << open << " " << net << ")" << endl;
	}
};

class compCO {
	public:

	bool operator() (CO a, CO b) {
		return a.net == b.net ? a.close < b.close: a.net > b.net;
		// return a.close == b.close ? a.open > b.open : a.close < b.close;
	}
};

CO makeCO(string &s) {
	int oc = 0, cc = 0;
	for (char x: s) {
		if (x == '(')
			oc++;
		else
			cc++;
	}

	return CO(cc, oc);
}

void shorten(string &s) {
	stack<char> st;
	for (char x: s) {
		if (st.empty())
			st.push(x);
		
		else {
			if (x == ')' && st.top() == '(')
				st.pop();

			else
				st.push(x);
		}		
	}

	s = "";
	while (!st.empty()) {
		s = st.top() + s;
		st.pop();
	}
}

int main() {

	IOS

	int n;
	cin >> n;

	string s[n];

	for (int i = 0; i < n; i++)
		cin >> s[i];


	int pos = 0, neg = 0;
	vector<CO> v;

	for (int i = 0; i < n; i++) {
		shorten(s[i]);

		// deb(s[i]);

		int open_found = s[i].find('(');
		int close_found = s[i].find(')');

		if (open_found != string::npos && close_found != string::npos) {
			v.push_back(makeCO(s[i]));

		} else if (open_found != string::npos) {
			pos += s[i].size();

		} else {
			neg += s[i].size();
		}
	}

	// deb(pos);
	// deb(neg);

	sort(v.begin(), v.end(), compCO());

	// for (auto x: v)
	// 	x.printCO();

	int cur_depth = pos;
	bool can = true;

	for (auto x: v) {
		if (pos < x.close) {
			can = false;
			// cout << "broken at " << pos ;
			// x.printCO();
			break;
		}

		pos += x.net;
	}

	// deb(pos);

	if (can) {
		if (pos != neg)
			can = false;
	}

	cout << (can ? "Yes" : "No") << endl;


	return 0;
}