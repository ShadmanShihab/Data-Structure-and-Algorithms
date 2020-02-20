//kruskal
//O(ElogE)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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

struct edge{
    int u, v, w;

    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

int n, m;
vector<edge> e;
int parent[101];

/*bool cmp(edge e1, edge e2)    // can be used for sorting
{
    return e1.w < e2.w;
}*/


void makeset(int n)
{
    for(int i=1; i<=n; i++)
        parent[i] = i;
}

int Find(int r)
{
    if(parent[r] == r)
        return r;
    return parent[r] = Find(parent[r]);
}

int kruskal(int n)
{
    sort(e.begin(), e.end());
    makeset(n);

    int sum = 0, Count = 0;
    for(int i=0; i<e.size(); i++)
    {
        int u = Find(e[i].u);
        int v = Find(e[i].v);

        if(u != v)
        {
            parent[u] = v;
            Count++;
            sum += e[i].w;
            if(Count == n-1)
                break;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        edge obj;
        obj.u = u;
        obj.v = v;
        obj.w = w;

        e.push_back(obj);
    }

    cout<<"Cost of MST = "<<kruskal(n)<<endl;

    return 0;
}
