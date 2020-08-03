#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 501

void printReq(map<int, unordered_set<int>> req) {
	for (auto x: req) {
		cout << x.first << " (";
		for (auto y: x.second)
			cout << y << " ";
		cout << ")\n";
	}
}

// void printSet(unordered_set<int> &s) {
// 	for(auto x: s)
// 		cout << x << ",";
// 	cout << endl;
// }

void do_set_diff(unordered_set<int> &s, unordered_set<int> &c) {

	// printSet(s);
	// printSet(c);

	unordered_set<int> s_copy = s;
	for (auto x: s_copy) {
		if (c.find(x) == c.end()) {
			s.erase(x);
		}
	}
}

class compareByCount{

	public:
	bool operator() (pair<int, unordered_set<int>> pp1, pair<int, unordered_set<int>> pp2) {
		return pp1.second.size() > pp2.second.size();
	}
};

void printGraph(map<int, int> graph, int n) {

	for (int i = 1; i <= n; i++)
		cout << graph[i] << " ";
	cout << endl;
}

// void createGraphRecursive(map<int, int> &graph,
// 	unordered_map<int, unordered_set<int>> &req,
// 	int cur_key,
// 	unordered_set<int> &zero_indegree
// ) {
// 	// cout << "here4"<< cur_key<<endl;

// 	if (zero_indegree.find(cur_key) != zero_indegree.end())
// 		return;

// 	if (req[cur_key].size() == 0) {
// 		zero_indegree.insert(cur_key);
// 		return;
// 	}

// 	if (graph[cur_key] != 0)
// 		return;

// 	for (auto x: req[cur_key]) {
// 		createGraphRecursive(graph, req, x, zero_indegree);
// 		if (graph[x] == 0)
// 			graph[x] = cur_key;
// 	}
// }

// void createGraph(unordered_map<int, unordered_set<int>> req, int n) {
// 	// cout << "here2"<< endl;
// 	map<int, int> graph;
// 	unordered_set<int> zero_indegree;
// 	priority_queue<
// 		pair<int, unordered_set<int>>,
// 		vector<pair<int, unordered_set<int>>>,
// 		compareByCount
// 	> pq;

// 	for (auto x: req)
// 		pq.push(x);

// 	while (!pq.empty()) {
// 		auto x = pq.top();
// 		pq.pop();

// 		cout << "popped " << x.first << endl;
// 		createGraphRecursive(graph, req, x.first, zero_indegree);
// 	}

// 	cout << zero_indegree.size() << endl;
// 	printGraph(graph, n);
// }

// void DAG(int a[][N], int q, int n) {
// 	// cout << "here1"<< endl;

// 	unordered_set<int> cur_us;
// 	unordered_map<int, unordered_set<int>> req;

// 	for (int i = 1; i <= n; i++) {
// 		req[a[0][i]] = cur_us;
// 		cur_us.insert(a[0][i]);
// 	}

// 	// cout << "herexx"<< endl;
// 	// printReq(req);

// 	unordered_set<int> cur_acc;

// 	for (int i = 1; i < q; i++) {
// 		cur_acc.clear();

// 		for (int j = 1; j <= n; j++) {
// 			do_set_diff(req[a[i][j]], cur_acc);
// 			cur_acc.insert(a[i][j]);
// 		}
// 	}

// 	// cout << "herexxy"<< endl;

// 	// printReq(req);

// 	createGraph(req, n);
// }

int zeroIndegreeCount(unordered_map<int, int> &m, int n) {
	int c = 0;
	for (int i = 1; i <= n; i++)
		if (m[i] == 0)
			c++;

	return c;
}

int zeroIndegreeCount2(unordered_map<int, unordered_set<int>> &m, int n) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (m.find(i) == m.end()) {
			c++;
			// cout << "> " << i << " " << endl;

		} else {
			// cout << "> " << i << " - ";
			// for (auto x: m[i])
			// 	cout << x << " ";
			// cout << endl;
		}
	}

	return c;
}


void createGraph2(map<int, unordered_set<int>> conn, int n) {
	unordered_map<int, unordered_set<int>> indegree;
	priority_queue<
		pair<int, unordered_set<int>>,
		vector<pair<int, unordered_set<int>>>,
		compareByCount
	> pq;
	map<int, int> graph;

	for (auto x: conn)
		pq.push(x);

	while (!pq.empty()) {
		auto popped = pq.top();
		pq.pop();
		// cout << "popped " << popped.first << endl;

		if (popped.second.size() == 0)
			continue;

		unordered_set<int> all_conn;
		for (auto x: popped.second) {
			all_conn.insert(graph[x]);
		}

		for(auto x: popped.second) {
			if (all_conn.find(x) == all_conn.end()) {
				indegree[x].insert(popped.first);
				graph[popped.first] = x;
				break;
			}
		}
	}

	cout << zeroIndegreeCount2(indegree, n) << endl;
	printGraph(graph, n);
}

void DAG(int a[][N], int q, int n) {

	map<int, unordered_set<int>> conn;
	unordered_set<int> cur_conn_set;

	for (int i = n; i >= 1; i--) {
		conn[a[0][i]] = cur_conn_set;
		cur_conn_set.insert(a[0][i]);
	}

	// printReq(conn);
	for (int i = 1; i < q; i++) {
		cur_conn_set.clear();
		for (int j = n; j >= 1; j--) {
			do_set_diff(conn[a[i][j]], cur_conn_set);
			cur_conn_set.insert(a[i][j]);
		}
	}

	// printReq(conn);

	createGraph2(conn, n);
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
		int n, q;
		cin >> n >> q;

		int a[q][N];
		for (int i = 0; i < q; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];

		DAG(a, q, n);
	}

	return 0;
}