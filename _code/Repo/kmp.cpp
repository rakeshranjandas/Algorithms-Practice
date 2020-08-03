#include <iostream>
#include <cstring>
using namespace std;  

int* kmp_failure_build(string p) {
	int* f = (int*) malloc(sizeof(int) * p.length());
	memset(f, 0, sizeof(int) * p.length());

	f[0] = 0;
	int k = 1, x= 0;

	while (k < p.length()) {

		if (p[k] == p[x]) {
			f[k] = x + 1;
			x++;
			k++;

		} else {
			if (x == 0) {
				f[k] = 0;
				k++;

			} else {
				x = f[x - 1];
			}
		}
	}

	return f;
}


int kmp_search(string t, string p) {

	if (t.length() < p.length())
		return false;

	// Build failure function array
	int* f = kmp_failure_build(p);

		// cout << "f : ";
		// for (int i = 0; i < p.length(); ++i)
		// 	cout << f[i];
		// cout << endl;

	// Search pattern
	int i = 0, j = 0;
	bool found = false;

	while (i < t.length()) {

		// cout << ">>" << i << " " << j << endl;

		if (t[i] == p[j]) {
			i++;
			j++;

			if (j == p.length()) {
				found = true;
				break;
			}

		} else {
			if (j == 0)
				i++;

			else
				j = f[j - 1];
		}
	}

	int foundIndex = -1;

	if(found) {
		foundIndex = i - p.length();
	};

	return foundIndex;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	string text, pattern;
	cin >> text >> pattern;
	cout << kmp_search(text, pattern);
}