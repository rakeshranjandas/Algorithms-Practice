#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define pf push_front
#define all int i=0; i<n; i++
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long int ll;                        	
string palin(string k){
    reverse(k.begin(), k.end());
	return k;
} 
int reverse(int n){
	int reversedNumber = 0, remainder;
	while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    return reversedNumber;
}
int power(int x, int y){
	int res = 1;
	while(y>0){
		if(y&1)res = (res*x);
		y = y>>1;
		x = (x*x);
	}
	return res;
} 
int main() 
{ 

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif
	
	ll t,n,m;
	vector<ll>v;
	v.pb(1);
	v.pb(1);
	v.pb(2);
	v.pb(3);
	for(int i=4; i<1000; i++){
		v.pb(v[i-1]+v[i-2]);
	}

	n = 31, m=1000;
	for (int i = 0; i < n; i++)
		cout << i << ":" << v[i-1]%m << endl;

	// cin>>t;
	// while(t--){
	// 	cin>>n>>m;
	// 	cout<<(2*v[n-1])%m<<endl;
	// }
} 