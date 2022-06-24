#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define SHOW_DEBUG

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
#define DEBP(x)	cerr << #x << "=" << x << " ";
#define _DBM_1(x) DEBP(x);
#define _DBM_2(x, ...) DEBP(x); _DBM_1(__VA_ARGS__)
#define _DBM_3(x, ...) DEBP(x); _DBM_2(__VA_ARGS__)
#define _DBM_4(x, ...) DEBP(x); _DBM_3(__VA_ARGS__)
#define _DBM_5(x, ...) DEBP(x); _DBM_4(__VA_ARGS__)
#define _DBM_6(x, ...) DEBP(x); _DBM_5(__VA_ARGS__)
#define _GET_OVERRIDE(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#ifdef SHOW_DEBUG
#define DEB(...) _GET_OVERRIDE(__VA_ARGS__, \
	_DBM_6, _DBM_5, _DBM_4, _DBM_3, _DBM_2, _DBM_1)(__VA_ARGS__) \
	cerr << endl
#define DEB_VEC(v) cerr<<#v<<":";for(auto x:v)cerr<<" "<<x;cerr<<endl
#else
#define DEB(...)
#define DEB_VEC(v)
#endif
#define SZ(x) ((int) (x).size())
#define ALL(a) (a).begin(),(a).end()
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))
#define pb push_back
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define endl "\n"
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

typedef long long int LL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef pair<int, PI> PPI;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;

const int M = 1e9+7;
/*------------------------------------------------------------------------*/

const int MAX_BIT_LENGTH = 17;

class BitTrieNode {
	public:
	BitTrieNode *children[2];
	BitTrieNode() {
		REP(i, 2)
			children[i] = NULL;
	}
};

class BitTrie {

	BitTrieNode *root;

	public:
	BitTrie() {
		root = NULL;
	}

	void insert(LL num) {
		BitTrieNode *head;
		if (root == NULL)
			root = new BitTrieNode();

		head = root;

		VI bits(MAX_BIT_LENGTH);
		REP(i, MAX_BIT_LENGTH)
			bits[i] = (num&(1<<i))?1:0;

		reverse(ALL(bits));
		for (int x: bits) {
			if (head->children[x] == NULL)
				head->children[x] = new BitTrieNode();
			head = head->children[x];
		}
	}

	LL maxXOR(LL n) {
		return maxXORUtil(n, MAX_BIT_LENGTH-1, root);
	}

	LL maxXORUtil(LL n, int bit, BitTrieNode *now) {
		if (bit < 0)
			return 0;

		int cur_bit = (n&(1<<bit))?1:0;

		if (now->children[cur_bit^1] != NULL)
			return (1<<bit) | (maxXORUtil(n, bit-1, now->children[cur_bit^1]));

		return maxXORUtil(n, bit-1, now->children[cur_bit]);
	}

	LL minXOR(LL n) {
		return minXORUtil(n, MAX_BIT_LENGTH-1, root);
	}

	LL minXORUtil(LL n, int bit, BitTrieNode *now) {
		if (bit < 0)
			return 0;

		int cur_bit = (n&(1<<bit))?1:0;

		if (now->children[cur_bit] != NULL)
			return minXORUtil(n, bit-1, now->children[cur_bit]);

		return (1<<bit) | minXORUtil(n, bit-1, now->children[cur_bit^1]);
	}

	void print() { printUtil(root); }

	void printUtil(BitTrieNode *now) {
		cout << "(";

		REP(i, 2) {
			if (now->children[i] != NULL) {
				cout << i;
				printUtil(now->children[i]);
			}
		}

		cout << ")";
	}
};

void solve() {
	BitTrie t = BitTrie();
	t.insert(12);
	t.insert(10);
	t.print();

	cout << t.maxXOR(3) << endl;
	cout << t.minXOR(3) << endl;
}

int main() {

	IOS

	int t = 1;
	// cin >> t;

	while (t--) {
	    solve();
	}

	return 0;
}