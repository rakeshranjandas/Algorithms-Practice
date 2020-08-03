#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int n;

struct Pack{
	int val;
	int index;
	int half;

	Pack(int v, int i, int h) {
		val = v;
		index = i;
		half = h;
	}
};

struct sortPack {
	bool operator() (Pack a, Pack b) {
		if (a.val == b.val) {
			// both are in same half
			// if (a.half == b.half) {
			// 	if (a.half == 1)
			// 		return a.index > b.index;
			// 	else
			// 		return a.index < b.index;

			// } else {
			// 	// both are in different half
				int mid = n/2;
				return abs(a.index-mid) < abs(b.index-mid);
			// }
		}

		return a.val < b.val;
	}
};

priority_queue<Pack, vector<Pack>, sortPack> pq;

void printPack(Pack p) {
	cout << "{ val: " << p.val << ", index: " << p.index << "}, ";
}

void printPQ(priority_queue<Pack, vector<Pack>, sortPack> pq) {
	while (!pq.empty()) {
		Pack popped = pq.top();
		pq.pop();
		printPack(popped);
	}

	cout << endl;
}

int main() {

	IOS

	cin >> n;
	
	int ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		pq.push(Pack(ip, i, i > n/2 ? 1 : 2));
	}

	printPQ(pq);

	int l = 0, r = n-1;
	ll happiness = 0;

	if (n%2 == 1 && pq.top().index == n/2) {
		

	} else {
		while (!pq.empty()) {
			Pack popped = pq.top();
			pq.pop();

			ll ldist = abs(l-popped.index);
			ll rdist = abs(r-popped.index);

			if (ldist > rdist) {
				l++;
				happiness += ldist * popped.val;
			
			} else {
				r--;
				happiness += rdist * popped.val;	
			}

			cout << popped.val << " " << l << " " << r << endl;
			deb(happiness);
		}
	}

	cout << happiness << endl;

	return 0;
}