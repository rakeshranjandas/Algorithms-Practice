#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

#define INF 10e15
int n,m;
vector<vector<pair<int,int>>> g;
int main()
{
	FILE_WR
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    g.resize(n+1);
    for(int  i = 0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int b;
    cin>>b;
    vector<ll> near(n+1,INF);
    bool visited[n+1] = {false};
    queue<int> q;
    for(int  i = 0;i<b;++i)
    {
        int x;
        cin>>x;
        near[x] = 0;
        q.push(x);
        visited[x] = true;
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> p;
    while(!q.empty())
    {
        int t = q.front();q.pop();
               for(auto i:g[t])
               {
                  near[i.first] = min(near[i.first],near[t]+i.second);
                  if(near[i.first]!=0)
                    p.push({near[i.first],i.first});
                }
    }
    while(!p.empty())
    {
        pair<long long ,int> t = p.top();
        p.pop();
        if(!visited[t.second])
        {
            for(auto i:g[t.second])
            {
               near[i.first] = min(near[i.first],near[t.second]+i.second);
               if(!visited[i.first])
               {
               		deb(i.first);
               		deb(near[i.first]);
               		deb(t.second);
               		deb("\n");


                   p.push({near[i.first],i.first});
                   visited[t.second] = true;
 
                }
            }
        }
 
    }
    for(int i = 1;i<=n;i++)
        cout<<i << " "<<near[i]<<"\n";
}