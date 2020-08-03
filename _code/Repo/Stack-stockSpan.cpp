#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

string maxSpan(int a[], int n) {
    
    stack<pair<int, int>> st;
    st.push({INT_MAX, -1});
    
    string max_span_str = "";
    
    for (int i = 0; i < n; i++) {
        while (st.top().first <= a[i])
            st.pop();
        
        max_span_str += to_string(i-st.top().second) + " ";
        st.push({a[i], i});
    }
    
    return max_span_str;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #else
    #endif

	int t;
	cin >> t;
	
	while (t--) {
	    int n;
	    cin >> n;
	    
	    int a[n];
	    for (int i = 0; i < n; i++)
	        cin >> a[i];
	        
	    cout << maxSpan(a, n) << endl;
	}
	
	return 0;
}