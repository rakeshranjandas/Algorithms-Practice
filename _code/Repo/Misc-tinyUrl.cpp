#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

string base_62_mod = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
unordered_map<char, int> base_62_map;

string encode(long long int num) {
	string enc_str = "";
	long long int m;

	while (num > 0) {
		m = num % 62;
		enc_str = base_62_mod[m] + enc_str;
		num /= 62;
	}

	return enc_str;
}

long long int decode(string enc_str) {
	long long int num = 0;

	for (int i = 0; i < enc_str.size(); i++) {
		num = num * 62 + base_62_map[enc_str[i]];
	}

	return num;
}

void initMap() {
	for (int i = 0; i < base_62_mod.size(); i++)
		base_62_map[base_62_mod[i]] = i;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	initMap();

	int t;
	cin >> t;

	while (t--) {
		long long int num;
		cin >> num;

		string encoded_str = encode(num);
		cout << encoded_str << endl;

		long long int decoded_num = decode(encoded_str);
		cout << decoded_num << endl;
	}

	return 0;
}