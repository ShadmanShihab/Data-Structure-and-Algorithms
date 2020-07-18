//Longest common subsequence
//O(n^2)
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[200][200];
int len1, len2;

int c = 0;

int lcs(int i, int j)
{
    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == len1 || j == len2)
        return 0;


    if(s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(i+1, j+1);
    else
    {
        int a = lcs(i+1, j);
        int b = lcs(i, j+1);
        return dp[i][j] = max(a, b);
    }
}


int main()
{
    memset(dp, -1, sizeof(dp));

    cin>>s1>>s2;

    len1 = s1.size();
    len2 = s2.size();

    cout<<lcs(0, 0)<<endl;
}
