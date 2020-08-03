#include<iostream>
using namespace std;

#define N 101

void dfs(int p, int c, int a[][N], int tc[][N], int n) {

	tc[p][c] = 1;

	for (int i = 0; i < n; i++)
		if(a[c][i] == 1 && c != i && tc[p][i] == 0)
			dfs(p, i, a, tc, n);
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
	    
	    int a[N][N];
	    for (int i = 0; i < n; i++)
	        for (int j = 0; j < n; j++)
	            cin >> a[i][j];
	    
	    int tc[N][N] = {0};

	    for (int i = 0; i < n; i++)
	    	dfs(i, i, a, tc, n);

	   	for (int i = 0; i < n; i++)
	   		for (int j = 0; j < n; j++)
	   			cout << tc[i][j] << " ";

	   	cout << endl;
	}

	return 0;
}