#include <iostream>
#include <bits/stdc++.h>
using namespace std;  

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif
		
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string word;
		int a[6] = {0, 0, 0, 0, 0, 0};

		for (int i = 0; i < n; i++) {
			cin >> word;

			for (int j = 0; j < word.size(); j++) {
				if (word[j] == 'c')
					a[0]++;

				else if (word[j] == 'd')
					a[1]++;

				else if (word[j] == 'e')
					a[2]++;

				else if (word[j] == 'f')
					a[3]++;

				else if (word[j] == 'h')
					a[4]++;

				else if (word[j] == 'o')
					a[5]++;
			}
		}

		a[0] /= 2;
		a[2] /= 2;

		int count = a[0];
		for (int i = 1; i < 6; i++)
			count = min(count, a[i]);

		cout << count << endl;
	}

	return 0;
}