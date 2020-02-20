#include <bits/stdc++.h>
using namespace std;

int parent[101], n, e;
vector<int> adj[101];

void makeset()
{
    for(int i=1; i<=n; i++)
        parent[i] = i;
}

int Find(int r)
{
    if(r == parent[r])
         return r;
    parent[r] = Find(parent[r]);
}

void Union(int a, int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u == v)
        return;
    else
        parent[v] = u;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    makeset();

    //find is used to find the parent of any node
    //if parent of two nodes are different then the graphs aren't connected


    //union is used to connect two graphs
    return 0;
}
