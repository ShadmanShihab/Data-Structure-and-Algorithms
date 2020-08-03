#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> primes;
int mark[Max+2];

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

ll sod(ll n)
{
    ll res = 1;
    ll sqrtn = sqrt(n);

    for(int i=0; i<primes.size() && primes[i] <= sqrtn; i++)
    {
        if(n % primes[i] == 0)
        {
            ll tempsum = 1;
            ll p = 1;

            while(n % primes[i] == 0)
            {
                n /= primes[i];
                p *= primes[i];
                tempsum += p;
            }
            sqrtn = sqrt(n);
            res *= tempsum;
        }
    }

    if(n != 1)
        res *= (n + 1);

    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);


    sieve(1000005);

    ll n; cin>>n;
    ll sum_of_divisors = sod(n);

    cout<<sum_of_divisors<<endl;
    return 0;
}
