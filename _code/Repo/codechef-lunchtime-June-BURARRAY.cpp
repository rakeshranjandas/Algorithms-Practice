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

	int t;
	cin >> t;

	while (t--) {
		int n, Q;
		cin >> n >> Q;

		int op, x, y, p, q, l, r, s = 0, maxm;

		set<int> zeroes_set;

		for (int i = 0; i < Q; i++) {
			cin >> op;

			if (op == 2) {
				cin >> p >> q;

				// Find l, r
				l = p + s;
				r = q + s;

				// Find max
				auto first_it = zeroes_set.find(l);
				auto last_it = zeroes_set.find(r);

				if (last_it == zeroes_set.end()) {
					// r not found in zeroes set, that is maximum
					maxm = r;

				} else {					
					// r is found in zeroes set. Need to find what lies left to r
					// in zeroes set. That is the nearest non zero.
					// Also need to check if that number is inside l and r
					
					int left_num;

					if (last_it == zeroes_set.begin())
						// if r is in begin of zeroes set, then the just left is maxm
						left_num = r - 1;

					else {
						// find the just left
						while (r > 0 && zeroes_set.find(r) != zeroes_set.end())
							r--;

						left_num = r;
					}


					if (left_num < l)
						// if lies outside l and r, then all are 0, 0 is maximum
						maxm = 0;

					else
						// if lies inside l and r, then that is the maxm
						maxm = left_num;

				}

				cout << maxm << endl;

				// Set s as max%n
				s = (s+maxm) % n;

				// cout << "s     " <<  s << endl;

			} else if (op == 1) {
				cin >> y;

				// Find x
				x = y + s;

				// cout << "x " << x << endl;
				
				// Set as 0
				zeroes_set.insert(x);
			}
		}
	}

	return 0;
}