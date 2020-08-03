#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int
#define N 200001
#define vvs vector<vector<set<int>>>
#define vs vector<set<int>>

int n, k, c;
string s;
map<int, map<int, set<int>>> dp;
int only_working = -1;

bool canWork(int i) {
	return s[i-1] != 'x';
}

string printSet(set<int> &s) {

	if (s.size() == 0)
		return "";

	string str = "";
	str += "{";
	for (int x: s)
		str += to_string(x) + ",";
	str += "}";

	return str;
}

void printDp() {
	for (int i = k; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			cout << "[" << i << "," << j << "]" <<printSet(dp[i][j]) << "\t";
		}
		cout << endl;
	}
}

string findSureDays() {
	set<int> sure_days;
	set<int> reachable;

	for (int i = 1; i <= n; i++)
		for (int x: dp[k][i])
			reachable.insert(x);

	for (int k_i = k-1; k_i > 1; k_i--) {


		for (auto x: reachable) {
			cout << x << "--";
		}
		cout << endl;

		if (reachable.size() == 1)
			sure_days.insert(*(reachable.begin()));

		else if (reachable.size() == 0)
			return "";
	}

	string res = "";
	for (int x: sure_days)
		res += to_string(x) + "\n";

	deb(res);
	return res;
}

bool hasOnlyOneWorking() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'x') {

			if (only_working != -1)
				return false;

			only_working = i+1;
		}
	}

	return true;
}


string yutori() {

	if (k == 1 && hasOnlyOneWorking())
		return to_string(only_working);

	for (int j = n; j >= 1; j--) {
		if(canWork(j)) {
			for (int k = j-c-1; k >= 1; k--)
				if (canWork(k))
					dp[2][k].insert(j);
		}
	}

	for (int i = 2; i <= k; i++) {
		for (int j = n; j >= 1; j--) {
			if(dp[i][j].size()) {
				for (int k = j-c-1; k >= 1; k--)
					if (canWork(k))
						dp[i+1][k].insert(j);
			}
		}
	}

	printDp();

	return findSureDays();
}

int main() {

	IOS

	cin >> n >> k >> c;
	cin >> s;
	cout << yutori();
}