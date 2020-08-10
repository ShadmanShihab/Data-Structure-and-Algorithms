#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 1000010
#define pii pair<int, int>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//long long limit = 4294967296;

template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}

vector<int> primes;
int mark[Max+2];

/*void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.0) + 2;
    mark[1] = 1;

    for(int i=0; i<=limit; i+=2)
        mark[i] = 1;

    primes.push_back(2);

    for(int i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i <= limit)
            {
                for(j=i*i; j<=limit; j+=(i*2))
                    mark[j] = i;
            }
        }
    }

}*/

void sieve(ll n)
{
    mark[1]=1;
    for(int i=4; i<=n; i+=2)
    {
        mark[i]=1;
    }
    int limit=sqrt(n);
    for(int i=3; i<=limit; i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<=n; j+=(2*i))
                mark[j]=1;
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(mark[i]==0)
            primes.push_back(i);
    }

}

int NOD(ll n)
{
    int res = 1;
    int limit = sqrt(n);
    for(int i=0; primes[i]*primes[i] <=n && primes[i]<=limit; i++)
    {
        int val = primes[i];
        if(n % val == 0)
        {
            int p = 0;
            while(n % val == 0)
            {
                n /= val;
                p++;
            }
            p++;
            res *= p;
        }
    }
    if(n != 1)
        res *= 2;

    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    int T;
    cin>>T;
    sieve(1000005);

    for(int t=1; t<=T; t++)
    {
        ll n; cin>>n;
        int res = divisorCount(n);
        printf("Case %d: %d\n", t, res-1);
    }
    return 0;
}
