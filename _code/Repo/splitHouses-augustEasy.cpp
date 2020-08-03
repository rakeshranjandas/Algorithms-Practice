#include<iostream>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char s[20];
	for (int i = 0; i < 20; i++)
		s[i] = ' ';

	for (int i = 0; i < n; i++)
		cin >> s[i];

	string res = "";
	res += (s[0] != 'H' ? 'B' : s[0]);
	bool isPossible = true;

	for (int i = 1; i < n; i++) {
		if (s[i] == 'H' && s[i-1] == 'H') {
			isPossible = false;
			break;
		}

		res += (s[i] != 'H' ? 'B' : s[i]);
	}

	if (isPossible)
		cout << "YES" << endl << res << endl;
	else 
		cout << "NO" << endl;

	return 0;
}