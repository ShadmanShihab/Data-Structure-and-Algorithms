//coin change algorithm
//dynamic programming (bottom up approach)
//O(n * make)
#include <bits/stdc++.h>
using namespace std;

#define Max 101

int dp[Max][Max];
int coin[Max];
int make, n;

int coin_change(int i, int amount)
{
    if(i >= n)
    {
        if(amount == 0)
            return 1;
        else
            return 0;
    }

    if(dp[i][amount] != -1)
        return dp[i][amount];

    int ret1 = 0, ret2 = 0;

    if(amount - coin[i] >= 0)
        ret1 = coin_change(i, amount - coin[i]);

    ret2 = coin_change(i+1, amount);

    return dp[i][amount] = ret1 + ret2;     //how many times a case can be made with given coins
}

int main()
{
    while(1)
    {
        memset(dp, -1, sizeof(dp));
        cin>>n>>make;

        if(n==0)
            break;

        for(int i=0; i<n; i++)
            cin>>coin[i];

        cout<<coin_change(0, make)<<endl;
    }
}
