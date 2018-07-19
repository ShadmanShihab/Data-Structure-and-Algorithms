///topoligical sort(bfs) uva 10305
#include <bits/stdc++.h>
using namespace std;

#define Max 101

int indegree[Max]={0};
vector<int>adj[Max];
vector<int> res;

void topsort(int n)
{
    queue<int> Q;

    for(int i=1; i<=n; i++)
        if(indegree[i] == 0){
            Q.push(i);
        }

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        res.push_back(u);
        //cout<<u;
        //the result can also be printed here
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            indegree[v]--;
            if(indegree[v] == 0)
                Q.push(v);
        }
    }
}
int main()
{
    int m, n;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        memset(indegree, 0, sizeof(indegree));
        memset(adj, 0, sizeof(adj));
        memset(adj, 0, sizeof(res));

        for(int i=1; i<=m; i++)
        {
            int x, y;
            cin>>x>>y;

            adj[x].push_back(y);
            indegree[y]++;
        }

        topsort(n);

        for(int i=0; i<n; i++)
        {
            cout<<res[i];
            if(i != n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
