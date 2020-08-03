#include<iostream>
#include<climits>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 28

struct DPWrapper {
	int val;
	string str;

	DPWrapper() {
		val = -1;
		str = "";
	}
};

// void print2dArr(int dp[][N], int n1, int n2) {
// 	for (int i = 0; i < n1; i++) {
// 		for (int j = 0; j < n2; j++)
// 			cout << dp[i][j] << " ";
// 		cout << endl;
// 	}
// }

// void init2dDP(int dp[][N], int n1, int n2) {
// 	for (int i = 0; i < n1; i++)
// 		for (int j = 0; j < n2; j++) 
// 			dp[i][j] = i == j ? 0 : -1;
// }

int findMult(DPWrapper dp[][N], int i, int j) {
	return dp[i][j].val;
}

string MCMUtil(int x[], int y[], int n, int start, int end, DPWrapper dp[][N]) {

	if (start == end)
		return string(1, 'A' + start);

	if (dp[start][end].val != -1)
		return dp[start][end].str;

	string ret_string, first_part_mult_str, second_part_mult_str;
	int this_mult, first_part_mult, second_part_mult;
	int min_mult = INT_MAX;

	for (int i = start; i < end; i++) {
		first_part_mult_str = MCMUtil(x, y, n, start, i, dp);
		first_part_mult = findMult(dp, start, i);

		second_part_mult_str = MCMUtil(x, y, n, i+1, end, dp);
		second_part_mult = findMult(dp, i+1, end);

		this_mult = x[start] * x[i+1] * y[end] + first_part_mult + second_part_mult;

		// cout << "start " << start 
		// 	<< " i " << i
		// 	<< " end " << end
		// 	<< endl;

		// cout << "this_mult " << this_mult << endl;

		if (this_mult < min_mult) {
			ret_string = first_part_mult_str + second_part_mult_str;
			min_mult = this_mult;
			// cout << " rep " << ret_string << endl;
		}
	}

	dp[start][end].val = min_mult;
	dp[start][end].str = "(" + ret_string + ")";


	return dp[start][end].str;
}

string MCM(int a[], int n) {

	int x[n-1], y[n-1];
	for (int i = 0; i < n-1; i++) {
		x[i] = a[i];
		y[i] = a[i+1];
	}

	DPWrapper dp[n][N];
	// init2dDP(dp, n, n);

	string ret = MCMUtil(x, y, n-1, 0, n-2, dp);

	// print2dArr(dp, n, n);

	return ret;
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

		cout << MCM(a, n) << endl;
	}

	return 0;
}