#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define OFFSET 3000
#define N 7000
#define MAX_OP 31

bool used[N];
bool dp[MAX_OP][MAX_OP][N];

int countUsed() {
	return accumulate(used, used + N, 0);
}

void evaluate(vector<int> &op, vector<bool> &is_pos, int cur, int open, int rs, string exp = "") {
	if (cur == op.size()) {
		if (open == 0) {
			// cout << exp << " = " << rs << endl;
			used[rs + OFFSET] = true;
		}

		return;
	}

	if (dp[cur][open][rs + OFFSET])
		return;

	int new_rs = rs + (is_pos[cur] ? 1 : -1) * op[cur] * (open%2 == 0 ? 1 : -1);

	if (!is_pos[cur])
		evaluate(op, is_pos, cur+1, open+1, new_rs);

	if (open > 0)
		evaluate(op, is_pos, cur+1, open-1, new_rs);

	evaluate(op, is_pos, cur+1, open, new_rs);


	dp[cur][open][rs + OFFSET] = true;
}

void solve(string ip) {

	stringstream ss(ip);
	string s;

	vector<bool> is_pos;
	is_pos.push_back(true);

	vector<int> operand;

	while (ss >> s) {
		if (s == "-")
			is_pos.push_back(false);

		else if (s == "+")
			is_pos.push_back(true);

		else
			operand.push_back(stoi(s));
	}

	// for (int x: operand)
	// 	cout << x << " ";
	// cout << endl;

	// for (bool x: is_pos)
	// 	cout << x << " ";
	// cout << endl;

	memset(dp, false, sizeof(dp));
	memset(used, false, sizeof(used));

	evaluate(operand, is_pos, 0, 0, 0);
	cout << countUsed() << endl;
}

int main() {

	IOS

	string ip;
	while (getline(cin, ip)) {
		solve(ip);
	}

	return 0;
}