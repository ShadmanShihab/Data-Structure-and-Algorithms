//SPOJ: PRIME1 - Prime Generator
#include <bits/stdc++.h>
#include <iostream>
#define MAX 32000

using namespace std;

using ll = long long;

vector<int> primes;

void sieve()    
{
    bool isPrime[MAX];

    for (int i = 0; i < MAX; ++i) isPrime[i] = true;

    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i < MAX; i += 2) {
        if (isPrime[i]) primes.push_back(i);
    }
}

/*

void sieve()
{
    ll n = Max;
    mark[1] = 1;
 
    for(int i=4; i<=n; i+=2)
        mark[i] = 1;
 
    int limit = sqrt(n);
 
    for(int i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<=n; j+=(2*i))
                mark[j] = 1;
        }
    }
 
    primes.push_back(2);
    for(int i=3; i<=n; i+=2)
        if(mark[i] == 0)
            primes.push_back(i);
}

*/
void segmented_sieve(ll l, ll r)
{
    bool isPrime[r - l + 1];
    for(int i=0; i<r-l+1; i++) isPrime[i] = true;

    if(l == 1) isPrime[0] = false;

    for(int i=0; primes[i]*primes[i]<=r; i++)
    {
        int currentPrime = primes[i];
        ll base = (l / currentPrime) * currentPrime;
        if(base < l) base += currentPrime;      //if base is less than range

        for(ll j=base; j<=r; j+=currentPrime)
            isPrime[j-l] = false;

        if(base == currentPrime)
            isPrime[base-l] = true;
    }

    for(int i=0; i<r-l+1; i++)
        if(isPrime[i])
            cout<<i+l<<endl;
}


int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        segmented_sieve(l, r);
    }

    return 0;
}
