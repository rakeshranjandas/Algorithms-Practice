#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

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
		string s;
		cin >> s;

		set<int> v;

		for (int i = 0; i < s.size(); i++) {
			if (vowels.find(s[i]) != vowels.end())
				v.insert(i+1);
		}

		int q;
		cin >> q;

		char command;
		while (q--) {

			// for (auto x: v) {
			// 	cout << x << " ";
			// }
			// cout << endl;
			
			cin >> command;
			if (command == 'U') {
				int index;
				char up;
				cin >> index >> up;

				if (vowels.find(up) != vowels.end()) {
					v.insert(index);

				} else {
					if (v.find(index) != v.end())
						v.erase(index);
				}

			} else {
				int l_index, r_index;
				cin >> l_index >> r_index;

				set<int> :: iterator l, r;
				l = v.lower_bound(l_index);

				r = v.lower_bound(r_index);
				if (v.find(r_index) != v.end())
					r++;

				// cout << "l " << distance(v.begin(), l) << endl;
				// cout << "r " << distance(v.begin(), r) << endl;
				cout << distance(l, r) << endl;
			}
		}

	}

	return 0;
}