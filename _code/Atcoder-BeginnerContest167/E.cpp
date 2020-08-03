#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
typedef pair<int, int> pi;

void printPQ(priority_queue<pi> pq) {
	while (!pq.empty()) {
		auto popped = pq.top();
		cout << "{" << popped.first << ", " << popped.second << "} ";
		pq.pop();
	}
	cout << endl;
}

void printV(vector<pi> v) {
	for (auto x: v) {
		cout << "{" << x.first << "," << x.second << "} ";
	}
	cout << endl;
}

void calcDepth(string &s, int *max_neg, int *d) {
	// deb(s);

	*d = 0, *max_neg = 0;
	for (char c: s) {
		// deb(c);
		if (c == '(')
			(*d)++;
		else {
			(*d)--;
			// deb(*d);
			*max_neg = max(*max_neg, -1 * (*d));
			// deb(*max_neg);
		}
	}
}

bool compareX(pi a, pi b) {
	return a.first == b.first ? a.second < b.second : a.first > b.first;
}

bool valid(string s[], int n) {
	vector<pi> x_pos, x_neg;
	int max_neg, depth, net_depth = 0;
	int start_depth = 0, end_depth = 0;

	for (int i = 0; i < n; i++) {
		max_neg = 0, depth = 0;
		calcDepth(s[i], &max_neg, &depth);

		// deb(max_neg);
		// deb(depth);

		if (max_neg == 0 && depth == 0)
			continue;

		if (max_neg == 0) {
			if (depth > 0)
				start_depth += depth;
			else
				end_depth += depth;

		} else {

			if (depth > 0) {
				x_pos.push_back({max_neg, depth});
			
			} else {
				x_neg.push_back({max_neg, depth});
			}
		}

		net_depth += depth;
	}

	if (x_pos.size() == 0 && x_neg.size() == 0) {
		// cout << "s";
		return true;
	}

	if (net_depth != 0) {
		// cout << "sd";
		return false;
	}


	sort(x_pos.begin(), x_pos.end(), compareX);
	reverse(x_pos.begin(), x_pos.end());

	sort(x_neg.begin(), x_neg.end(), compareX);

	// cout << "x_pos ";
	// printV(x_pos);

	// cout << "x_neg ";
	// printV(x_neg);

	// deb(start_depth);
	// deb(end_depth);

	int run_depth = start_depth, run_max_neg = 0;

	for (auto p: x_pos) {

		if (run_max_neg > 0)
			return false;

		run_max_neg = max(run_max_neg, p.first - run_depth);

		run_depth += p.second;
	}

	// deb(run_depth);
	// deb(run_max_neg);

	for (auto p: x_neg) {

		if (run_max_neg > 0)
			return false;

		run_max_neg = max(run_max_neg, p.first - run_depth);

		run_depth += p.second;
	}

	// deb(run_depth);
	// deb(run_max_neg);


	return run_depth == 0 && run_max_neg == 0;
}

int main() {

	IOS

	int n;
	cin >> n;

	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];

	cout << (valid(s, n) ? "Yes" : "No") << endl;

	return 0;
}