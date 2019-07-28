//prims
//O(ElogV)

#include <bits/stdc++.h>
using namespace std;

# define INF 0x3f3f3f3f
#define pii pair<int, int>
vector<pii> adj[101];
bool visited[101];
int weight[101];
int parent[101];
int n, e;

void prims(int start)
{
    memset(visited, false, sizeof(visited));
    memset(weight, INF, sizeof(weight) );
    memset(parent, -1, sizeof(parent));
    int sum = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    //pq(weight, edge)
    pq.push( pii(0, start) );
    parent[start] = start;
    weight[start] = 0;


    cout<<"path -> \n";

    while(!pq.empty())
    {
        int u = pq.top().second;    //in pq
        int c = pq.top().first;
        pq.pop();
        visited[u] = true;
        cout<<"path -> "<<u<<"  --  Cost -> "<<c<<endl;

        if(pq.size() != 0)
            sum += c;

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;        //in adj
            int w = adj[u][i].second;

            if(visited[v]==false && weight[v] > w)
            {
                weight[v] = w;
                parent[v] = u;
                pq.push( pii(w, v) );
            }
        }
    }
    cout<<sum<<endl;
    //for(int i=1; i<=n; i++)
       // cout<<parent[i]<<" -> "<<i<<endl ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back( pii(v, w) );
        adj[v].push_back( pii(u, w) );
    }
    int start;
    cin>>start;
    prims(start);

    return 0;
}
