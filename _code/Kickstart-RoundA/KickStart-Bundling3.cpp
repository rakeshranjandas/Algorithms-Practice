#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

int getIndex(char c) {
	return c - 'A';
}

class TrieNode {
	public:

	int count;
	TrieNode *children[26];

	TrieNode() {
		count = 0;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};

class Trie {
	public:

	TrieNode *head;

	Trie() {
		head = NULL;
	}

	void insert(string s) {
		if (head == NULL)
			head = new TrieNode();

		TrieNode *now = head;

		for (auto c: s) {
			if (now->children[getIndex(c)] == NULL)
				now->children[getIndex(c)] = new TrieNode();
			now = now->children[getIndex(c)];
		}

		now->count++;
	}

	int dfs(TrieNode *now, int *score, int k, int depth) {

		for (int i = 0; i < 26; i++) {
			if (now->children[i] != NULL)
				now->count += dfs(now->children[i], score, k, depth+1);
		}

		*score += (now->count / k) * depth;
		now->count %= k;

		return now->count;
	}

	int countBundle(int k) {
		int score = 0;
		dfs(head, &score, k, 0);

		return score;
	}
};

int main() {

	FILE_WR
	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		int n, k;
		cin >> n >> k;

		Trie t;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			t.insert(s);
		}

		cout << "Case #" << t_i << ": " << t.countBundle(k) << endl;
	}

	return 0;
}