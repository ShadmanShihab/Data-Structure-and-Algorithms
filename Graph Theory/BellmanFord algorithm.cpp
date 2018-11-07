/*
Try this inputs from uva 558 wormholes
2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60
*/
//BellmanFord algorithm
//O(n * e)

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
vector<pii> adj[1010];
int inf = 10000000;
int dis[1010];
int previous[1010];
int n, m;

int printPath(int n)
{
    while(n != 0)
   {
        cout<<n<<endl;
        n = previous[n];
    }
}

void BellmanFord(int start)
{
    for(int i=0; i<=n; i++)
        dis[i] = inf;

    dis[start] = 0;

    for(int i=0; i<n-1; i++)
    {
        for(int u=0; u<n; u++)
        {
            for(int v = 0; v<adj[u].size(); v++)
            {
                if(dis[adj[u][v].first] > dis[u] + adj[u][v].second)
                {
                    dis[adj[u][v].first] = dis[u] + adj[u][v].second;
                    previous[adj[u][v].first] = u;
                }
            }
        }
    }
    bool flag = false;
    for(int u=0; u<n; u++)
    {
        for(int v = 0; v<adj[u].size(); v++)
        {
            if(dis[adj[u][v].first] > dis[u] + adj[u][v].second)
            {
                flag = true;
            }
        }
    }

    if(flag == true)
        printf("The shortest path from the source is undefined\n");
    else
    {
        for(int u=0; u<n; u++)
            cout<<"This distance of node "<<u<<" from source: "<<dis[u]<<endl;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);

        for(int i=0; i<=n; i++)
            adj[i].clear();

        for(int i=0; i<m; i++)
        {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back( pii(y,w) );
        }
        BellmanFord(0);

        printPath(n-1);
    }
    return 0;
}
