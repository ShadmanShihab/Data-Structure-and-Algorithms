#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pfi(n) printf("%d\n", n)
#define sci(n) scanf("%d", &n)
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=1; i<=n; i++)
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005;
# define INF 0x3f3f3f3f
long long limit = 4294967296;

template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}

int adj[101][101];
int n, m;

int main()
{
    cin>>n>>m;
    memset(adj, 0, sizeof(adj));

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int deg = 0, deg2= 0, deg3 = 0;
    int Count = 0;

    for(int i=1;i<=n;i++)
    {
        Count=0;
        for(int j=1;j<=n;j++)
        {
            if(adj[i][j]==1)
                Count++;
        }

        cout<<"both in degree and out degree of node "<<i+1 <<" is "<<Count<<endl;

        if(Count==2)
            deg2++;
        else if(Count==3)
            deg3++;
        else if(Count==(n-1))
            deg++;
    }


    if(deg2 == n)
        cout<<"The graph is a cycle\n";

    if(deg3 == (n-1) && deg == 1)
        cout<<"The graph is a Wheel\n";

    return 0;
}
