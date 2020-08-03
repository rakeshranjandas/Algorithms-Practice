#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;

	bool findOnes = true;
	int type, x, y;

	set<pair<int, int> > s;
	pair<int, int> p;

	while (q--) {

		cin >> type;

		if (type == 1) {
			cin >> x >> y;

			p = make_pair(x, y);

			if (s.find(p) != s.end())
				s.erase(s.find(p));

			else
				s.insert(p);

		} else
			findOnes = !findOnes;
		
	}

	int set_size = s.size();
	long long int count = findOnes ? set_size : ((long long int)n*m - set_size);

	cout << count << endl;

	return 0;
}