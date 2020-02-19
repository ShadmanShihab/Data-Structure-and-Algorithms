//O(v^3)
#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> adj[101];
vector<int> ap;
int dis[101], low[101];
int vis[101];
int timer = 0;

void dfs(int u, int p)
{
    vis[u] = true;
    low[u] = dis[u] = timer++;
    int child = 0;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(v == p)
            continue;

        if(vis[v])
            low[u] = min(low[u], dis[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[v], low[u]);


            if(low[v] >= dis[u] && p != -1)   //low[v] > dis[v] - for bridge
                ap.push_back(u);

            child++;
        }
    }

    if(p == -1 && child > 1)
        ap.push_back(u);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, -1);

    for(int i=0; i<ap.size(); i++)
        cout<<ap[i]<<endl;
}
