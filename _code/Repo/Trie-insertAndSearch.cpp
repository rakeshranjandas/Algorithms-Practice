#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

class TrieNode {
 public:
 	bool is_end_of_word;
 	map<char, TrieNode*> children;

 	TrieNode() {
 		is_end_of_word = false;
 	}
};

class Trie {
 private:
	TrieNode* root;

 public:
 	Trie() {
 		root = NULL;
 	}

	void insert(string s) {

		if (root == NULL)
			root = new TrieNode();

		TrieNode* now = root;

		for (auto c: s) {

			if ((now->children).find(c) == (now->children).end())
				(now->children)[c] = new TrieNode();

			now = (now->children)[c];
		}

		now->is_end_of_word = true;
	}

	bool search(string s) {

		if (root == NULL)
			return false;

		TrieNode* now = root;

		for (auto c: s) {
			
			if ((now->children).find(c) == (now->children).end())
				return false;

			now = (now->children)[c];
		}

		return now->is_end_of_word;
	}
};

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
		int n;
		cin >> n;

		Trie t;
		string str;

		for (int i = 0; i < n; i++) {
			cin >> str;
			t.insert(str);
		}

		string a;
		cin >> a;
		cout << t.search(a) << endl;
	}

	return 0;
}