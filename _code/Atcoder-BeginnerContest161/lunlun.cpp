#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

vector<ll> lunlun;

void findLunlun(ll cur) {

	// deb(cur);

	if (cur < 0)
		return;

	if (cur >= 10000000000)
		return;

	lunlun.push_back(cur);

	int unit_digit = cur % 10;

	findLunlun(cur*10 + unit_digit);

	if (unit_digit > 0)
		findLunlun(cur*10 + unit_digit-1);

	if (unit_digit < 9)
		findLunlun(cur*10 + unit_digit+1);
}

void init() {
	for (int i = 1; i <= 9; i++)
		findLunlun(i);

	sort(lunlun.begin(), lunlun.end());

	// for (auto x: lunlun)
	// 	cout << x << " ";
	// cout << endl;
}

int main() {

	IOS

	init();

	int k;
	cin >> k;
	cout << lunlun[k-1] << endl;

	return 0;
}