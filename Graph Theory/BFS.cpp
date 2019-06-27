//BFS
//O(V + E)
/*
*
*
input
6 5
1 2
1 5
1 4
2 3
3 4
1
*
*
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];
int level[100];

void bfs(int start)
{
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    queue<int> q;
    q.push(start);
    level[start] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
                level[v] = level[u] + 1;
            }
        }
    }
}

int main()
{
    int node, edge;
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Enter start: \n";
    int start;
    cin>>start;
    bfs(start);

    cout<<"Visited nodes are: "<<endl;
    for(int i=1; i<=node; i++){
        if(visited[i])
            cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
