#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

long long int findXorTillN(const long long int n) {

	long long int ans;

	switch(n & 3) {
		case 0:
			ans = n;
			break;

		case 1:
			ans = 1;
			break;

		case 2:
			ans = n+1;
			break;

		case 3:
			ans = 0;
			break;
	}

	return ans;
}

int main() {

	FILE_WR;
	IOS;

	long long int n, x;
	cin >> n;

	int q;
	cin >> q;

	int c;
	set<long long int> ones, zeros;
	string res = "";

	while (q--) {
		cin >> c >> x;

		if (c == 1) {

			ones.insert(x);
			zeros.erase(x);

			if (ones.find(x+1) == ones.end())
				zeros.insert(x+1);

		} else if (c == 2) {

			long long int ans, l, r;

			// Check if x is one or zero
			if (ones.find(x) == ones.end()) {
				// Not a one, can start counting from here
				l = x;

			} else {
				// Is a one, so find nearest zero to right
				l = *(zeros.lower_bound(x));
			}

			// Till what?
			// Till the val becomes 1
			// Find the nearest one
			auto rit = ones.lower_bound(l);

			if (rit == ones.end()) {
				// Cannot find any one to the left, set to n
				r = n;

			} else {
				// Since this is a one, set one to left so that 
				// we find the ending zero index
				r = *rit - 1;
			}

			ans = findXorTillN(r) ^ findXorTillN(l-1);

			res += to_string(ans) + "\n";
		}
	}

	cout << res;

	return 0;
}