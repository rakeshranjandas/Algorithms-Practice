#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

class Agent {
	public:

	int comm;
	int l, r;
	int id;

	Agent(int ll, int rr, int c) {
		l = ll;
		r = rr;
		comm = c;
	}
};

bool sortByComm (Agent a, Agent b) {
	return a.comm == b.comm ? (a.id <= b.id): a.comm < b.comm;
};

void printAgentV(vector<Agent> &agent_v) {
	for (auto x: agent_v) {
		cout << "{" << id << "(" << l << "," << r << ")}"
	}
}

long long int minAmount(vector<Agent> &agent_v, int k) {

	long long int total_comm = 0;

	sort(agent_v.begin(), agent_v.end(), sortByComm);
	printAgentV(agent_v);

	return 0;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<Agent> agent_v;
	int l, r, comm;

	for (int i = 0; i < m; i++) {
		cin >> l >> r >> comm;
		agent_v.push_back(Agent(l, r, comm));
	}

	cout << minAmount(agent_v, k) << endl;

	return 0;
}