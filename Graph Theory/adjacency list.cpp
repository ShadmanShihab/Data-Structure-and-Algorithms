#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
vector<int>edges[MAX];
vector<int>cost[MAX];

int main()
{
    int N,E,i;

    scanf("%d%d",&N,&E);

    for(i=1;i<=E;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
        //cost[x].push_back(1);
        //cost[y].push_back(1);

    }
    cout<<"\n\n";

    cout<<"The adjacency list is: \n";
    int size, count = 0;

    for(int i=1; i<=E; i++){
        if(count < N){
            count++;
        cout<<count<<" -> ";
        }
        size = edges[i].size();
        for(int j=0; j<size; j++)
            cout<<edges[i][j]<<" ";
        cout<<endl;
    }
}
/*
input:
4
6
1 2
1 3
1 4
2 3
3 4
2 4
*/
