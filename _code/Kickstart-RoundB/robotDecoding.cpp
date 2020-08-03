#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 1000000000

typedef long long int ll;
typedef pair<ll, ll> pi;

string stringify(pi p) {
	return to_string(p.second+1) + " " + to_string(p.first+1);
}

bool isNumber(char c) {
	return c >= '0' && c <= '9';
}

pi getMove(char move) {
	int mx, my;

	switch(move) {
		case 'N':
			mx = -1, my = 0;
			break;

		case 'S':
			mx = 1, my = 0;
			break;

		case 'W':
			mx = 0, my = -1;
			break;

		case 'E':
			mx = 0, my = 1;
			break;
	}

	return {mx, my};
}

pi multXY(int m, pi p) {
	ll x = (((m * p.first) % N) + N) % N;
	ll y = (((m * p.second) % N) + N) % N;

	return {x, y};
}

pi addXY(pi xy, pi movexy) {
	ll x = (xy.first + movexy.first + N) % N;
	ll y = (xy.second + movexy.second + N) % N;
	return {x, y};
}

pi finalPos(string s) {
	// deb(s);

	pi xy = {0, 0};

	for (int i = 0; i < s.size(); i++)	{

		if (isNumber(s[i])) {
			int start_paren = i+1, mult = s[i] - '0';
			int depth = 1, end_paren;

			for (end_paren = start_paren+1; end_paren < s.size(); end_paren++) {

				if (s[end_paren] == '(')
					depth++;

				else if(s[end_paren] == ')') {
					depth--;
					if (depth == 0)
						break;
				}
			}

			pi moveset_inner = finalPos(s.substr(start_paren+1, end_paren-start_paren-1));
			pi moveset_multiplied = multXY(mult, moveset_inner);

			// cout << " --- " << s.substr(start_paren+1, end_paren-start_paren-1) << endl;
			// cout << "moveset_inner " << stringify(moveset_inner) << endl;
			// cout << "moveset_multiplied " << stringify(moveset_multiplied) << endl;

			xy = addXY(xy, moveset_multiplied);

			i = end_paren;

		} else {
			xy = addXY(xy, getMove(s[i]));
		}
	}

	return xy;
}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		string s;
		cin >> s;

		cout << "Case #" << t_i << ": " << stringify(finalPos(s)) << endl;
	}

	return 0;
}