#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

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

	int q;
	cin >> q;

	int q_type;

	for (int i = 0; i < q; i++) {

		cin >> q_type;

		if (q_type == 1) {
			int ind, new_num;
			cin >> ind >> new_num;

			s[ind-1] = new_num + '0';

		} else {

			int l, r, x;
			cin >> l >> r >> x;

			string ss = s;

			long long int sum = 0;

			for (auto x: ss)
				sum += (x-'0');
			
			int digit_required = 9 - (sum%9);
			// ss += (digit_required + '0');

			char char_array[ss.length()];
			strcpy(char_array, ss.c_str());

			sort(char_array+l-1, char_array+r, greater<char>());

			// deb(s);
			// deb(char_array);

			ss = char_array;
			// deb(ss);

			for (int i = 0; i < ss.length(); i++) {
				if (ss[i] - '0' < digit_required) {
					ss.insert(i, 1, digit_required+'0');
					break;
				}
			}

			cout << ss[x-1] << endl;
		}
	}

	return 0;
}