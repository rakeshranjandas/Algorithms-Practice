#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printst(stack<int> a) {

	string astr = "";
	while (!a.empty()) {
		astr = to_string(a.top()) + " " + astr;
		a.pop();
	}

	cout << astr << endl;
}

void printStack(stack<int> a, stack<int> b) {
	cout << "a : ";
	printst(a);

	cout << "b : ";
	printst(b);
}

int main() {

	IOS

	int n, m, k;
	cin >> n >> m >> k;

	stack<int> a, b;
	int ip;

	int a_arr[n], b_arr[m];

	for (int i = 0; i < n; i++)
		cin >> a_arr[i];

	for (int i = 0; i < m; i++)
		cin >> b_arr[i];

	for (int i = n-1; i >= 0; i--) {
		a.push(a_arr[i]);
	}

	for (int i = m-1; i >= 0; i--) {
		b.push(b_arr[i]);
	}

	stack<int> sta, stb;

	int kk = k;

	while (!a.empty() && kk > 0) {
		if (kk - a.top() >= 0) {
			sta.push(a.top());
			kk -= a.top();
			a.pop();

		} else
			break;
	}

	while (!b.empty() && kk > 0) {
		if (kk - b.top() >= 0) {
			stb.push(b.top());
			kk -= b.top();
			b.pop();
		
		} else
			break;
	}

	int taken = sta.size() + stb.size();
	int max_taken = taken;

	// printStack(sta, stb);

	while (!sta.empty()) {
		int popped = sta.top();
		sta.pop();

		kk += popped;

		while (!b.empty() && kk > 0) {
			if (kk - b.top() >= 0) {
				stb.push(b.top());
				kk -= b.top();
				b.pop();

			} else
				break;
		}

		// printStack(sta, stb);

		max_taken = max(max_taken, (int)sta.size() + (int)stb.size());
	}

	cout << max_taken;

	return 0;
}