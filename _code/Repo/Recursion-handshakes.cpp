#include<iostream>
using namespace std;

int handshakes(int n) {
    if (n%2 == 1)
        return 0;
    
    if (n == 0 || n == 2)
        return 1;
    
    int total_ways = 0, k = 0;
    
    for (int i = 0; 2*i <= n-2; i++) {
        total_ways += handshakes(2*i) * handshakes((n-2)-2*i);
        // cout << n << " " << 2*i << "X" << ((n-2)-2*i) << endl;
    }
    
    // cout << "n = " << n << " " << total_ways << endl;
    return total_ways;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int n;
	    cin >> n;
	    
	    cout << handshakes(n) << endl;
	}
	
	return 0;
}