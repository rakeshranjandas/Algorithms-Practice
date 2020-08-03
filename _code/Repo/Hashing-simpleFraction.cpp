#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string simpleFraction(int n, int d) {

	string res = "";
	
	vector<int> dec;
	unordered_map<int, int> m; // {value, last_index}
	unordered_map<int, int> :: iterator it; // {value, last_index}

	int q = n / d;
	int r = n % d;
	int hasDec = (r % d) > 0;

	if (hasDec) {

		int nowq, i = 0, recDigitIndex = -1;

		while (r > 0) {
			r *= 10;
			it = m.find(r);

			if (it != m.end()) {
				// Found recurring point
				recDigitIndex = it->second;
				break;
			}

			dec.push_back(r / d);

			m[r] = i++;

			r %= d;
		}

		for (auto mm: m)
			cout << mm.first << "(" << mm.second << "), ";
		cout << endl;

		for (auto digit: dec)
			cout << digit;
		cout << endl;

		cout << recDigitIndex << " = r" << endl;

		res = ".";

		for (int v_i = 0; v_i < dec.size(); v_i++) {
			if (v_i == recDigitIndex)
				res += "(";

			res += (dec[v_i] + '0');
		}

		if (recDigitIndex != -1)
			res += ")";
	}

	res = to_string(q) + res;

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n, d;
		cin >> n >> d;

		cout << simpleFraction(n, d) << endl;
	}

	return 0;
}