#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

class CityCost {
	public:
	int city, cost;
	CityCost(int ct, int cst) {
		city = ct;
		cost = cst;
	}
};

class compareByDist {
	public:
	bool operator() (CityCost a, CityCost b) {
		return a.cost > b.cost;
	}
};

int main() {

	FILE_WR
	IOS

	int k, n, x;
	cin >> k >> n >> x;

	int route[n+1][n+1] = {0};
	int time[n+1][n+1] = {0};
	int s, d, ftime, fcost;

	for (int i = 0; i < x; i++) {
		cin >> s >> d >> ftime >> fcost;
		route[s][d] = route[d][s] = fcost + ftime*k;
		time[s][d] = time[d][s] = ftime;
	}

	if (x > n*(n-1)/2)
		cout << "Error" << endl;
	
		else {

		int src, dest;
		cin >> src >> dest;

		int cost[n+1] = {0};
		bool visited[n+1] = {0};
		int parent[n+1];

		priority_queue<CityCost, vector<CityCost>, compareByDist> pq;
		pq.push(CityCost(src, 0));
		cost[src] = 0;
		visited[src] = true;

		while (!pq.empty()) {
			CityCost popped = pq.top();
			pq.pop();

			visited[popped.city] = true;

			if (popped.city == dest)
				break;

			for (int i = 1; i <= n; i++) {

				if (!route[popped.city][i])
					continue;

				if (visited[i])
					continue;

				int new_cost = cost[popped.city] + route[popped.city][i] + (i == dest ? 0 : k);

				if (cost[i] == 0 || new_cost < cost[i]) {
					cost[i] = new_cost;
					pq.push(CityCost(i, new_cost));
					parent[i] = popped.city;
				}
			}
		}

		if (!visited[dest])
			cout << "Error" << endl;

		else {
			// Find route
			string path = "";
			int now_city = dest, total_time = 0;
			while (now_city != src) {
				path = "->" + to_string(now_city) + path;

				total_time += time[parent[now_city]][now_city];
				if (parent[now_city] != src)
					total_time++;

				now_city = parent[now_city];
			}
			path = to_string(src) + path;

			cout << (path + " " + to_string(total_time) + " " + to_string(cost[dest])) << endl;
		}
	}

	return 0;
}