#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a+n, greater<int>());

	priority_queue<int> pq;
	pq.push(a[0]);

	ll comfort = 0;

	for (int i = 1; i < n; i++) {
		int popped = pq.top();
		pq.pop();

		comfort += popped;

		pq.push(a[i]);
		pq.push(a[i]);
	}

	cout << comfort << endl;

	return 0;
}