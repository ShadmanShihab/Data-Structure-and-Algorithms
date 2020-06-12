//Inversion Count using BIT
//Time Complexity - O(nlogn)
//Space Complexity - O(n)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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

int n;
int ara[Max];

void update(int tree[], int maxElement, int idx, int val)
{
    while(idx <= maxElement)
    {
        tree[idx] += val;

        idx += (idx & -idx);
    }
}

int query(int tree[], int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int getInvCount()
{
    int inv_cnt = 0, maxElement = 0;

    for(int i=0; i<n; i++)
        if(ara[i] > maxElement)
            maxElement = ara[i];

    //BIT tree of size upto maximum Element
    int tree[maxElement+1];
    memset(tree, 0, sizeof(tree));


    //traversing the array in the reverse order
    for(int i=n-1; i>=0; i--)
    {
        inv_cnt += query(tree, ara[i]-1);
        update(tree, maxElement, ara[i], 1);
    }

    return inv_cnt;
}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>ara[i];
    
    /*  
    //for linear space complexity
    vector<pii> v;
        v.push_back({0,0});
        for(ll i=1; i<=n; i++){
            cin>>ara[i];
 
            v.push_back(make_pair(ara[i], i));
        }
        sort(v.begin(), v.end());
 
        for(ll i=1; i<=n; i++){
            ara[i] = v[i].second;
        }
    cout<<getInvCount()<<endl;
    */
    
    cout<<"Number of Inversions: "<<getInvCount()<<endl;

    return 0;
}
