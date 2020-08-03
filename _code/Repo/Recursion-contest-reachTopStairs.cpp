#include<bits/stdc++.h>
using namespace std;

vector<long long int> v(51, -10);

long long int numberOfWays(int n) {
    
    if (n < 0)
        return 0;
        
    if (v[n] != -10)
        return v[n];
    
    long long int num_ways = numberOfWays(n-3) 
        + numberOfWays(n-2) 
        + numberOfWays(n-1);
        
    v[n] = num_ways;
    
    // cout << "n=" << n << ", num_ways=" << num_ways << endl;
    
    return num_ways;
}

long long int findStep(int n) 
{ 
    if (n == 1 || n == 0)  
        return 1; 
    else if (n == 2)  
        return 2; 
      
    else 
        return findStep(n - 3) +  
               findStep(n - 2) +
               findStep(n - 1); 
  
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;
	v[0] = 1;
	v[1] = 1;
	v[2] = 2;
	v[3] = 4;

	for (int i = 1; i < 51; i++)
		cout << i << " : " << numberOfWays(i) << endl;

	return 0;
	
	while (t--) {
	    int n;
	    cin >> n;
	    
	    cout << ((n < 1) ? -1 : numberOfWays(n)) << endl;
	}
	
// 	for (int i = 0; i <= 50; i++)
// 	cout << "i " << i << " " << v[i] << endl;
	
	return 0;
}