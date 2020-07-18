//Edit Distance (DP)
//Time Complexity: O(n * m)
//Space Complexity: O(n * m)
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int len1, len2;
int dp[100][100];
//int dp[s1.size()][s2.size()];

int edit_distance(int i, int j)
{
    if(i == len1) return len2 - j;
    if(j == len2) return len1 - i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j])
    {
        return dp[i][j] = edit_distance(i+1, j+1);
    }
    else
    {
        int a = 1 + edit_distance(i, j+1);  //insert
        int b = 1 + edit_distance(i+1, j);  //delete
        int c = 1 + edit_distance(i+1, j+1);    //update
        return dp[i][j] = min(a, min(b, c));
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin>>s1>>s2;

    len1 = s1.size();
    len2 = s2.size();

    cout<<edit_distance(0, 0)<<endl;
    return 0;
}
