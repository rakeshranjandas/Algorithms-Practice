#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
#define N 101

vector<set<int>> sieve;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

string printSet(set<int> st) {
	string res = "{";
	for (auto x: st)
		res += to_string(x) + ", ";
	res += "} ";

	return res;
}

string printV(vvi v) {

	string res = to_string(v.size()) + "\n";

	for (int i = 0; i < v.size(); i++) {

		// v[i].push_back(1);

		res += to_string(v[i].size()) + " ";

		for (auto xx: v[i])
			res += to_string(xx) + " ";

		res += "\n";
	}

	return res;
}

bool setIntersects(set<int> &a, set<int> &b) {
	set<int> c;
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),
        inserter(c,c.begin()));

	return c.size() > 0;
}

bool setUnion(set<int> &a, set<int> &b) {
	for (auto x: b)
		a.insert(x);
}

void augSieve() {
	sieve.resize(N);

	for (int i = 2; i < N; i++) {
		if (sieve[i].size())
			continue;

		sieve[i].insert(i);

		for (int k = 2; k*i < N; k++) {
			sieve[k*i].insert(i);
		}
	}

	// for (int i = 2; i < N; i++) {
	// 	cout << "[" << i << "]" << printSet(sieve[i]) << " ";
	// }
	// cout << endl;
}

bool checker(vvi v, int n) {

	bool used[n+1] = {0};

	for (auto x: v) {
		for (int i = 0; i < x.size()-1; i++) {
			used[x[i]] = true;

			for (int j = i+1; j < x.size(); j++) {
				used[x[j]] = true;

				if (gcd(x[i], x[j]) != 1) {
					cout << x[i] << " " << x[j] << endl;

					return false;
				}
			}
		}
	}

	for (int i = 2; i < n+1; i++)
		if (!used[i]) {
			cout << "=" << i << "not used";
			return false;
		}


	return true;
}

int main() {

	IOS

	augSieve();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n == 1) {
			cout << "1\n1 1\n";

			continue;
		}

		vvi v;
		bool used[n+1] = {0};

		for (int i = 1; 2*i <= n; i++) {
			v.push_back(vi{2*i, 1});
			used[2*i] = true;
		}

		set<int> rep_set;
		int vind = 0, left = n-n/2-1;

		while (true) {
			rep_set = sieve[v[vind][0]];

			for (int i = 3; i <= n; i++) {
				if (used[i])
					continue;

				if (!setIntersects(rep_set, sieve[i])) {
					
					v[vind].push_back(i);
					used[i] = true;
					left--;

					setUnion(rep_set, sieve[i]);
				}

				if (left == 0)
					break;
			}

			if (left == 0)
				break;

			vind++;
		}
		
		cout << printV(v);
		// deb(n);
		// deb(checker(v, n));
	}

	return 0;
}