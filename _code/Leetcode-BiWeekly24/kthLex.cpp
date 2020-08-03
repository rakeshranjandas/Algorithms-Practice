#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void solveUtil(string s, int cur, int n, vector<string> &v) {

	if (cur == n) {
		v.push_back(s);
		return;
	}

	for (int i = 0; i < 3; i++) {

		if (cur == 0)
			solveUtil(s + ((char)('a'+i)), cur+1,  n, v);

		else {
			if (s[s.size()-1] - 'a' != i)
				solveUtil(s + ((char)('a'+i)), cur+1,  n, v);				
		} 
	}
}

string solve(int n, int k) {
	string s = "";
	vector<string> v;

	solveUtil(s, 0, n, v);

	if (k > v.size())
		return "";

	sort(v.begin(), v.end());

	return v[k-1];
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		cout << solve(n, k) << endl;
	}

	return 0;
}