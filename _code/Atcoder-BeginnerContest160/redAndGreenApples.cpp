#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	FILE_WR
	IOS

	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;

	int red[a], green[b], cls[c];

	for (int i = 0; i < a; i++)
		cin >> red[i];

	for (int i = 0; i < b; i++)
		cin >> green[i];

	for (int i = 0; i < c; i++)
		cin >> cls[i];

	sort(red, red+a);
	sort(green, green+b);
	sort(cls, cls+c);

	priority_queue<int> pq;

	for (int i = 0; i < x; i++)
		pq.push(red[a-1-i]);

	for (int i = 0; i < y; i++)
		pq.push(green[b-1-i]);

	for (int i = 0; i < c; i++)
		pq.push(cls[i]);

	ll del = 0;
	for (int i = 0; i < x+y; i++) {
		del += pq.top();
		pq.pop();
	}

	cout << del << endl;

	return 0;
}