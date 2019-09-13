//sieve method
//O(nloglogn)
#include<bits/stdc++.h>
using namespace std;

int mark[1000002];
int prime[1000002], nPrime = 0;
//1 if not prime
//0 if prime
void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.0) + 2;

    mark[1] = 1;

    for(int i=4; i<=n; i+=2)
        mark[i] = 1;

    prime[nPrime++] = 2;

    for(int i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nPrime++] = i;

            if(i <= limit)
            {
                for(int j=i*i; j<=n; j+=(i*2))
                    mark[j] = 1;
            }
        }
    }
}


/*
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

*/
int main()
{
    sieve(10000);

    while(1)
    {
        int n;
        scanf("%d", &n);

        if(mark[n] == 0)
            cout<<n<<" is a prime\n";
        else
            cout<<n<<" is not prime\n";

        cout<<"\n\nThe first "<<n<<" primes are: \n";
        for(int i=0; i<n; i++)
            cout<<prime[i]<<endl;
    }
}
