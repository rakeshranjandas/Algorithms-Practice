#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *createBST(Node *root, int n) {

	if (root == NULL)
		return new Node(n);

	if (root->data < n)
		root->right = createBST(root->right, n);

	if (root->data > n)
		root->left = createBST(root->left, n);

	return root;
}

void dfs(Node *root, int col, map<int, vector<int>> *m) {

	if(root == NULL)
		return;

	(*m)[col].push_back(root->data);

	dfs(root->left, col-1, m);
	// cout << root->data << " ";
	dfs(root->right, col+1, m);
}

void bfs(Node *root, map<int, vector<int>> *m) {

	queue<pair<Node*, int>> q;
	q.push({root, 0});

	pair<Node*, int> popped;

	while (!q.empty()) {
		popped = q.front();
		q.pop();

		if (popped.first->left != NULL)
			q.push({popped.first->left, popped.second - 1});

		if (popped.first->right != NULL)
			q.push({popped.first->right, popped.second + 1});

		(*m)[popped.second].push_back(popped.first->data);
	}
}

void printMap(map<int, vector<int>> m) {

	for (auto x: m) {
		for (auto v: x.second)
			cout << v << " ";

		cout << endl;
	}
}

void printVerticalOrder(Node *root) {
	map<int, vector<int>> m;
	bfs(root, &m);
	printMap(m);
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		int a, b;
		char lr;

		unordered_map<int, Node*> m;

		Node *f, *s, *root;

		for (int i = 0; i < n; i++) {
			cin >> a >> b >> lr;

			if (m.find(a) != m.end())
				f = m[a];

			else {
				f = new Node(a);
				m[a] = f;
			}

			if (m.find(b) != m.end())
				s = m[b];

			else {
				s = new Node(b);
				m[b] = s;
			}

			if (lr == 'L')
				f->left = s;
			else
				f->right = s;

			if (i == 0)
				root = m[a];
		}

		printVerticalOrder(root);
	}
	
	return 0;
}