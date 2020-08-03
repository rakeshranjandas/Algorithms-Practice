#include<iostream>
using namespace std;
bool overall_dup_detected;

string removeAdjDup(string s, int level, string formed, bool dup_detected = false) {

	cout << "s " << s << " level " << level << "formed " << formed 
		<< " dup_detected " << dup_detected
		<< " overall_dup_detected " << overall_dup_detected
		<< endl;
	
	if (s.size() == 0)
		return "";

	if (level == s.size()) {

		if (dup_detected){
			formed.erase(formed.begin() + formed.size() - 1);
			if (formed.size() == 0)
				return "";

		} else if (!overall_dup_detected) {
			return formed;
		}

		overall_dup_detected = false;

		return removeAdjDup(formed, 1, string(1, formed[0]));
	}

	if (!dup_detected && s[level] == formed[formed.size()-1]) {
		dup_detected = true;
		overall_dup_detected = true;


	} else if (dup_detected) {

		if (s[level] != formed[formed.size()-1]) {
			dup_detected = false;
			formed.erase(formed.begin() + formed.size() - 1);
			formed += s[level];
		}

	} else
		formed += s[level];

	return removeAdjDup(s, level+1, formed, dup_detected);
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

		overall_dup_detected = false;
		cout << removeAdjDup(s, 1, string(1, s[0])) << endl;
	}

	return 0;
}