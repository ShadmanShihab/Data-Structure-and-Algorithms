#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 1000005
#define pii pair<int, int>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

long long limit = 4294967296;
int MOD = 1000000007;
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

int mark[Max];
vector<int> primes;

void sieve(int n)
{
    mark[1] = 1;

    for(int i=4; i<=n; i+=2)
        mark[i] = 1;

    int limit = sqrt(n);

    for(int i=3; i<=limit; i++)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<=n; j+=(2*i))
                mark[j] = 1;
        }
    }

    for(int i=2; i<=n; i++)
        if(mark[i] == 0)
            primes.push_back(i);
}


int eulerPhi(int n)
{
    int res = n;
    int limit = sqrt(n);

    for(int i=0; i<primes.size() && primes[i]<=limit; i++)
    {
        int p = primes[i];

        if(n % p == 0)
        {
            while(n % p ==0)
            {
                n /= p;
            }

            limit = sqrt(n);
            res /= p;
            res *= p - 1;
        }
    }

    if(n != 1)
    {
        res /= n;
        res *= n - 1;
    }
    return res;
}



int main()
{
    fastIO;

    sieve(1000010);

    int T, n; cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<eulerPhi(n)<<endl;

    }
}
