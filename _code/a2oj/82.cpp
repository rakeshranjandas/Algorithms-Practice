#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {


	IOS

	int n;
	cin >> n;

	int cnt = 0;
	fesetround(FE_DOWNWARD);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int c2 = i*i + j*j;
			
			if (c2 > n*n)
				continue;

			int c = rint(sqrt(c2));

			if (c*c == c2)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}