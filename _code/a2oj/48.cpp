#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int k;
	cin >> k;

	int a[12];
	for (int i = 0; i < 12; i++)
		cin >> a[i];

	sort(a, a+12, greater<int>());

	int c = 0, sum = 0;
	for (int i = 0; i < 12 && sum < k; i++)
		sum += a[i], c++;

	cout << (sum < k ? -1 : c);

	return 0;
}