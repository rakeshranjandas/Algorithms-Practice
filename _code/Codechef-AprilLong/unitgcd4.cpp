#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl “\n”
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	string s;

	while (t--) {
		int n;
		cin >> n;

		if (n == 1) {
			s += "1\n1\n1\n";
		
		} else {
			s += to_string(n/2) + "\n";

			if (n%2)
				s += "3 1 2 " + to_string(n) + "\n";
			else
				s += "2 1 2\n";
			
			for (int i = 1; i < n/2; i++) {
				s += "2 " + to_string(2*i+1) + " " + to_string(2*i+2) + "\n";
			}			
		}
	}

	cout << s;

	return 0;
}