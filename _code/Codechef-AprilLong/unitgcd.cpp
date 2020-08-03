#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 1000001
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef set<int> uset;

string printV(vvi v, uset fact_set[]) {

	string res = to_string(v.size()) + "\n";

	for (int i = 0; i < v.size(); i++) {
		res += "{";
		for (auto x: fact_set[i])
			res += to_string(x) + ", ";
		res += "} ";

		res += to_string(v[i].size()) + "-> ";

		for (auto xx: v[i])
			res += to_string(xx) + " ";

		res += "\n";
	}

	return res;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

bool checker(vvi v) {
	for (auto x: v) {
		for (int i = 0; i < x.size()-1; i++)
			for (int j = i+1; j < x.size(); j++) {
				if (gcd(x[i], x[j]) != 1) {
					cout << x[i] << " " << x[j] << endl;

					return false;
				}
			}
	}

	return true;
}

int main() {

	IOS

	int t;
	cin >> t;

	string op = "";
	// int n = 101;

	while (t--) {
		int n;
		cin >> n;

		bool used[n+1] = {0};
		vi vv(1, 1);
		vvi v(n/2, vv);
		uset fact_set[n+1];

		// printV(v);

		for (int i = 2; i <= n; i++)	{
			if (!used[i]) {
				int put_i = 0;

				for (int k = 1; k*i <= min(i*i, n); k++) { 


					if (!used[k*i]) {

						while (fact_set[put_i].find(i) != fact_set[put_i].end() || fact_set[put_i].find(k) != fact_set[put_i].end()) {
							put_i = ((put_i+1) % (n/2));
						}

						v[put_i].push_back(k*i);
						used[k*i] = true;
						fact_set[put_i].insert(i);
						fact_set[put_i].insert(k);

						if (k*i == 15) {
							deb(i);
							deb(k);
						}
					}
				}
			}
		}

		// for (int i = 2; i <= n; i++)	{
		// 	if (!used[i]) {
		// 		int put_i = 0;

		// 		for (int k = 1; k*i <= n; k++) {
		// 			if (!used[k*i]) {
		// 				v[put_i++].push_back(k*i);
		// 				used[k*i] = true;
		// 			}
		// 		}
		// 	}
		// }

		op += printV(v, fact_set);

		// deb(n);
		deb(checker(v));
	}

	cout << op;

	return 0;
}