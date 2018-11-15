#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];
stack<int> Stack;

void topsort(int start)
{
    if(visited[start] == false)
        return;

    visited[start] = true;

    for(int i=0; i<adj[start].size(); i++)
            topsort( adj[start][i] );

    Stack.push(start);

    cout<<Stack.top()<<endl;

}

int main()
{
    int n, e;
    cin>>n>>e;

    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    memset(visited, false, sizeof(visited));

    for(int i=1; i<=e; i++){
        if(visited[i] == false)
            topsort(i);
    }
    cout<<Stack.top();

    while(!Stack.empty() )
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    return 0;
}
