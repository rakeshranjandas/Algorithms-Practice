#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

class Camel {
	public:
	int k, l, r;

	Camel(int kk, int ll, int rr) {
		k = kk, l = ll, r = rr;
	}

	void print() {
		cout << " { " << k << " " << l << " " << r << "}" << endl;
	}
};

bool sortCamel(Camel a, Camel b) {

	int diffa = a.l - a.r;
	int diffb = b.l - b.r;


	if (diffa >= 0 && diffb <= 0)
		return true;

	if (diffa >= 0 && diffb >= 0)
		return a.k < b.k;

	if (diffa <= 0 && diffb > 0)
		return false;

	if (diffa <= 0 && diffb <= 0)
		return a.r < b.r;



	// if (diffa > diffb)
	// 	return true;

	// if (diffa < diffb)
	// 	return false;

	// if (a.k <= b.k)
	// 	return true;

	// return false;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<Camel> a;
		a.push_back(Camel(0, 0, 0));

		int k, l, r;

		for (int i = 1; i <= n; i++) {
			cin >> k >> l >> r;
			a.push_back(Camel(k, l, r));
		}

		sort(a.begin()+1, a.end(), sortCamel);

		int h = 0;

		for (int i = 1; i < a.size(); i++) {
			a[i].print();
			h += (i <= a[i].k) ? a[i].l : a[i].r;
			// deb(h);
		}

		cout << h << endl;
	}

	return 0;
}