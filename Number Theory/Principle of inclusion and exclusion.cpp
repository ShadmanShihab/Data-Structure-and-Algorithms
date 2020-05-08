//Principle of inclusion and exclusion
//bitmask

/**Problem : Find how many numbers from 1 to N(less than 1000) are divisible by
             any of the prime numbers less than 20 **/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    ll n;
    cin>>n;

    ll subsets = (1<<8) - 1;  //2^8 - 1
    //dbg(subsets)

    ll ans = 0;
    for(ll i=1; i<=subsets; i++)
    {
        ll denominator = (ll)1;
        ll setBits = __builtin_popcount(i);     //returns how many bits are one in Binary representation

        for(ll j=0; j<=7; j++)
        {
            if(i & (1<<j))      //product of the denominators
                denominator = denominator * primes[j];
        }

        if(setBits&1)     //if no of ones are odd, add to the result else subtract
            ans += (n / denominator);
        else
            ans -= (n / denominator);
    }
    cout<<ans<<endl;
}
