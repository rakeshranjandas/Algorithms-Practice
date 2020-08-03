#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS
	
	int s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	set<int> st;
	st.insert(s1);
	st.insert(s2);
	st.insert(s3);
	st.insert(s4);

	cout << (4 - st.size());

	return 0;
}