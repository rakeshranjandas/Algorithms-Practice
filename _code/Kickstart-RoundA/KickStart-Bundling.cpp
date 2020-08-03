#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

class TreeNode {
	public:

	int count, depth;
	unordered_map<char, int> child;

	TreeNode() {
		count = 0;
		depth = 0;
	}
};

void printTree(map<int, TreeNode> tree) {
	for (auto x: tree) {
		cout << x.first << " - " << endl;

		cout << " count = " << x.second.count << endl;
		cout << " depth = " << x.second.depth << endl;

		cout << " links:" << endl;

		for (auto xx: x.second.child) {
			cout << "	" << xx.first << " : " << xx.second << endl;
		}
	}
}

int dfs(map<int, TreeNode> tree, int ind, int *sum_scores, int k) {

	int to_be_deleted = 0;

	for (auto next_ind: tree[ind].child)
		to_be_deleted += dfs(tree, next_ind.second, sum_scores, k);

	tree[ind].count -= to_be_deleted;

	*sum_scores += (tree[ind].count/k) * tree[ind].depth;

	to_be_deleted += tree[ind].count - (tree[ind].count % k);

	return to_be_deleted;
}

int main() {

	FILE_WR;
	IOS;

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {

		int n, k;
		cin >> n >> k;

		map<int, TreeNode> tree;

		string s;
		int ind, m = 0, depth;

		for (int i = 0; i < n; i++) {
			cin >> s;

			ind = 0;
			depth = 1;

			for (auto x: s) {

				if (tree.find(ind) == tree.end())
					tree[ind] = TreeNode();

				if (tree[ind].child.find(x) == tree[ind].child.end())
					tree[ind].child[x] = ++m;



				ind = tree[ind].child[x];
				tree[ind].count++;
				tree[ind].depth = depth++;
			}

			// printTree(tree);
			// cout << "------------------\n";
		}

		int sum_scores = 0;
		dfs(tree, 0, &sum_scores, k);

		cout << "Case #" << t_i << ": " << sum_scores << endl;

	}

	return 0;
}