#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int andAll(int m, int n) {

	if (n-m == INT_MAX)
		return 0;

	int count_num = n-m+1;

	if (count_num == 1)
		return n;

	int i = 30;

	while (count_num < ((1<<i) + 1)) {
		i--;
	}

	i++;

	return ((m>>i) & (n>>i)) << i;
}

int main() {

	IOS

	int m, n;
	cin >> m >> n;

	cout << andAll(m, n) << endl;

	return 0;
}