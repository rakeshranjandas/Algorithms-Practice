#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;
	
	int x;
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> x;
		mp[x]++;
	}

	int row_count = n/3;

	if (mp[7] || mp[5] || mp[1] != row_count)
		cout << -1;

	else {
		bool can = true;
		string res = "";

		for (int i = 0; i < row_count; i++) {
			if (mp[2] && mp[4]) {
				mp[2]--;
				mp[4]--;
				res += "1 2 4\n";
			
			} else if (mp[2] && mp[6]) {
				mp[2]--;
				mp[6]--;
				res += "1 2 6\n";
			
			} else if (mp[3] && mp[6]) {
				mp[3]--;
				mp[6]--;
				res += "1 3 6\n";
			
			} else {
				can = false;
				 break;
			}
		}

		if (can)
			cout << res;
		else
			cout << -1;
	}

	return 0;
}