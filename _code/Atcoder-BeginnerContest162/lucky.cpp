#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {
	int n;
 	cin >> n;
  
  	if (n%10 == 7 || ((n/10)%10)== 7 || ((n/100)%10) == 7)
      cout << "Yes";
  	else
      cout << "No";
}