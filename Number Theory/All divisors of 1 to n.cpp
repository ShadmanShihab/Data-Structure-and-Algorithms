//All divisors upto n
#include <bits/stdc++.h>
using namespace std;

vector <int> divisors[1000002];

void div(int n)
{
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j+=i)
            divisors[j].push_back(i);
}

int main()
{
    int n;
    cin>>n;
    div(n);

    for(int i=1; i<=n; i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<divisors[i].size(); j++)
        {
            cout<<divisors[i][j]<<" ";
        }
        cout<<endl;
    }
}
