//Binary Index Tree
//Fenwick tree
//Range minimum query(RMQ)
//query - update - O(logn)
//Constructing tree - O(nlogn)

#include <bits/stdc++.h>
using namespace std;

#define Max 10000

int ara[Max];
int tree[Max];

void print(int n)
{
    cout<<"Values: \n";
    for(int i=1; i<=n; i++)
        cout<<ara[i]<<" ";


    cout<<"\n\nTree: \n";
    for(int i=1; i<=n; i++)
        cout<<tree[i]<<" ";
    cout<<endl;
}

void update(int idx, int val, int n)
{
    cout<<"Update: ";

    while(idx <= n)
    {
        cout<<idx<<" ";
        tree[idx] += val;
        idx = idx + (idx & -idx);
    }
    cout<<endl;
}

//start = 1
int query(int idx)
{
    int sum = 0;

    while(idx > 0)
    {
        sum += tree[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n; cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];
        update(i, ara[i], n);
    }

    //print(n);
    cout<<endl<<endl;

    cout<<query(10)<<endl;

    update(5, 3, n);

    cout<<query(10)<<endl;
}



