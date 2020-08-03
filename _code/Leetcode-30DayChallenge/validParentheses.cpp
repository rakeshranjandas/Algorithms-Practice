#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool isValid(string &s) {

	int n = s.size();
	int count_closed = 0, count_open = 0, count_star = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			count_closed++;
			
			if (count_open + count_star < count_closed)
				return false;

		} else if (s[i] == '(')
			count_open++;

		else if (s[i] == '*')
			count_star++;
	}
	
	int count_closed_rev = 0, count_open_rev = 0, count_star_rev = 0;

	for (int i = n-1; i >= 0; i--) {
		if (s[i] == ')')
			count_closed_rev++;
		
		else if (s[i] == '(') {
			count_open_rev++;

			if (count_closed_rev + count_star_rev < count_open_rev)
				return false;

		} else if (s[i] == '*')
			count_star_rev++;
	}

	return true;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		cout << isValid(s) << endl;
	}

	return 0;
}