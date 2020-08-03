#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int maxAreaHistogram(int h[], int m) {

	if (m == 0)
		return 0;

	stack<pair<int, int>> st;
	int max_area = 0;

	for (int i = 0; i < m; i++) {
		int start_index = i;

		while (!st.empty() && st.top().first >= h[i]) {
			
			auto popped = st.top();
			int area = popped.first * (i-popped.second);
			// deb(area);

			max_area = max(area, max_area);
			start_index = popped.second;

			st.pop();
		}

		st.push({h[i], start_index});

		// printStack(st);
	}

	while (!st.empty()) {
		auto popped = st.top();
		int area = popped.first * (m-popped.second);
		max_area = max(area, max_area);

		st.pop();
	}

	return max_area;
}

int numElMaxSubmatrix(vector<string> &v) {
	int n = v.size();

	if (n == 0)
		return 0;

	int m = v[0].size();

	int h[m] = {0};
	int max_area = 0;

	for (int row = 0; row < n; row++)	{
		for (int col = 0; col < m; col++) {
			if (v[row][col] == '0')
				h[col] = 0;
			else
				h[col]++;
		}

		max_area = max(max_area, maxAreaHistogram(h, m));
		
		// for (int i = 0; i < m; i++)
		// 	cout << h[i] << " ";
		// cout << endl;

		// deb(row);
		// deb(max_area);
	}

	return max_area;
}

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (n--) {
        vector<string> v;
        while (getline(cin, s) && s != "") {
            v.push_back(s);
        }
        // for (int i = 1; i <= v.size(); i++) {
        //     for (int j = 1; j <= v[i - 1].length(); j++) {
        //         int val = v[i - 1][j - 1] == '1'? 1: 0;
        //         height[i][j] = val? height[i - 1][j] + val: 0;
        //     }
        // }
        // int maxi = 0;
        // for (int i = 1; i <= v.size(); i++) {
        //     for (int j = 1; j <= v[i - 1].length(); j++) {
        //         int val = v[i - 1][j - 1] == '1'? 1: 0;
        //         int smaxi = 0, h = 100;
        //         for (int k = j; k >= 1; k--) {
        //             if (height[i][k] == 0) break;
        //             h = min(h, height[i][k]);
        //             smaxi = max(smaxi, (j - k + 1) * h);
        //         }
        //         maxi = max(maxi, smaxi);
        //     }
        // }
        printf("%d\n", numElMaxSubmatrix(v));
        if (n) printf("\n");
    }
    return 0;
}