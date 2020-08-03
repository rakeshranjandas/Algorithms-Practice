#include<iostream>
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

void dfs(Node *root, int *count_leaf, int *sum_alt) {

	if(root == NULL)
		return;

	if (root->left == NULL && root->right == NULL) {
		if (*count_leaf % 2 == 0)
			*sum_alt = *sum_alt + root->data;

		*count_leaf = *count_leaf + 1;
	}

	dfs(root->left, count_leaf, sum_alt);
	// cout << root->data << " ";
	dfs(root->right, count_leaf, sum_alt);
}

int sumOfAlternateLeaf(Node *root) {
	int count_leaf = 0, sum_alt = 0;
	dfs(root, &count_leaf, &sum_alt);
	return sum_alt;
}

int sumAlternate(int a[], int n) {

	// Create tree;
	Node *root = new Node(a[0]);
	for (int i = 1; i < n; i++)
		createBST(root, a[i]);

	// dfs(root);

	return sumOfAlternateLeaf(root);
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
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << sumAlternate(a, n) << endl;
	}
	
	return 0;
}