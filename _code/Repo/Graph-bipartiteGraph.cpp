// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}


bool isBipartiteUtil(int s, int G[][MAX], int V, vector<bool> &visited)
{
	vector<int> color(V, 0);
	queue<int> q;

	q.push(s);
	color[s] = 1;

	while (!q.empty()) {

		int popped = q.front();
		int popped_color = color[popped];
		q.pop();

		for (int i = 0; i < V; i++) {

			if (G[popped][i] == 0)
				continue;

			if (i == popped)
				return false;

			if (color[i] == 0) {
				q.push(i);
				color[i] = -1 * popped_color;
				visited[i] = true;

			} else if (color[i] == popped_color) {
				return false;
			}
		}
	}

	return true;
}

bool isBipartite(int G[][MAX],int V) {

	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++) {
		if (visited[i])
			continue;

		if (!isBipartiteUtil(i, G, V, visited))
			return false;
	}

	return true;
}