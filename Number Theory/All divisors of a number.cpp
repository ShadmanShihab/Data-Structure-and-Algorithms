#include <bits/stdc++.h>
using namespace std;

vector<int> divisors;

void findDivisors(int n)
{
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                divisors.push_back(i);
            else // Otherwise print both
            {
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n; cin>>n;
    findDivisors(n);
    sort(divisors.begin(), divisors.end());

    for(int i=0; i<divisors.size(); i++)
        cout<<divisors[i]<<" ";
    return 0;
}
