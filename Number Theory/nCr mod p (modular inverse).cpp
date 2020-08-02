#include <bits/stdc++.h>
using namespace std;

ll fact[1000005];
ll p = 1000003;

void solve()
{
    fact[0] = 0;
    fact[1] = 1;

    for(int i=2; i<1000005; i++)
    {
        fact[i] = (fact[i - 1] * (i % p)) % p;
    }
}


ll power(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;

	while (y > 0)
    {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}

int main()
{
    fastIO;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    solve();
    int t; cin>>t;

    for(int k=1; k<=t; k++)
    {
        int n, r; cin>>n>>r;

        if(n == r || r == 0)
            cout<<"Case "<<k<<": "<<1<<endl;
        else
        {
            int x = (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
            cout<<"Case "<<k<<": "<<x<<endl;
        }
    }
    return 0;
}
