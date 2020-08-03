#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define MAX_AMOUNT 301
#define MAX_COINS 1002

// #define MAX_AMOUNT 30
// #define MAX_COINS 30

ll ways[MAX_AMOUNT][MAX_COINS];

void init() {

	ways[0][0] = 1;

	for (int coin_val = 1; coin_val < MAX_AMOUNT; coin_val++) {

		ways[coin_val][1]++;

		for (int i = 1; i < MAX_AMOUNT; i++) {

			for (int j = 1; j < MAX_COINS; j++) {
				
				if (ways[i][j]) {

					ll new_amount = i + coin_val;
					ll new_num_coins = j + 1;

					if (new_amount < MAX_AMOUNT && new_num_coins < MAX_COINS) {
						ways[new_amount][new_num_coins] += ways[i][j];

					}
				}
			}
		}
	}
}

int main() {

	IOS

	init();

	string ip;

	while (getline(cin, ip)) {
		
		stringstream ss(ip);
		int num;
		vector<int> ips;

		while (ss >> num)
			ips.push_back(num);

		int ips_type = ips.size();
		ll res = 0;

		if (ips_type == 1) {
			for (int i = 0; i <= MAX_COINS; i++)
				res += ways[ips[0]][i];
			
		
		} else if (ips_type == 2) {
			for (int i = 0; i <= ips[1]; i++)
				res += ways[ips[0]][i];
		
		} else {
			for (int i = ips[1]; i <= ips[2]; i++)
				res += ways[ips[0]][i];	
		}

		cout << res << endl;
	}

	return 0;
}