#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 12
int dp[1<<N];

int findBitMask(string &s) {
	int mask = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'o')
			mask |= 1 << i;
	}

	return mask;
}

int countSetBits(int mask) {
	int c = 0;
	for (int i = 0; i < N; i++)
		if (mask & 1<<i)
			c++;

	return c;
}

int setBit(int mask, int i) {
	return mask | 1<<i;
}

int unsetBit(int mask, int i) {
	return mask & (~(1<<i));
}

int isBitSet(int mask, int i) {
	return mask & 1<<i;
}

int minPebblesLeft(int mask) {

	if (dp[mask] != -1)
		return dp[mask];

	int pebbles = countSetBits(mask);
	int mask_after_move;

	for (int i = 0; i < N; i++) {

		// If the space is empty
		if (!isBitSet(mask, i)) {

			// Check if 2 left spaces have pebbles
			if (i-1 >= 0 && isBitSet(mask, i-1) && i-2 >= 0 && isBitSet(mask, i-2)) {

				mask_after_move = setBit(mask, i);
				mask_after_move = unsetBit(mask_after_move, i-1);
				mask_after_move = unsetBit(mask_after_move, i-2);

				pebbles = min(pebbles, minPebblesLeft(mask_after_move));
			}

			// Check if 2 right spaces have pebbles
			if (i+1 < N && isBitSet(mask, i+1) && i+2 < N && isBitSet(mask, i+2)) {
				
				mask_after_move = setBit(mask, i);
				mask_after_move = unsetBit(mask_after_move, i+1);
				mask_after_move = unsetBit(mask_after_move, i+2);

				pebbles = min(pebbles, minPebblesLeft(mask_after_move));
			}
		}
	}

	dp[mask] = pebbles;

	return pebbles;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		memset(dp, -1, sizeof(dp));

		cout << minPebblesLeft(findBitMask(s)) << endl;
	}

	return 0;
}