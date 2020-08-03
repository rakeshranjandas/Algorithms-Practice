#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int hIndex(vector<int>& a) {
	int n = a.size();
    int l = 0, r = n+1, mid;
    
    while (l < r) {

        if (l == r-1)
            break;

        mid = (l+r) / 2;

        if (a[n-mid] < mid)
            r = mid;

        else
            l = mid;
    }


    return l;
}

int main() {

	IOS

	vector<int> v{0};
	cout << hIndex(v);

	return 0;
}