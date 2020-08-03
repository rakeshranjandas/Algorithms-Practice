#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

// This function finds the value of a and b 
// and returns a+b and a-b 
void FermatFactors(int n) 
{ 
	
	// since fermat's factorization applicable 
	// for odd positive integers only 
	if(n <= 0) 
	{ 
		cout << "[" << n << "]"; 
		return; 
	} 

	// check if n is a even number 
	if((n & 1) == 0) 
	{ 
		cout << "[" << n / 2.0 << "," << 2 << "]"; 
		return; 
	} 
		
	int a = ceil(sqrt(n)) ; 

	// if n is a perfect root, 
	// then both its square roots are its factors 
	if(a * a == n) 
	{ 
		cout << "[" << a << "," << a << "]"; 
		return; 
	} 
	int b; 
	while(true) 
	{ 
		int b1 = a * a - n ; 
		b = (int)sqrt(b1) ; 
		
		if(b * b == b1) 
			break; 
		else
			a += 1; 
	} 
	cout << "[" << (a - b) << "," << (a + b) << "]" ; 
	return; 
} 
	
// Driver Code 
int main() 
{ 
	IOS
	FermatFactors(99999999); 
	return 0; 
} 

// This code is contributed by AnkitRai01 
