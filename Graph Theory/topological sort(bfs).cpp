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

vector<int> adj[101];
int indegree[101] = {0};
bool visited[101] = {false};
vector<int> res;
int n, e;

void topsort()
{
    queue<int> q;

    for(int i=1; i<=n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        res.push_back(u);

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>e;

    memset(indegree,0, sizeof(indegree));

    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        indegree[y]++;
    }

    topsort();

    cout<<"Tasks: \n";
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<endl;
    return 0;
}
