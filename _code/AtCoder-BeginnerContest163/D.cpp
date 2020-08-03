#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define M 1000000007

typedef long long int ll;

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	ll max_sum, min_sum, count = 0;

	for (ll num_el = k; num_el <= n+1; num_el++) {
		min_sum = ((double)num_el * (num_el-1)) / 2;
		max_sum = (ll) (((double)num_el/2) * (2*(n-num_el+1) + (num_el-1)));
		
		count = (count + (max_sum - min_sum + 1)) % M;
	}

	cout << count << endl;

	return 0;
}