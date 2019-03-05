//coin change(bottom up)
//o(mn)
//uva 624
#include <bits/stdc++.h>
using namespace std;

#define Max 7495

int coin[5] = {50,25,10, 5, 1};
int make, n=5;
int dp[Max];

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i=0; i<n; i++)
        for(int j=coin[i], k=0; j<Max; j++, k++)
            dp[j] += dp[k];
        //dp[j] = dp[j] + dp[j - coin[i]];

    while(scanf("%d", &make) == 1)
        printf("%d\n", dp[make]);

    return 0;
}
