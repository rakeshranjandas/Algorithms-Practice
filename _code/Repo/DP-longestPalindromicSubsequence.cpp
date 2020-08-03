#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool isPal(string s) {
	int l = 0, r = s.size()-1;

	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}

	return true;
}

void palSubseq(string till_now, string s, int now_ind, int *max_subseq_len) {

	if (now_ind >= s.size()) {
		cout << till_now << " <" << endl;
		return;
	}

	string now_str = till_now + s[now_ind];
	int now_str_size = now_str.size();

	// cout << now_str << " " << now_str_size << endl;

	if(isPal(now_str))
		*max_subseq_len = max(*max_subseq_len, now_str_size);

	palSubseq(now_str, s, now_ind+1, max_subseq_len);
	palSubseq(till_now, s, now_ind+1, max_subseq_len);
}

int longestPalSubseq(string s) {
	int max_subseq_len = 0;
	palSubseq("", s, 0, &max_subseq_len);

	return max_subseq_len;
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

		cout << longestPalSubseq(s) << endl;
	}

	return 0;
}