#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool covers(int l, int r, int ml, int mr) {
	return l <= ml && r >= mr;
}

bool inside(int l, int r, int ml, int mr) {
	return ml <= l && r <= mr;
}

int main() {

	IOS

	int n;
	cin >> n;

	int l, r, minl, maxr, resi;

	for (int i = 1; i <= n; i++) {

		cin >> l >> r;

		if (i == 1) {
			minl = l;
			maxr = r;
			resi = 1;

		} else {
			
			if (covers(l, r, minl, maxr)) {
				resi = i;
				minl = l;
				maxr = r;

			} else if(inside(l, r, minl, maxr)) {
				// Do nothing

			} else {
				resi = -1;				
				minl = min(l, minl);
				maxr = max(r, maxr);				
			}


		}

		// deb(minl);
		// deb(maxr);

	}

	cout << resi;

	return 0;
}