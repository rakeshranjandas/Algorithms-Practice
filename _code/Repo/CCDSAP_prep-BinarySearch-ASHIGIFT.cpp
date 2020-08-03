#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define TYPE(x) x.second.first
#define PEOPLE(x) x.second.second.first
#define CLAN(x) x.second.second.second
#define ll long long int

void printVector(auto v) {
	for (auto x: v) {
		cout << x.first << " (" 
			<< TYPE(x) << ")"
			<< PEOPLE(x) << ", "
			<< CLAN(x) << endl;
	}
}

bool canReach(auto v, ll r) {

	for (auto x: v) {
		if (TYPE(x) == 1)
			r -= PEOPLE(x);

		else {
			if (r >= PEOPLE(x))
				r += CLAN(x);
		}


		if (r <= 0)
			return false;
	}

	return true;
}

int findMinChef(auto v) {

	sort(v.begin(), v.end());

	// printVector(v);

	ll lo = 0, hi = LLONG_MAX, mid;

	while (lo < hi) {

		mid = lo + (hi-lo) / 2;

		if (lo == mid)
			break;

		// cout << "for " << mid << " canReach " << canReach(v, mid) << endl;

		if (canReach(v, mid))
			hi = mid;
		else
			lo = mid;
	}

	return mid+1;
}

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
		int n;
		cin >> n;

		vector<pair<int, pair<int, pair<ll, ll>>>> v;
		/*
			
			<
				dist,
				
				<
					type,

					<
						val1, val2						
					>
					
				>
			>

		*/

		int b;
		cin >> b;

		int x;
		ll y;

		for (int i = 0; i < b; i++) {
			cin >> x >> y;
			v.push_back({x, {1, {y, 0}}});
		}

		int c;
		cin >> c;

		int p;
		ll q, r;

		for (int i = 0; i < c; i++) {
			cin >> p >> q >> r;
			v.push_back({p, {2, {q, r}}});
		}

		cout << findMinChef(v) << endl;
	}

	return 0;
}