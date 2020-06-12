//finding cycle in a graph
//using dfs
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int n, e;

bool dfs(vector<bool> visited, int at)
{
    if(visited[at] == true)
        return true;

    visited[at] = false;

    bool flag = false;

    for(int i=0; i<adj[at].size(); i++)
    {
        flag = dfs(visited, adj[at][i]);
        if(flag)
            return true;
    }
    return false;
}

bool IsCyclic()
{
    vector<bool> visited(n, false);
    bool flag = false;

    for(int i=1; i<=n; i++)
    {
        visited[i] = true;

        for(int j=0; j<adj[i].size(); j++)
        {
            flag = dfs(visited, adj[i][j]);

            if(flag)
                return true;
        }
        visited[i] = false;
    }
    return false;
}

int main()
{
    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
    }

    bool flag = IsCyclic();

    if(flag)
        cout<<"The graph has a cycle\n";
    else
        cout<<"The graph doesn't have any cycle\n";
}

/*
5 6
5 1
2 1
4 5
4 2
2 3
3 4
*/
