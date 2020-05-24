//merge sort
//O(nlogn)
#include <bits/stdc++.h>
using namespace std;

void _merge(int ara[], int i1, int j1, int i2, int j2)
{
    int temp[100]; //array for merging
    int i = i1; //beginning of first array
    int j = i2; //beginning of second array
    int k = 0;

    while(i <= j1 && j <= j2)
    {
        if(ara[i] < ara[j])
            temp[k++] = ara[i++];
        else
            temp[k++] = ara[j++];
    }

    while(i <= j1)
        temp[k++] = ara[i++];

    while(j <= j2)
        temp[k++] = ara[j++];

    k = 0;
    for(i = i1; i<=j2; i++)
        ara[i] = temp[k++];
}

void mergesort(int ara[], int i, int j)
{
    int mid;

    if(i < j)
    {
        mid = (i + j) / 2;
        mergesort(ara, i, mid);
        mergesort(ara, mid+1, j);
        _merge(ara, i, mid, mid+1, j);
    }
}

int main()
{
    int n, ara[100];

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>ara[i];

    mergesort(ara, 0, n-1);

    cout<<"Sorted array: \n";
    for(int i=0; i<n; i++)
        cout<<ara[i]<<" ";
    cout<<endl;
}
