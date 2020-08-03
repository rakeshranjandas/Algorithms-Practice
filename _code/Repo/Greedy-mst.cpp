#include <bits/stdc++.h>
using namespace std;
#define deb(x)  cout << #x << " " << x << endl;
int spanningTree(int V,int E,vector<vector<int> > graph);
// Driver code
int main()
{

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));
        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

struct Edge {
    int node, cost;
    Edge(int aa, int cc) {
        node = aa;
        cost = cc;
    }
};

class sortByCost {
    public:
    bool operator() (Edge a, Edge b) {
        return a.cost > b.cost;
    }  
};

int spanningTree(int V,int E,vector<vector<int> > graph)
{

    // for (auto x: graph) {
    //     for (auto y: x)
    //         cout << y << " ";
    //     cout << endl;
    // }

    // return 1;

    priority_queue<Edge, vector<Edge>, sortByCost> pq;
    vector<bool> visited(V, false);
    
    int now = 0, mst_cost = 0;
    
    pq.push(Edge(0, 0));
    
    while (!pq.empty()) {
        auto popped = pq.top();
        pq.pop();
        
        // deb(popped.node+1);

        if (visited[popped.node])
            continue;

        visited[popped.node] = true;
        mst_cost += popped.cost;
        
        for (int i = 0; i < V; i++) {
            
            if (graph[popped.node][i] == INT_MAX)
                continue;
            
            if (i == popped.node)
                continue;
                
            if (visited[i])
                continue;
                
            pq.push(Edge(i, graph[popped.node][i]));
        }
    }
    
    return mst_cost;
}
