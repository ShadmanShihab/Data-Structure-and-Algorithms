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
#define all(a)           a.begin(),a.end()
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

/*direction array*/

/***4 moves***/
/*
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
*/
/***8 moves***/
/*
int dx[] = { 0,  0, -1, -1, -1, +1, +1, +1 } ;
int dy[] = {-1, +1, -1,  0, +1, -1,  0, +1 } ;
*/

/*direction array ends*/

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}

ll nCr(ll n, ll r)
{
    ll res = 1;

    for(ll i=0; i<r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    ll n, m, p;
    cin>>n>>m>>p;
    ll res = 0;

    for(ll i=4; i<=p-1; i++)
        res += nCr(n, i) * nCr(m, p - i);

    cout<<res<<endl;
}
