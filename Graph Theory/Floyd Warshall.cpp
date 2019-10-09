//Floyd Warshall
//O(n3)
#include <bits/stdc++.h>
using namespace std;

#define Max 100
int adj[Max][Max];
int parent[Max][Max];
int n, inf = 99;

void floyd_warshall()
{
     for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    parent[i][j] = parent[k][j];
                }

}

void input()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>adj[i][j];

            if(i==j || adj[i][j] == inf)
                parent[i][j] = -1;
            else
                parent[i][j] = i;
        }
    }
}

void print()
{
    cout<<"D: \n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\n\nParent: \n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout<<parent[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    input();
    floyd_warshall();
    print();
}

/*
*
7
0 3 6 99 99 99 99
3 0 2 1 99 99 99
6 2 0 1 4 2 99
99 1 1 0 2 99 4
99 99 4 2 0 2 1
99 99 2 99 2 0 1
99 99 99 4 1 1 0
*
*/

