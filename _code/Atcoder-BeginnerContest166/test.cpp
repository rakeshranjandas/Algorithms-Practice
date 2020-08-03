#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string ip;
	cin >> ip;
	ip[1] = ip[1] == 'B' ? 'R' : 'B';
	cout << ip << endl;

	return 0;
}