// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>
#define deb(x)  cout << #x << " " << x << endl;
using namespace std;

string printOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = printOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}

string printStack(stack<char> st) {

    string res = "";
    while (!st.empty()) {
        // cout << st.top();
        res += st.top();
        st.pop();
    }

    return res;
}

void topSortUtil(int ind, bool visited[], unordered_map<char, set<char>> &graph,
    stack<char> &st) {

    visited[ind] = true;

    for (auto child: graph[ind+'a']) {
        int child_ind = child-'a';

        if (!visited[child_ind])
            topSortUtil(child_ind, visited, graph, st);
    }

    // deb(ind+'a');
    st.push(ind+'a');
}

string topSort(unordered_map<char, set<char>> &graph, int K) {

    stack<char> st;
    bool visited[K] = {0};

    for (int i = 0; i < K; i++)
        if(!visited[i])
            topSortUtil(i, visited, graph, st);

    return printStack(st);
}

string printOrder(string dict[], int N, int k) {
    
    unordered_map<char, set<char>> graph;

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {

            if (dict[i] == dict[j])
                continue;

            for (int ind = 0; ind < min(dict[i].size(), dict[j].size()); ind++) {
                if (dict[i][ind] != dict[j][ind]) {
                    graph[dict[i][ind]].insert(dict[j][ind]);
                    break;
                }
            }
        }
    }

    // for (auto x: graph) {
    //     cout << x.first << "(";
    //     for (auto y: x.second)
    //         cout << y << ",";
    //     cout << ")";
    // }
    // cout << endl;
    string top_sorted = topSort(graph, k);

    // deb(top_sorted);
    return top_sorted;
}