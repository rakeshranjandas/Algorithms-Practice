#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

vector<int> generateFact(int n) {
	vector<int> v(n+1);
	v[0] = 1;

	for (int i = 1; i <= n; i++)
		v[i] = i * v[i-1];

	return v;
}

vector<char> generate(int n) {
	vector<char> v;
	for (int i = 1; i <= n; i++)
		v.push_back(i+'0');

	return v;
}

string kthPermutation(int n, int k) {
	vector<int> fact = generateFact(n);
	vector<char> ch = generate(n);

	string res = "";
	int nn = n;
	k--;

	for (int i = 0; i < n; i++)	{
		int group = fact[--nn];
		int index = k/group;
		
		res += ch[index];
		ch.erase(ch.begin() + index);

		k -= index * group;
	}

	return res;
}

int main() {

	IOS

	int n, k;
	cin >> n >> k;

	cout << kthPermutation(n, k);

	return 0;
}