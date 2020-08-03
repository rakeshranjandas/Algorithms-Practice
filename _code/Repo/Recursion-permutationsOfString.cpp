#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> v;

void permute(string s, vector<int> used_arr,
	int cur_pos, int cur_ind, string formed) {

	if (cur_pos == s.size()) {
		v.push_back(formed);
		return;
	}

	if (cur_ind != -1)
		used_arr[cur_ind] = 1;

	for (int i = 0; i < s.size(); i++) {
		if (used_arr[i] == 0) {
			
			permute(s, used_arr, cur_pos+1, i, formed + s[i]);
		}
	}
}

void findPermutations(string s) {

	v.clear();
	vector<int> used_arr(s.size(), 0);

	permute(s, used_arr, 0, -1, "");

	sort(v.begin(), v.end());

	for (auto x: v)
		cout << x << " ";
	cout << endl;
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
		string s;
		cin >> s;
		findPermutations(s);
	}

	return 0;
}