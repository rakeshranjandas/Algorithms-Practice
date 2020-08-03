#include<iostream>
#include<string>
using namespace std;

string removeAdjDup(string &s, int index, bool has_dup = false) {

	cout << "s " << s << ", index " << index << ", has_dup " << has_dup << endl;

	if (index == s.size() && !has_dup)
		return s;

	if (index == 0)
		return removeAdjDup(s, 1, false);

	if (!has_dup && s[index] == s[index-1])
		has_dup = true;

	else if (has_dup && s[index] != s[index-1]) {
		cout << "here ";

		// remove all duplicates
		char dup_el = s[index-1];
		int index_to_del = index-1;

		while (s[index_to_del] == dup_el)
			s.erase(s.begin() + (index_to_del--));

		// reinitialize has_dup
		has_dup = false;

		// Recursion
		return removeAdjDup(s, index_to_del+1, has_dup);

	}
		
	return removeAdjDup(s, index+1, has_dup);
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

		cout << removeAdjDup(s, 0) << endl;
	}

	return 0;
}