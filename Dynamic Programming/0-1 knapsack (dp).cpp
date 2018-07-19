//0-1 knapsack
//complexity O(n * capacity)

#include <bits/stdc++.h>
using namespace std;

#define Max 1000

int weight[Max];
int cost[Max];
int capacity, n;

int knapsack(int i, int w)
{
    if(i == n+1)
        return 0;

    int profit1, profit2;

    if(w + weight[i] <= capacity)
        profit1 = cost[i] + knapsack(i+1, w+weight[i]);
    else
        profit1 = 0;

    profit2 = knapsack(i+1, w);

    return max(profit1, profit2);
}

int main()
{
    scanf("%d %d", &n, &capacity);

    for(int i=1; i<=n; i++)
        scanf("%d %d", &weight[i], &cost[i]);

    cout<<knapsack(1, weight[1])<<endl;
}
