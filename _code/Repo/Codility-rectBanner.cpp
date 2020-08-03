#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int solution(vector<int> &v) {

	int l_banner, r_banner, min_banner = INT_MAX;

	for (int l_size = 1; l_size <= v.size(); l_size++) {

		l_banner = *(max_element(v.begin(), v.begin()+l_size)) * l_size;
		r_banner = (l_size == v.size()) 
			? 0 
			: (*(max_element(v.begin()+l_size, v.end())) * (v.size()-l_size));

		min_banner = min(min_banner, l_banner+r_banner);
	}

	return min_banner;
}


int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<int> v(a, a+n);
		cout << solution(v) << endl;
	}

	return 0;
}