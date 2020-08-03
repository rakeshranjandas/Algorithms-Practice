#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printSet(set<int> &s) {
	for (auto x: s)
		cout << x << " ";
	cout << endl;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		set<int> f, t, o;

		for (int i = 0; i < n; i++) {

			if (a[i] % 4 == 0)
				f.insert(i);

			else if (a[i] % 2 == 0)
				t.insert(i);

			else
				o.insert(i);
		}

		// cout << "f ";
		// printSet(f);

		// cout << "t ";
		// printSet(t);
		
		// cout << "o ";
		// printSet(o);

		ll c = 0;

		for (int i = 0; i < n; i++) {

			if (f.find(i) != f.end()) {
				c += n-i;
			
			} else if (t.find(i) != t.end()) {
				auto nt_it = t.upper_bound(i);
				int nt = n;

				if (nt_it != t.end())
					nt = *(nt_it);

				auto nf_it = f.upper_bound(i);
				int nf = n;

				if (nf_it != f.end())
					nf = *(nf_it);

				c += n - min(nf, nt);

			} else {

				auto upt_it = t.upper_bound(i);
				int upt = n;

				if (upt_it != t.end())
					upt = *(upt_it);

				auto upf_it = f.upper_bound(i);
				int upf = n;

				if (upf_it != f.end())
					upf = *(upf_it);

				c += min(upf, upt) - i;

				auto uptt_it = t.upper_bound(upt);
				int uptt = n;

				if (uptt_it != t.end())
					uptt = *(uptt_it);

				c += n - min(upf, uptt);
			}
		}

		cout << c << endl;

	}

	return 0;
}