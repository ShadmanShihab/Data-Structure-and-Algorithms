#include <bits/stdc++.h>
using namespace std;



struct edge{
    int u, v, w;

    /*bool operator < (const edge& p) const
    {
        return w < p.w;
    }*/
};

bool cmp(edge e1, edge e2)
{
    return e1.w < e2.w;
}

vector<edge> e;
int parent[101];
vector<edge> res_edges;
vector<int> done;

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
            res_edges.push_back(e[i]);
            done.push_back(i);
            if(Count == n-1)
                break;
        }
    }
    return sum;
}


///2nd best MST - kruskal
int second_best(int n)
{
    int s = INT_MAX;
    sort(e.begin(), e.end(), cmp);

    for(int j=0; j<done.size(); j++)
    {
        int c = 0, sum = 0;

        makeset(n);

        for(int i=0; i<e.size(); i++)
        {
            if(i == done[j])
                continue;
            int u = Find(e[i].u);
            int v = Find(e[i].v);

            if(u != v)
            {
                sum += e[i].w;
                c++;
                parent[u] = v;
                if(c == n-1)
                    break;
            }
        }

        if(s > sum) s = sum;
    }
    return s;
}


int main()
{
    freopen("in.txt", "r", stdin);

    int n, m; cin>>n>>m;

    while(m--)
    {
        int x, y, c; cin>>x>>y>>c;

        edge obj;
        obj.u = x;
        obj.v = y;
        obj.w = c;

        e.push_back(obj);
    }

    sort(e.begin(), e.end(), cmp);

    makeset(n);

    cout<<"Cost of mst: "<<kruskal(n)<<endl;
    cout<<"visited edges: \n";

    for(int i=0; i<res_edges.size(); i++)
        cout<<res_edges[i].u<<" "<<res_edges[i].v<<" "<<res_edges[i].w<<"\n";


    cout<<endl<<endl<<endl;

    cout<<"second best mst = "<<second_best(n)<<endl;
    return 0;
}
