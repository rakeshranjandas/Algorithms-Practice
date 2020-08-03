#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void util(vector<vector<int>>& costs, int cur, int cost_till_now, int used_a, int used_b, int *min_cost) {
	if (used_a == costs.size()/2 && used_b == costs.size()/2) {
		*min_cost = min(*min_cost, cost_till_now);
		return;
	}

	if (cur >= costs.size())
		return;

	util(costs, cur+1, cost_till_now + costs[cur][0], used_a+1, used_b, min_cost);
	util(costs, cur+1, cost_till_now + costs[cur][1], used_a, used_b+1, min_cost);
}

int twoCitySchedCost(vector<vector<int>>& costs) {
	int min_cost = INT_MAX;
	util(costs, 0, 0, 0, 0, &min_cost);

	return min_cost;
}

int main() {

	IOS

	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(2));
	for (int i = 0; i < n; i++)
		cin >> v[i][0] >> v[i][1];

	cout << twoCitySchedCost(v);

	return 0;
}