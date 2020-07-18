#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 100
int row[MAX], col[MAX];
bool visited[MAX][MAX];
int dp[MAX][MAX];

int mcm(int beg, int end)
{
    if(beg >= end)
        return 0;
    if(visited[beg][end])
        return dp[beg][end];

    int ans = 1 << 30;  //infinity

    for(int mid = beg; mid <= end; mid++)
    {
        int opr_left = mcm(beg, mid);
        int opr_right = mcm(mid+1, end);
        int opr_to_multiply = row[beg]*col[mid]*col[end];
        int total = opr_left + opr_right + opr_to_multiply;

        ans = min(ans, total);
    }
    visited[beg][end] = 1;
    dp[beg][end] = ans;
    return dp[beg][end];
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>row[i]>>col[i];

    cout<<mcm(0, n-1)<<endl;
}
