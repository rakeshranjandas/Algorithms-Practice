#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

class TrieNode {
	public:
	bool end_of_word;
	int count;
	TrieNode* children[26];

	TrieNode() {
		count = 0;
		end_of_word = false;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};

int getIndex(char c) {
	return c-'A';
}

char getA(int n) {
	return n+'A';
}

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

			now->children[getIndex(c)]->count++;

			now = now->children[getIndex(c)];
		}

		now->end_of_word = true;
	}

	void dfs() {
		doDfs(head);
	}

	void doDfs(TrieNode* now, int k = 0, int *sum = NULL) {

		for (int i = 0; i < 26; i++) {
			if (now->children[i] != NULL) {
				// cout << getA(i) << " " << now->children[i]->count << " " << endl;

				if (sum != NULL && k != 0) {
					*sum += now->children[i]->count / k;
					// deb(*sum);
				}

				doDfs(now->children[i], k, sum);
			}
		}
	}

	int bundling(int k) {
		int sum = 0;
		doDfs(head, k, &sum);
		return sum;
	}
};

int main() {

	FILE_WR;
	IOS;

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {

		int n, k;
		cin >> n >> k;

		string s;
		Trie t;

		for (int i = 0; i < n; i++) {
			cin >> s;
			t.insert(s);
		}

		// t.dfs();

		cout << "Case #" << t_i << ": " << t.bundling(k) << endl;
	}

	return 0;
}