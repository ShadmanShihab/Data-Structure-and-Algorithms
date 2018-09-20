/*
*
*
Segment tree - 1
complexity - O(nlogn)
*
*
*/
#include <bits/stdc++.h>
using namespace std;

#define Max 100001
int ara[Max];
int tree[Max];

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = ara[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)  //out of range
        return 0;

    if(b >= i && e <= j)
        return tree[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return p1 + p2;
}

void update(int node, int b, int e, int i, int newValue)
{
    if(i>e || i<b)
        return;

    if(b >= i && e <= i)
    {
        tree[node] = newValue;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    update(left, b, mid, i, newValue);
    update(right, mid+1, e, i, newValue);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>ara[i];
    init(1, 1, n);

    cout<<query(1, 1, n, 2, 6)<<endl;

    update(1, 1, n, 3, 10);

    cout<<query(1, 1, n, 2, 6);
}

/*
*
*
try this as input

7
4 -9 3 7 1 0 2
*
*
*/
