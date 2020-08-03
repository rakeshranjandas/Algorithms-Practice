#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool isInterleave(string a, string b, string c) {

	if (c.size() == 0)
		return a.size() == 0 && b.size() == 0;

	bool matched_from_a = false;
	if (a[0] == c[0])
		matched_from_a = isInterleave(a.substr(1), b, c.substr(1));

	bool matched_from_b = false;
	if (b[0] == c[0])
		matched_from_b = isInterleave(a, b.substr(1), c.substr(1));

	return matched_from_a || matched_from_b;
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
		string a, b, c;
		cin >> a >> b >> c;

		cout << isInterleave(a, b, c) << endl;
	}

	return 0;
}