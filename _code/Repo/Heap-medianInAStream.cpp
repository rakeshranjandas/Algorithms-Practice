#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{


	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    vector<int> dist(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({src, 0});
    dist[src] = 0;

    while (!pq.empty()) {
    	auto popped = pq.top();
    	pq.pop();

    	for (int i = 0; i < V; i++) {
    		if (i != popped.first
    			&& graph[popped.first][i] > 0 
    			&& (dist[i] == -1 || (popped.second + graph[popped.first][i] < dist[i]))
			) {
				int this_dist = popped.second + graph[popped.first][i];
    			pq.push({i, this_dist});
    			dist[i] = this_dist;
    			// cout << "push " << i << " " << this_dist << endl;
    		}
    	}
    }

    for (auto x: dist)
    	cout << x << " ";
}