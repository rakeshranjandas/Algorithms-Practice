#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

class PACK {
	public:
	int l, r;
	PACK(int ll, int rr) {
		l = ll, r = rr;
	}

	int len() {
		return r-l+1;
	}
};

struct comparePACK {
	bool operator() (PACK a, PACK b) {
		return (a.len() == b.len()) ? (a.l > b.l) : (a.len() < b.len()); 
	}
};

priority_queue<PACK, vector<PACK>, comparePACK> pq;

int ind;

void modify(int a[], int n) {

	pq.push(PACK(0, n-1));

	while (!pq.empty()) {
		PACK popped = pq.top();
		pq.pop();

		int l = popped.l, r = popped.r;

		int mid;
		if ((r-l+1) % 2 == 1)
			mid = (l+r) / 2;
		else
			mid = (l+r-1) / 2;

		// deb(mid);

		a[mid] = ind;
		ind++;

		if (l <= mid-1)
			pq.push(PACK(l, mid-1));

		if (mid+1 <= r)
			pq.push(PACK(mid+1, r));
	}
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n] = {0};
		ind = 1;
		modify(a, n);

		for (int i = 0; i < n; i++)	
			cout << a[i] << " ";
		cout << endl;

		// cout << "----\n";
	}

	return 0;
}