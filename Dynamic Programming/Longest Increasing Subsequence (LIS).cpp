//LIS
//O(n2)
#include <bits/stdc++.h>
using namespace std;

#define Max 1000
int n, value[Max];
int dp[Max], dir[Max];

int longest(int u)
{
    if(dp[u] != -1)
        return dp[u];

    int maxi = 0;

    for(int v = u+1; v<=n; v++)
    {
        if(value[v] > value[u])
        {
            int k = longest(v);
            if(k > maxi)
            {
                maxi = k;
                dir[u] = v;
            }
        }
    }
    dp[u] = 1 + maxi;
    return dp[u];
}

void printPath(int start)
{
    while(dir[start] != -1)
    {
        printf("Index %d  -> value %d\n", start, value[start]);
        start = dir[start];
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>value[i];

    memset(dp, -1, sizeof(dp));
    memset(dir, -1, sizeof(dir));

    int LIS = 0, start = 0;

    for(int i=1; i<=n; i++)
    {
        //cout<<"Longest path from "<<longest(i)<<"\n";
        int k = longest(i);
        if(k > LIS)
        {
            LIS = k;
            start = i;
        }
    }

    printf("LIS = %d  Start = %d\n", LIS, start);

    printPath(start);
    return 0;
}
