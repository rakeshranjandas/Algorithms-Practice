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

	int n;
	cin >> n;

	cout << ((n/500) * 1000 + ((n%500)/5) * 5) << endl;

	return 0;
}