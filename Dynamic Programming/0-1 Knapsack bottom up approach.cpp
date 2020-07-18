//0/1 knapsack
//bottom up
//O(nW)  n = items, W = capacity
#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, int profit[], int weight[], int n)
{
    int i, w;
    int K[n+1][capacity+1];

    for (i = 0; i <= n; i++)
    {
       for (w = 0; w <= capacity; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight[i-1] <= capacity)
                 K[i][w] = max(profit[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
    }
    return K[n][capacity];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int  capacity = 50;
    int n = 3;

    cout<<knapsack(capacity, profit, weight, n)<<endl;

    return 0;
}
