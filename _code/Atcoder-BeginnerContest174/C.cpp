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

	int seven = 7, i = 1;
	unordered_set<int> st;

	while (true) {

		if (st.find(seven) != st.end()) {
			cout << -1;
			break;
		}

		st.insert(seven);

		if (seven % k == 0) {
			cout << i;
			break;
		}

		seven = (seven*10 + 7) % k;
		i++;
	}

	return 0;
}