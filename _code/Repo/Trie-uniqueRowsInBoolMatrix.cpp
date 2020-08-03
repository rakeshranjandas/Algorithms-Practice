#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define N 41

class TrieNode {
	public:
	TrieNode* children[2];
	bool is_end_of_word;

	TrieNode() {
		children[0] = NULL;
		children[1] = NULL;
		is_end_of_word = false;
	}
};

bool uniqueInsertIntoTrie(TrieNode *trie_start, int a[], int m) {

	TrieNode* now = trie_start;

	for (int i = 0; i < m; i++) {

		if (now->children[a[i]] == NULL) {
			now->children[a[i]] = new TrieNode();
		}

		now = now->children[a[i]];
	}

	if (!now->is_end_of_word) {
		now->is_end_of_word = true;
		return true;
	}

	return false;
}

void printRow(int a[], int m) {
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << "$";
}

TrieNode* createTrieAndPrintIfUnique(int a[][N], int n, int m) {
	TrieNode* trie_start = new TrieNode();
	bool is_unique;

	for (int i = 0; i < n; i++) {
		is_unique = uniqueInsertIntoTrie(trie_start, a[i], m);

		if (is_unique)
			printRow(a[i], m);
	}

	return trie_start;
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
		int n, m;
		cin >> n >> m;

		int a[n][N];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];

		createTrieAndPrintIfUnique(a, n, m);
		cout << endl;
	}

	return 0;
}