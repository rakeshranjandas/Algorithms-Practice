#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

string generateMid(int n) {
	string s = "";
	for (int i = 0; i < n-1; i++)
		s += '1';

	return '0' + s;
}

string generateOneGreater(string &s, bool* out_of_range) {
	string res = "";
	int carry = 1, cur_sum; 
	bool one_one = false;
	*out_of_range = false;

	for (int i = s.size()-1; i >= 0; i--) {
		cur_sum = (s[i] - '0') + carry;

		if (cur_sum == 2) {
			cur_sum = 0;
			carry = 1;

		} else {
			carry = 0;
		}

		if (cur_sum == 1)
			one_one = true;

		// deb(cur_sum);

		res = (char)(cur_sum + '0') + res;
	}

	if (!one_one) {
		*out_of_range = true;
		return "";
	}

	return res;
}

string generateOneSmaller(string &s, bool *out_of_range) {
	string res = s;
	auto it = s.rfind("1");
	*out_of_range = false;

	if (it == string::npos) {
		*out_of_range = true;
		return "";
	}

	// deb(it);
	res[it] = '0';
	for (int i = it+1; i < s.size(); i++)
		res[i] = '1';

	return res;
}

string generateValid(string &median, set<string> &used, int type, bool *can_find_median) {
	*can_find_median = true;

	bool out_of_range;
	string new_median = median;

	do {
		if (type == 0) {
			new_median = generateOneSmaller(new_median, &out_of_range);

		} else {
			new_median = generateOneGreater(new_median, &out_of_range);
		}

		// deb(new_median);

		if (out_of_range) {
			*can_find_median = false;
			return "";
		}

	} while (used.find(new_median) != used.end());

	return new_median;
}

int main() {

	IOS

	// bool cn;
	// string ss = "101";

	// cout << generateOneGreater(ss, &cn) << "-";

	// cout << generateOneSmaller(ss, &cn) << "-";

	// cout << cn << endl;

	// return 0;

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		// for (int i = 0; i < n; i++)
		// 	cout << s[i] << endl;
		// cout << endl;

		string median = generateMid(m);

		// deb(median);

		int lec = 0, rec = 0;
		bool can_find_median;
		set<string> used;

		for (int i = 0; i < n; i++) {
			// deb(i);

			used.insert(s[i]);

			if (s[i] < median) {
				lec++;
			} else {
				rec++;
			}

			while (!(rec == lec || (rec - lec) == 1) || s[i] == median) {

				if (s[i] == median) {

					if (lec == rec) {

						// cout << "find smaller " << endl;

						median = generateValid(median, used, 0, &can_find_median);

					} else {

						// cout << "find greater " << endl;

						median = generateValid(median, used, 1, &can_find_median);

					}

					if (!can_find_median)
						break;

				} else if (rec > lec) {
					rec--;
					lec++;

					// cout << "find smaller " << endl;

					median = generateValid(median, used, 0, &can_find_median);

					if (!can_find_median)
						break;

				} else {
					lec--;
					rec++;

					// cout << "find greater " << endl;

					median = generateValid(median, used, 1, &can_find_median);

					if (!can_find_median)
						break;
				}	
			}


			if (!can_find_median)
				break;
		}

		// cout << "ans " << (!can_find_median ? "-1" : median) << endl << endl;
		cout << median << endl;

	}

	return 0;
}