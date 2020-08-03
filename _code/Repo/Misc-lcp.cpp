#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define ALPHA_SIZE 26

int indexOfChar(char c) {
	return c - 'a';
}

char charFromIndex(int i) {
	return 'a' + i;
}

class TrieNode {
	public:
	bool is_end_of_word;
	TrieNode* children[ALPHA_SIZE];


	TrieNode() {
		is_end_of_word = false;
		for (int i = 0; i < ALPHA_SIZE; i++)
			children[i] = NULL;
	}
};

class Trie {
	private:
	TrieNode *root;

	public:
	Trie() {
		root = NULL;
	}

	void insert(string str) {
		if (root == NULL)
			root = new TrieNode();

		TrieNode *now = root;

		for (auto x: str) {
			if (now->children[indexOfChar(x)] == NULL)
				now->children[indexOfChar(x)] = new TrieNode();

			now = now->children[indexOfChar(x)];
		}

		now->is_end_of_word = true;
	}

	bool match(string str) {

	}

	void dfs(TrieNode *now) {
		for (int i = 0; i < ALPHA_SIZE; i++) {
			if (now->children[i] != NULL) {
				cout << charFromIndex(i) << " ";
				dfs(now->children[i]);
			}
		}

		cout << " end" << endl;		
	}

	void traverse() {
		TrieNode *now = root;
		dfs(now);
	}

	bool recursiveMatch(TrieNode *now, string str, int *matched_upto_len) {

		if (str.size() == 0)
			return true;

		if (now->children[indexOfChar(str[0])] != NULL) {
			*matched_upto_len = *matched_upto_len + 1;

			return recursiveMatch(now->children[indexOfChar(str[0])], str.substr(1), matched_upto_len);
		}

		return false;
	}

	int matchAsSuffix(string str) {
		TrieNode *now = root;
		int matched_upto_len = 0;

		recursiveMatch(now, str, &matched_upto_len);

		return matched_upto_len;
	}
};

class SuffixTree {
	public:
	Trie* t;

	SuffixTree(string str) {
		t = new Trie();
		for (int i = 0; i < str.size(); i++)
			t->insert(str.substr(i));
	}

	void traverse() {
		t->traverse();
	}

	void matchPatternFindLargestIndex(string str) {
		int lg = 0, lg_i = -1, matched_len;
		string s_str;

		for (int i = 0; i < str.size(); i++) {
			s_str = str.substr(i);
			matched_len = t->matchAsSuffix(s_str);

			if (matched_len > 0 && matched_len > lg) {
				lg = matched_len;
				lg_i = i;	
			}
		}

		if (lg)
			cout << lg_i << " " << str.substr(lg_i, lg);
		else
			cout << "-1";
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
		string str1, str2;
		cin >> str1 >> str2;

		SuffixTree* st = new SuffixTree(str1);
		st->matchPatternFindLargestIndex(str2);
		cout << endl;
	}

	return 0;
}