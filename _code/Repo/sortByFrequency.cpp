#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;

// sort using a custom function object
struct {

    // True - Don't swap
    // False - swap
    bool operator()(int x, int y) const
    {   
        return (m[x] > m[y]) || (m[x] == m[y] && x < y);
    }   
} customCompare;

void sortByFrequency(int a[], int n) {
    
    m.clear();
    
    for (int i = 0; i < n; i++)
        m[a[i]]++;
    
    // for (auto mc : m) {
    //     cout << mc.first << " - " << mc.second << endl;
    // }
    
    sort(a, a+n, customCompare);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	int t;
	cin >> t;
	
	while (t--) {
        int n;
        cin >> n;
        
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
            
        sortByFrequency(a, n);
	}
	
	return 0;
}