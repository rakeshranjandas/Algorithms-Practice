#include <bits/stdc++.h>
#include <iostream>
#define MOD 1000000007

using namespace std;

int dp[100001][2];

long long int calc(int node, int isDiffColor, int parent,
    unordered_map<int, vector<int>> roads) {


    cout << "inside node " << node
        << ", isDiffColor " << isDiffColor
        << ", parent " << parent
        << ", dp " << dp[node][isDiffColor]
        << endl;

    if (dp[node][isDiffColor] != -1)
        return dp[node][isDiffColor];
    
    long long int c = 1;
    int num_child = 0;
    long long int num_ways_child_different, num_ways_child_same;
    long long int c_ways_child_different = 1;

    for (auto child: roads[node]) {
        if (child == parent)
            continue;

        num_child++;

        num_ways_child_same = calc(child, 0, node, roads);
        num_ways_child_different = calc(child, 1, node, roads);
        c *= (num_ways_child_same + num_ways_child_different) % MOD;
        c_ways_child_different = 
            (c_ways_child_different * num_ways_child_different) % MOD;
    }

    long long int ret;

    if (num_child == 0) // for Leaf node, it's color cannot be different than parent's
        ret = isDiffColor ? 0 : 1;
    else
        ret = (c - (isDiffColor || parent == 0 ? c_ways_child_different: 0) + MOD) % MOD;

    cout << " node " << node
        << ", isDiffColor " << isDiffColor
        << ", parent " << parent
        << ", returned " << ret 
        << endl;

    dp[node][isDiffColor] = ret;

    return ret;
}

int kingdomDivision(int n, vector<vector<int>> v) {

    unordered_map<int, vector<int>> m;
    for (auto x: v) {
        m[x[0]].push_back(x[1]);
        m[x[1]].push_back(x[0]);
    }

    int root;
    for (auto x: m) {

        if (x.second.size() == 1) {
            root = x.first;
            // break;
        }

        cout << x.first << " : ";
        for (auto y: x.second)
            cout << y << " ";
        cout << endl;
    }

    cout << root << endl;

    // vector<vector<int>> dp(m.size()+1, vector<int> (2, -1));
    int ssize = m.size()+1;
    for (int i = 1; i < ssize; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    long long int ways = (2 * calc(root, 0, 0, m)) % MOD;
    
    return ways;
    // return 0;
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> roads(n-1);
    for (int i = 0; i < n-1; i++) {
        roads[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = kingdomDivision(n, roads);

    cout << result << "\n";

    return 0;
}
