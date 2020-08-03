#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define deb(x)	cout << #x << " " << x << endl;

static const int MAX_WEIGHT = 3000, MAX_LOAD = 3000;

int main()
{  
    int N;
    while (cin >> N, N != 0)
    {
        // dp[i] stores the maximum number of boxes that can be
        // stacked up for exactly total weight i.
        vector<int> W(N + 1), L(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> W[i] >> L[i];

        vector<int> dp(MAX_WEIGHT + MAX_LOAD + 1, 0);
        // Condisder box N, box N-1..to box 1.
        for (int box = N; box >= 1; --box)
        {
        	// deb(box);
            for (int load = L[box]; load >= 0; --load)
            {	

            	// deb(load);
            	// deb(load + W[box]);

                if (dp[load])
                    dp[load + W[box]] = max(dp[load + W[box]], // The original best stack.
                                            dp[load] + 1);     // The box stack.
            }
            if (dp[W[box]] == 0)
                dp[W[box]] = 1;


            // for (int k = 0; k < MAX_WEIGHT + MAX_LOAD + 1; k++)
            // 	cout << k << "\t";
            // cout << endl;

            // for (int k = 0; k < MAX_WEIGHT + MAX_LOAD + 1; k++)
            // 	cout << dp[k] << "\t";
            // cout << endl;

        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}