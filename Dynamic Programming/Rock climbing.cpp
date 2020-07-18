//Rock climbing
//Maximum sum in the grid, suing 3 moves

#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI acos(-1)
#define all(a) a.begin(), a.end()
long long limit = 4294967296;
int MOD = 1000000007;
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... anst)
{
    print(first);
    print(anst ...) ;
}

int grid[100][100];
int dp[100][100];
int n, m;

int RockClimbing(int r, int c)
{
    if(r == n-1 || c == m-1)
        return grid[r][c];

    if(r < 0 || c < 0 || r >= n || c >= m)
        return 0;

    if(dp[r][c] != -1)
        return dp[r][c];

    int x = grid[r][c] + RockClimbing(r+1, c+1);
    int y = grid[r][c] + RockClimbing(r+1, c);
    int z = grid[r][c] + RockClimbing(r+1, c-1);

    return dp[r][c] = max(x, max(y, z));
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];

    cout<<RockClimbing(0, 0)<<endl;
}
