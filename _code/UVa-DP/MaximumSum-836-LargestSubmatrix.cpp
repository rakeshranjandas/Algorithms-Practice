#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printStack(stack<pair<int, int>> st) {
	string res ="";

	while (!st.empty()) {
		res = to_string(st.top().first) + "," 
			+ to_string(st.top().second) + " " + res;
		st.pop();
	}
	cout << res << endl;
}

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

	IOS

	int a[5] = {10, 15, 20, 20, 12};
	cout << maxAreaHistogram(a, 5) << endl;


	int t;
	cin >> t;

	int t_i = 0;

	string ip;
	getline(cin, ip);

	vector<string> v;

	while (true) {
		if (cin.eof() || (getline(cin, ip) && ip == "")) {

			if (t_i > 0)
				cout << numElMaxSubmatrix(v) << endl;

			if (cin.eof())
				break;

			else if (t_i > 0)
				cout << endl;

			v.clear();

			t_i++;
			if (t_i > t)
				break;

			continue;
		}

		v.push_back(ip);
	}
	return 0;
}