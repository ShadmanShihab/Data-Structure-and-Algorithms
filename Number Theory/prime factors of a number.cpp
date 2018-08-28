//prime factors of a number
#include <bits/stdc++.h>
using namespace std;

vector<int>primes;

int primeFactors(int n)
{
    while(n % 2 == 0)
    {
         //cout<<2<<endl;
         primes.push_back(2);
         n = n / 2;
    }
    for(int i=3; i<=sqrt(n); i++)
    {
        while(n % i == 0)
        {
             //cout<<i<<endl;
             primes.push_back(i);
             n = n / i;
        }
    }
    if(n > 2)
    {
        //cout<<n<<endl;
        primes.push_back(n);
    }
}

int main()
{
    int n;
    cin>>n;

    primeFactors(n);

    for(int i=0; i<primes.size(); i++)
        cout<<primes[i]<<endl;

    return 0;
}
