#include<iostream>
using namespace std;

int numberOfPaths(int now_x, int now_y, int end_x, int end_y) {

    if (now_x > end_x || now_y > end_y)
        return 0;
    
    if (now_x == end_x && now_y == end_y)
        return 1;
        
    return numberOfPaths(now_x+1, now_y, end_x, end_y) 
        + numberOfPaths(now_x, now_y+1, end_x, end_y);
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int m, n;
	    cin >> m >> n;
	    
	    cout << numberOfPaths(0, 0, m-1, n-1) << endl;
	}
	
	return 0;
}