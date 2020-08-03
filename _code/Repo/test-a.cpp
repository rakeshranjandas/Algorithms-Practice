#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;


void s1(set<int> &s, int x) {

	if (x > 10)
		return;

	s.insert(x);
	s1(s, ++x);
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> s;
	s.insert(12);
	s.insert(43);
	s.insert(100);

	s1(s, 6);

	return 0;
}