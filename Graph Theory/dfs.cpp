#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> adj[101];
bool visited[101];

void dfs(int at)
{
    if(visited[at]) return;

    visited[at] = true;

    for(int i=0; i<adj[at].size(); i++)
        dfs(adj[at][i]);
}


int main()
{
    int n, e, x, y, start;
    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
    cin>>start;

    dfs(start);

    cout<<"visited node: \n";
    for(int i=1; i<=n; i++)
        if(visited[i])
            cout<<i<<endl;
}
