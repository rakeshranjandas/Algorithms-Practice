#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

bool allDistinct(int n) {
	set<int> st;
	st.insert(n%10);
	st.insert((n/10)%10);
	st.insert((n/100)%10);
	st.insert((n/1000)%10);

	return st.size() == 4;
}

int main() {

	IOS

	int n;
	cin >> n;

	while (!allDistinct(++n)) {};

	cout << n;

	return 0;
}