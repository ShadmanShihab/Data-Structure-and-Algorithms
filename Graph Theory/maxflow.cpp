//maxflow
// Ford Fulkerson Algorithm--Edmonds-Karp Algorithm
// O(VE2)
#include <bits/stdc++.h>
using namespace std;
#define Max 100

int adj[Max][Max];
int n, s, t;

bool bfs(int residual[Max][Max], int parent[])
{
    int visited[n+2];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v=1; v<=n; v++)
        {
            if(visited[v]==0 && residual[u][v] > 0)
            {
                visited[v] = 1;
                q.push(v);
                parent[v] = u;
            }
        }
    }

    if(visited[t] == 1)
        return true;
    else
        return false;
}

int maxFlow()
{
    int residual[Max][Max];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            residual[i][j] = adj[i][j];

    int parent[n+2], max_flow=0;

    while(bfs(residual, parent))
    {
        int flow = INT_MAX;
        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
            flow = min(flow, residual[u][v]);
        }

        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];

            residual[u][v] -= flow;
            residual[v][u] += flow;
        }
        max_flow += flow;
    }
    return max_flow;
}

int main()
{
    cin>>n>>s>>t;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>adj[i][j];

    cout<<maxFlow()<<endl;
    return 0;
}

/*
*
*
6 1 6
0 16 13 0 0 0
0 0 10 12 0 0
0 4 0 0 14 0
0 0 9 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0
*
*/
